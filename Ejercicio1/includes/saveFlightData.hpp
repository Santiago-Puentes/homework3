#pragma once
#include "medicionBase.hpp"
#include "posicion.hpp"
#include "presion.hpp"

class SaveFlightData {
    std::vector<std::shared_ptr<MedicionBase>> mediciones;
    public:
    void agregarMedicion(std::shared_ptr<MedicionBase> m);
    void guardar(const std::string& filename);
    void cargar(const std::string& filename);
    void imprimirTodo() const;
};