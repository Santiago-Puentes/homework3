#include "../includes/posicion.hpp"

Posicion::Posicion() : x(0), y(0), z(0) {}

Posicion::Posicion(float x_, float y_, float z_, double tiempo) : MedicionBase(tiempo), x(x_), y(y_), z(z_) {}

Posicion::Posicion(const Posicion& other) : MedicionBase(other), x(other.x), y(other.y), z(other.z) {}

void Posicion::imprimir() const {
    std::cout << "Posicion: x=" << x << " y=" << y << " z=" << z;
    if (tiempoMedicion)
        std::cout << " tiempo=" << *tiempoMedicion;
    std::cout << std::endl;
}

void Posicion::serializar(std::ofstream& out) const {
    out.write(reinterpret_cast<const char*>(&x), sizeof(x));
    out.write(reinterpret_cast<const char*>(&y), sizeof(y));
    out.write(reinterpret_cast<const char*>(&z), sizeof(z));
    serializarTiempo(out);
}

void Posicion::deserializar(std::ifstream& in) {
    in.read(reinterpret_cast<char*>(&x), sizeof(x));
    in.read(reinterpret_cast<char*>(&y), sizeof(y));
    in.read(reinterpret_cast<char*>(&z), sizeof(z));
    deserializarTiempo(in);
}

std::shared_ptr<MedicionBase> Posicion::clonar() const {
    return std::make_shared<Posicion>(*this);
}