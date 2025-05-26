#pragma once
#include "circulo.hpp"
#include "elipse.hpp"
#include "rectangulo.hpp"
#define PI 3.14

template<typename T>
class ProcesadorFigura {
    static double calcularArea(const T& figura) {
        static_assert(sizeof(T) == -1, "Tipo no soportado por ProcesadorFigura");
        return 0.0f;
    }
};

template<> class ProcesadorFigura<circulo> {
    public:
        static double area(circulo& c) {
            return PI * c.getRadio() * c.getRadio();
        }
};

template<> class ProcesadorFigura<elipse> {
    public:
        static double area(elipse& e) {
            return PI * e.getEjeMayor() * e.getEjeMenor();
        }
};

template<> class ProcesadorFigura<rectangulo> {
    public:
        static double area(rectangulo& r) {
            return r.getAncho() * r.getLargo();
        }
};