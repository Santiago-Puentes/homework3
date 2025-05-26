#include "../includes/circulo.hpp"
#include "../includes/elipse.hpp"
#include "../includes/punto.hpp"
#include "../includes/rectangulo.hpp"
#include "../includes/ProcesadorFigura.hpp"
int main() {
    // Crear figuras
    circulo circ(punto(0, 0), 10);
    rectangulo rect(punto(0, 0), 10, 10);
    elipse elip(punto(0, 0), 10, 11);

    // Crear ProcesadorFigura
    ProcesadorFigura<circulo> procesadorCirc;
    ProcesadorFigura<elipse> procesadorElip;
    ProcesadorFigura<rectangulo> procesadorRect;

    // Probar área
    std::cout << "Area circulo: " << procesadorCirc.area(circ) << std::endl;
    std::cout << "Area rectangulo: " << procesadorRect.area(rect) << std::endl;
    std::cout << "Area elipse: " << procesadorElip.area(elip) << std::endl;

    return 0;
}