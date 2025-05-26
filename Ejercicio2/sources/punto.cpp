#include "../includes/punto.hpp"

punto::punto(double x_, double y_) : x(x_), y(y_) {}

void punto::setX(double x1) {x = x1;}
void punto::setY(double y1) {y = y1;}
double punto::getX() {return x;}
double punto::getY() {return y;}
void punto::mostrarPosicion() {std::cout << "x: " << x << "y: " << y << std::endl;}