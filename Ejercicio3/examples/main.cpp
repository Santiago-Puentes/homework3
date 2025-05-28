#include "../includes/JSONcreador.hpp"
#include "../includes/saveData.hpp"

int main() {
    saveData<double> numeros;
    numeros.add(1.3);
    numeros.add(2.1);
    numeros.add(3.2);

    saveData<std::string> palabras;
    palabras.add("Hola");
    palabras.add("Mundo");

    saveData<std::vector<int>> listas;
    listas.add({1, 2});
    listas.add({3, 4});

    JSONCreador json;
    json.agregarProcesado("vec_doubles", numeros.procesar());
    json.agregarProcesado("palabras", palabras.procesar());
    json.agregarProcesado("listas", listas.procesar());

    json.generarJSON();
    json.guardarJSON("salida.json");
}
