#include "../includes/presion.hpp"
#include <iostream>
using namespace std;

Presion::Presion() : presionEstatica(0), presionDinamica(0) {}

Presion::Presion(float pe, float pd, double tiempo)
    : MedicionBase(tiempo), presionEstatica(pe), presionDinamica(pd) {}

Presion::Presion(const Presion& other)
    : MedicionBase(other), presionEstatica(other.presionEstatica), presionDinamica(other.presionDinamica) {}

void Presion::imprimir() const {
    cout << "Presion: estatica=" << presionEstatica << " dinamica=" << presionDinamica;
    if (tiempoMedicion)
        cout << " tiempo=" << *tiempoMedicion;
    cout << endl;
}

void Presion::serializar(ofstream& out) const {
    out.write(reinterpret_cast<const char*>(&presionEstatica), sizeof(presionEstatica));
    out.write(reinterpret_cast<const char*>(&presionDinamica), sizeof(presionDinamica));
    serializarTiempo(out);
}

void Presion::deserializar(ifstream& in) {
    in.read(reinterpret_cast<char*>(&presionEstatica), sizeof(presionEstatica));
    in.read(reinterpret_cast<char*>(&presionDinamica), sizeof(presionDinamica));
    deserializarTiempo(in);
}

shared_ptr<MedicionBase> Presion::clonar() const {
    return make_shared<Presion>(*this);
}