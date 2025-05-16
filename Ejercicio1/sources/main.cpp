#include "../includes/saveFlightData.hpp"

int main() {
    SaveFlightData vuelo;
    vuelo.agregarMedicion(make_shared<Posicion>(-34.6f, -58.4f, 950.0f, 5.3));
    vuelo.agregarMedicion(make_shared<Presion>(101.3f, 5.8f, 6.1f));

    vuelo.guardar("vuelo.dat");

    SaveFlightData vueloLeido;
    vueloLeido.cargar("vuelo.dat");

    vueloLeido.imprimirTodo();
    return 0;
}