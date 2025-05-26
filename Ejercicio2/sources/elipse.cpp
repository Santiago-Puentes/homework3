#include "../includes/elipse.hpp"

// Constructor
elipse::elipse(const punto& c, double m, double M) : centro(c), eje_menor(m), eje_mayor(M) {
    if (m >= M) {
        throw std::invalid_argument("El semieje menor tiene que ser más chico que el semieje mayor.");
    } else if (m < 0 || M < 0) {
        throw std::invalid_argument("El semieje menor y el semieje mayor tienen que ser ambos mayores a 0.");
    }
}

// Setters
void elipse::setcentro(punto c) {
    centro = c;
}
void elipse::setEjeMenor(double m) {
    if (m >= eje_mayor) {
        throw std::invalid_argument("El semieje menor tiene que ser más chico que el semieje mayor.");
    } else if (m < 0) {
        throw std::invalid_argument("El semieje menor tiene que ser mayor a 0.");
    }
    eje_menor = m;
}
void elipse::setEjeMayor(double M) {
    if (eje_menor >= M) {
        throw std::invalid_argument("El semieje menor tiene que ser más chico que el semieje mayor.");
    } else if (M < 0) {
        throw std::invalid_argument("El semieje mayor tiene que ser mayor a 0.");
    }
    eje_mayor = M;
}

// Getters
punto elipse::getCentro() {
    return centro;
}
double elipse::getEjeMenor() {
    return eje_menor;
}
double elipse::getEjeMayor() {
    return eje_mayor;
}