#pragma once
#include "IMediciones.hpp"

class MedicionBase : public IMediciones {
protected:
    std::unique_ptr<double> tiempoMedicion;
public:
    MedicionBase();
    MedicionBase(double tiempo);
    MedicionBase(const MedicionBase& other);
    virtual ~MedicionBase() = default;

    virtual void imprimir() const = 0;
    virtual void serializar(std::ofstream&) const = 0;
    virtual void deserializar(std::ifstream&) = 0;
    virtual std::shared_ptr<MedicionBase> clonar() const = 0;

    void serializarTiempo(std::ofstream& out) const;
    void deserializarTiempo(std::ifstream& in);
};