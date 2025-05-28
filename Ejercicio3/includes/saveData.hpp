#include <vector>
#include <string>
#include <sstream>
#include <type_traits>
#include <iostream>
#include <fstream>

template<typename>
struct always_false : std::false_type {};

template<typename T>
class saveData {
private:
    std::vector<T> datos;

public:
    saveData() : datos() {}

    void add(const T& val) {
        datos.push_back(val);
    }

    std::string procesar() const {
        std::ostringstream oss;
        if constexpr (std::is_same_v<T, double>) {
            oss << "[";
            for (size_t i = 0; i < datos.size(); ++i) {
                oss << datos[i];
                if (i != datos.size() - 1) oss << ", ";
            }
            oss << "]";
        } else if constexpr (std::is_same_v<T, std::string>) {
            oss << "[";
            for (size_t i = 0; i < datos.size(); ++i) {
                oss << "\"" << datos[i] << "\"";
                if (i != datos.size() - 1) oss << ", ";
            }
            oss << "]";
        } else if constexpr (std::is_same_v<T, std::vector<int>>) {
            oss << "[";
            for (size_t i = 0; i < datos.size(); ++i) {
                oss << "[";
                for (size_t j = 0; j < datos[i].size(); ++j) {
                    oss << datos[i][j];
                    if (j != datos[i].size() - 1) oss << ", ";
                }
                oss << "]";
                if (i != datos.size() - 1) oss << ", ";
            }
            oss << "]";
        } else {
            static_assert(always_false<T>::value, "Tipo no soportado");
        }
        return oss.str();
    }
};