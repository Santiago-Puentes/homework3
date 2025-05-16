#include "../includes/saveFlightData.hpp"

void SaveFlightData::agregarMedicion(std::shared_ptr<MedicionBase> m) {
    mediciones.push_back(m);
}

void SaveFlightData::guardar(const std::string& filename) {
    std::ofstream out(filename, std::ios::binary);
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

void SaveFlightData::cargar(const std::string& filename) {
    std::ifstream in(filename, std::ios::binary);
    if (!in) return;
    size_t cantidad = 0;
    in.read(reinterpret_cast<char*>(&cantidad), sizeof(cantidad));
    for (size_t i = 0; i < cantidad; ++i) {
        int tipo = -1;
        in.read(reinterpret_cast<char*>(&tipo), sizeof(tipo));
        std::shared_ptr<MedicionBase> m;
        if (tipo == 0) m = std::make_shared<Posicion>();
        else if (tipo == 1) m = std::make_shared<Presion>();
        else continue;
        m->deserializar(in);
        mediciones.push_back(m);
    }
}

void SaveFlightData::imprimirTodo() const {
    for (const auto& m : mediciones)
        m->imprimir();
}