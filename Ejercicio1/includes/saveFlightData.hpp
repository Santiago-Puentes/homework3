#pragma once
#include "medicionBase.hpp"
#include "posicion.hpp"
#include "presion.hpp"

class SaveFlightData {
    vector<shared_ptr<MedicionBase>> mediciones;
    public:
    void agregarMedicion(shared_ptr<MedicionBase> m);
    void guardar(const string& filename);
    void cargar(const string& filename);
    void imprimirTodo() const;
};