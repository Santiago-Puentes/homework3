#include "../includes/circulo.hpp"

circulo::circulo(punto a = punto(0,0), double r = 0) : centro(a), radio(r) {
    if (r < 0) {
        throw std::invalid_argument("No se permite el ingreso de radio negativo");
    }
}


punto circulo::getCentro() {
    return centro;
}
double circulo::getRadio() {
    return radio;
}


void circulo::setCentro(punto p) {
    centro = p;
}
void circulo::setRadio(double r) {
    if (r < 0) {
        throw std::invalid_argument("No se permite el ingreso de radio negativo");
    }
    radio = r;
}