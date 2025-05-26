#pragma once
#include "punto.hpp"

class elipse {
    private:
        punto centro;
        double eje_menor;
        double eje_mayor;
    public:
        elipse(const punto& centro, double m, double M);

        void setcentro(punto c);
        void setEjeMenor(double m);
        void setEjeMayor(double M);
        
        punto getCentro();
        double getEjeMenor();
        double getEjeMayor();
};