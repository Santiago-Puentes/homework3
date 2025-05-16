#pragma once
#include "IMediciones.hpp"

class MedicionBase : public IMediciones {
protected:
    unique_ptr<double> tiempoMedicion;
public:
    MedicionBase();
    MedicionBase(double tiempo);
    MedicionBase(const MedicionBase& other);
    virtual ~MedicionBase() = default;

    virtual void imprimir() const = 0;
    virtual void serializar(ofstream&) const = 0;
    virtual void deserializar(ifstream&) = 0;
    virtual shared_ptr<MedicionBase> clonar() const = 0;

    void serializarTiempo(ofstream& out) const;
    void deserializarTiempo(ifstream& in);
};