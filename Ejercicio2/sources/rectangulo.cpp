#include "../includes/rectangulo.hpp"

rectangulo::rectangulo(punto v, double a, double l) : vertice(v), ancho(a), largo(l) {
    if (a < 0 || l < 0) {
        throw std::invalid_argument("No se puede ingresar ancho y largo menores a 0.");
    }
}

void rectangulo::setVertice(punto v) {
    vertice = v;
}
void rectangulo::setAncho(double a) {
    if (a < 0) {
        throw std::invalid_argument("No se puede ingresar ancho menor a 0.");
    }
    ancho = a;
}
void rectangulo::setLargo(double l) {
    if (l < 0) {
        throw std::invalid_argument("No se puede ingresar ancho y largo menores a 0.");
    }
    largo = l;
}

punto rectangulo::getVertice() {
    return vertice;
}
double rectangulo::getAncho() {
    return ancho;
}
double rectangulo::getLargo() {
    return largo;
}