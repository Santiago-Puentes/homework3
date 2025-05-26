#pragma once
#include "punto.hpp"

class rectangulo {
    private:
        punto vertice;
        double ancho;
        double largo;
    public:
        rectangulo(punto v, double a, double l);

        void setVertice(punto v);
        void setAncho(double a);
        void setLargo(double l);

        punto getVertice();
        double getAncho();
        double getLargo();
};