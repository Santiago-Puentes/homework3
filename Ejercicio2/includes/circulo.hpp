#pragma once
#include "punto.hpp"

class circulo{
    private:
        punto centro;
        double radio;
    public:
        circulo(punto c, double radio);

        punto getCentro();
        double getRadio();

        void setCentro(punto c);
        void setRadio(double r);
};