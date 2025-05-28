#include <vector>
#include <string>
#include <sstream>
#include <type_traits>
#include <iostream>
#include <fstream>

class JSONCreador {
private:
    std::vector<std::pair<std::string, std::string>> elementos;

public:
    JSONCreador() : elementos() {}

    // Guarda la clave (por ejemplo: "vec_doubles") con el string que devuelve saveData<T>::procesar()
    void agregarProcesado(const std::string& clave, const std::string& valor_json);

    void generarJSON() const;

    void guardarJSON(const std::string& nombre_archivo) const;
};