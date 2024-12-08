#include <iostream>
#include <sstream>
#include "Tablero.h"

int main() {
    Tablero& tablero = tablero.getInstance();
    char jugadorActual = tablero.determinarTurno();
    int fila, columna;

    std::cout << "Bienvenido al juego de gato." << std::endl;
    while (true) {
        tablero.mostrarTablero();

        do {
            std::string input;
            std::cout << "Turno del jugador " << jugadorActual << ". Ingresa fila y columna según la forma 'fila, columna': ";
            std::cin >> input;
            std::istringstream iss(input);
            char separador;
            if (!(iss >> fila >> separador >> columna) || separador != ',' || fila < 0 || fila > 2 || columna < 0 || columna > 2) {
                std::cout << "Entrada inválida. Inténtalo de nuevo.\n";
                continue; // Repetir la solicitud si la entrada no es válida
            }
        } while(!tablero.realizarMovimiento(fila, columna, jugadorActual));
        
        char ganador = tablero.ganadorFinal();
        if (ganador != '-') {
            tablero.mostrarTablero();
            std::cout << "El jugador " << ganador << " ha ganado!" << std::endl;
            break;
        } else if (tablero.isEmpate()) {
            tablero.mostrarTablero();
            std::cout << "El juego termina en empate" << std::endl;
            break;
        }

        tablero.setTurnos(tablero.getTurnos()+1);
        jugadorActual = tablero.determinarTurno();
    }

    return 0;
}