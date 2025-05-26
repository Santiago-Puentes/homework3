#pragma once
#include <iostream>

class punto {
    private:
        double x;
        double y;
    public:
        punto(double x, double y);
        void setX(double x1);
        void setY(double y1);
        double getX();
        double getY();
        void mostrarPosicion();
};
