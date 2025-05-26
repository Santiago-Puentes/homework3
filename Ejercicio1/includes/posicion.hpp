#pragma once
#include "medicionBase.hpp"

class Posicion : public MedicionBase {
    float x, y, z;
public:
    Posicion();
    Posicion(float x_, float y_, float z_, double tiempo);
    Posicion(const Posicion& other);

    void imprimir() const override;
    void serializar(std::ofstream& out) const override;
    void deserializar(std::ifstream& in) override;
    std::shared_ptr<MedicionBase> clonar() const override;
};