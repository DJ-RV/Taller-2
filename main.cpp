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
        if (tablero.determinarTurno() == 'X') {
            do {
            std::string input;
            std::cout << "Turno del jugador " << jugadorActual << ". Ingresa fila y columna según la forma 'fila, columna': ";
            std::cin >> input;
            std::istringstream iss(input);
            char separador;
                if (!(iss >> fila >> separador >> columna) || separador != ',' || fila < 0 || fila > 2 || columna < 0 || columna > 2) {
                    std::cout << "Entrada inválida. Inténtalo de nuevo" << std::endl;
                    continue;
                }
            } while(!tablero.realizarMovimiento(fila, columna, jugadorActual));
        } else {
            std::cout << "Turno de la IA (Jugador O). Calculando movimiento..." << std::endl;
            std::vector<int> mejorMovimiento = tablero.mejorMovimiento();
            fila = mejorMovimiento[0];
            columna = mejorMovimiento[1];
            tablero.realizarMovimiento(fila, columna, jugadorActual);
            std::cout << "La IA te papea con el movimiento: (" << fila << ", " << columna << ")." << std::endl;
        }
        
        int ganador = tablero.revisarTablero();

        if (ganador == 10) {
            tablero.mostrarTablero();
            std::cout << "El jugador X ha ganado!" << std::endl;
            break;
        } else if (ganador == -10){
            tablero.mostrarTablero();
            std::cout << "El jugador O (IA) ha ganado!" << std::endl;
            break;
        } else if (!tablero.movimientosDisponibles()) {
            tablero.mostrarTablero();
            std::cout << "El juego termina en empate" << std::endl;
            break;
        }

        tablero.setTurnos(tablero.getTurnos()+1);
        jugadorActual = tablero.determinarTurno();
    }

    return 0;
}