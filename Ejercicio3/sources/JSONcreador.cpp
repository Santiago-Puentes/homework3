#include "../includes/JSONcreador.hpp"

void JSONCreador::agregarProcesado(const std::string& clave, const std::string& valor_json) {
    elementos.push_back({clave, valor_json});
}

void JSONCreador::generarJSON() const {
    std::cout << "{\n";
    for (size_t i = 0; i < elementos.size(); ++i) {
        std::cout << "  \"" << elementos[i].first << "\": " << elementos[i].second;
        if (i != elementos.size() - 1)
            std::cout << ",";
        std::cout << "\n";
    }
    std::cout << "}\n";
}

void JSONCreador::guardarJSON(const std::string& nombre_archivo) const {
    std::ofstream archivo(nombre_archivo);
    if (!archivo) return; // Manejo simple de error
    archivo << "{\n";
    for (size_t i = 0; i < elementos.size(); ++i) {
        archivo << "  \"" << elementos[i].first << "\": " << elementos[i].second;
        if (i != elementos.size() - 1)
            archivo << ",";
        archivo << "\n";
    }
    archivo << "}\n";
}