#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int main() {
    // Obtener la cadena de consulta
    const char* query_string = getenv("QUERY_STRING");   
    // Inicializar variables
    int num1 = 0, num2 = 0;

    if (query_string != nullptr) {
        // Parsear los parámetros
        char* param = strdup(query_string);  // Hacer una copia de la cadena de consulta
        char* token = strtok(param, "&");     // Separar los parámetros
        while (token != nullptr) {
            if (sscanf(token, "num1=%d", &num1) == 1) { /* Se ha encontrado num1 */ } 
            else if (sscanf(token, "num2=%d", &num2) == 1) { /* Se ha encontrado num2 */ }
            token = strtok(nullptr, "&"); // Continuar con el siguiente parámetro
        }
        free(param);  // Liberar la memoria
    }

    // Realizar la suma
    int resultado = num1 + num2;


    // Generar la respuesta HTTP
    cout << "Content-Type: text/plain\n\n";
    cout << resultado;

    return 0;
}
