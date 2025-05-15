#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

// --- Interfaz IMediciones ---
class IMediciones {
public:
    virtual void serializar(ofstream& out) const = 0;
    virtual void deserializar(ifstream& in) = 0;
    virtual ~IMediciones() = default;
};

// --- Clase abstracta base ---
class MedicionBase : public IMediciones {
protected:
    unique_ptr<double> tiempoMedicion;
public:
    MedicionBase() : tiempoMedicion(make_unique<double>(0.0)) {}
    MedicionBase(double tiempo) : tiempoMedicion(make_unique<double>(tiempo)) {}
    MedicionBase(const MedicionBase& other) {
        if (other.tiempoMedicion)
            tiempoMedicion = make_unique<double>(*other.tiempoMedicion);
        else
            tiempoMedicion = nullptr;
    }
    virtual ~MedicionBase() = default;

    virtual void imprimir() const = 0;
    virtual void serializar(ofstream&) const = 0;
    virtual void deserializar(ifstream&) = 0;
    virtual shared_ptr<MedicionBase> clonar() const = 0;

    void serializarTiempo(ofstream& out) const {
        bool tieneTiempo = (tiempoMedicion != nullptr);
        out.write(reinterpret_cast<const char*>(&tieneTiempo), sizeof(tieneTiempo));
        if (tieneTiempo)
            out.write(reinterpret_cast<const char*>(tiempoMedicion.get()), sizeof(double));
    }
    void deserializarTiempo(ifstream& in) {
        bool tieneTiempo = false;
        in.read(reinterpret_cast<char*>(&tieneTiempo), sizeof(tieneTiempo));
        if (tieneTiempo) {
            double t;
            in.read(reinterpret_cast<char*>(&t), sizeof(double));
            tiempoMedicion = make_unique<double>(t);
        } else {
            tiempoMedicion = nullptr;
        }
    }
};

// --- Clase Posicion ---
class Posicion : public MedicionBase {
    float x, y, z;
public:
    Posicion() : x(0), y(0), z(0) {}
    Posicion(float x_, float y_, float z_, double tiempo)
        : MedicionBase(tiempo), x(x_), y(y_), z(z_) {}
    Posicion(const Posicion& other)
        : MedicionBase(other), x(other.x), y(other.y), z(other.z) {}

    void imprimir() const override {
        cout << "Posicion: x=" << x << " y=" << y << " z=" << z;
        if (tiempoMedicion)
            cout << " tiempo=" << *tiempoMedicion;
        cout << endl;
    }
    void serializar(ofstream& out) const override {
        out.write(reinterpret_cast<const char*>(&x), sizeof(x));
        out.write(reinterpret_cast<const char*>(&y), sizeof(y));
        out.write(reinterpret_cast<const char*>(&z), sizeof(z));
        serializarTiempo(out);
    }
    void deserializar(ifstream& in) override {
        in.read(reinterpret_cast<char*>(&x), sizeof(x));
        in.read(reinterpret_cast<char*>(&y), sizeof(y));
        in.read(reinterpret_cast<char*>(&z), sizeof(z));
        deserializarTiempo(in);
    }
    shared_ptr<MedicionBase> clonar() const override {
        return make_shared<Posicion>(*this);
    }
};

// --- Clase Presion ---
class Presion : public MedicionBase {
    float presionEstatica, presionDinamica;
public:
    Presion() : presionEstatica(0), presionDinamica(0) {}
    Presion(float pe, float pd, double tiempo)
        : MedicionBase(tiempo), presionEstatica(pe), presionDinamica(pd) {}
    Presion(const Presion& other)
        : MedicionBase(other), presionEstatica(other.presionEstatica), presionDinamica(other.presionDinamica) {}

    void imprimir() const override {
        cout << "Presion: estatica=" << presionEstatica << " dinamica=" << presionDinamica;
        if (tiempoMedicion)
            cout << " tiempo=" << *tiempoMedicion;
        cout << endl;
    }
    void serializar(ofstream& out) const override {
        out.write(reinterpret_cast<const char*>(&presionEstatica), sizeof(presionEstatica));
        out.write(reinterpret_cast<const char*>(&presionDinamica), sizeof(presionDinamica));
        serializarTiempo(out);
    }
    void deserializar(ifstream& in) override {
        in.read(reinterpret_cast<char*>(&presionEstatica), sizeof(presionEstatica));
        in.read(reinterpret_cast<char*>(&presionDinamica), sizeof(presionDinamica));
        deserializarTiempo(in);
    }
    shared_ptr<MedicionBase> clonar() const override {
        return make_shared<Presion>(*this);
    }
};

// --- Clase SaveFlightData ---
class SaveFlightData {
    vector<shared_ptr<MedicionBase>> mediciones;
public:
    void agregarMedicion(shared_ptr<MedicionBase> m) {
        mediciones.push_back(m);
    }
    void guardar(const string& filename) {
        ofstream out(filename, ios::binary);
        if (!out) return;
        size_t cantidad = mediciones.size();
        out.write(reinterpret_cast<const char*>(&cantidad), sizeof(cantidad));
        for (const auto& m : mediciones) {
            if (dynamic_cast<Posicion*>(m.get())) {
                int tipo = 0;
                out.write(reinterpret_cast<const char*>(&tipo), sizeof(tipo));
            } else if (dynamic_cast<Presion*>(m.get())) {
                int tipo = 1;
                out.write(reinterpret_cast<const char*>(&tipo), sizeof(tipo));
            }
            m->serializar(out);
        }
    }
    void cargar(const string& filename) {
        ifstream in(filename, ios::binary);
        if (!in) return;
        size_t cantidad = 0;
        in.read(reinterpret_cast<char*>(&cantidad), sizeof(cantidad));
        for (size_t i = 0; i < cantidad; ++i) {
            int tipo = -1;
            in.read(reinterpret_cast<char*>(&tipo), sizeof(tipo));
            shared_ptr<MedicionBase> m;
            if (tipo == 0) m = make_shared<Posicion>();
            else if (tipo == 1) m = make_shared<Presion>();
            else continue;
            m->deserializar(in);
            mediciones.push_back(m);
        }
    }
    void imprimirTodo() const {
        for (const auto& m : mediciones)
            m->imprimir();
    }
};

// --- main ---
int main() {
    SaveFlightData vuelo;
    vuelo.agregarMedicion(make_shared<Posicion>(-34.6f, -58.4f, 950.0f, 5.3));
    vuelo.agregarMedicion(make_shared<Presion>(101.3f, 5.8f, 6.1f));

    vuelo.guardar("vuelo.dat");

    SaveFlightData vueloLeido;
    vueloLeido.cargar("vuelo.dat");

    vueloLeido.imprimirTodo();
    return 0;
}