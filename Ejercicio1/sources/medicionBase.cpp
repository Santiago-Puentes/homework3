#include "../includes/medicionBase.hpp"

MedicionBase::MedicionBase() : tiempoMedicion(std::make_unique<double>(0.0)) {}

MedicionBase::MedicionBase(double tiempo) : tiempoMedicion(std::make_unique<double>(tiempo)) {}

MedicionBase::MedicionBase(const MedicionBase& other) {
    if (other.tiempoMedicion)
        tiempoMedicion = std::make_unique<double>(*other.tiempoMedicion);
    else
        tiempoMedicion = nullptr;
}

void MedicionBase::serializarTiempo(std::ofstream& out) const {
    bool tieneTiempo = (tiempoMedicion != nullptr);
    out.write(reinterpret_cast<const char*>(&tieneTiempo), sizeof(tieneTiempo));
    if (tieneTiempo)
        out.write(reinterpret_cast<const char*>(tiempoMedicion.get()), sizeof(double));
}

void MedicionBase::deserializarTiempo(std::ifstream& in) {
        bool tieneTiempo = false;
        in.read(reinterpret_cast<char*>(&tieneTiempo), sizeof(tieneTiempo));
        if (tieneTiempo) {
            double t;
            in.read(reinterpret_cast<char*>(&t), sizeof(double));
            tiempoMedicion = std::make_unique<double>(t);
        } else {
            tiempoMedicion = nullptr;
        }
    }