#pragma once
#include "medicionBase.hpp"

class Presion : public MedicionBase {
    float presionEstatica, presionDinamica;
public:
    Presion();
    Presion(float pe, float pd, double tiempo);
    Presion(const Presion& other);

    void imprimir() const override;
    void serializar(ofstream& out) const override;
    void deserializar(ifstream& in) override;
    shared_ptr<MedicionBase> clonar() const override;
};