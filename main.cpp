#include <iostream>
#include <sstream>
#include "Tablero.h"

int main() {
    Tablero& tablero = tablero.getInstance();
    char jugadorActual = tablero.determinarTurno();
    int fila, columna;

    std::cout << "Juego del gato" << std::endl;
    std::cout << "Conecta 3 símbolos iguales en línea recta o diagonal para ganar" << std::endl;
    std::cout << "---------------------------------------------------------------" << std::endl;
    while (true) {
        tablero.mostrarTablero();
        if (tablero.determinarTurno() == 'X') {
            do {
            int input;
            std::cout << "Turno del jugador " << jugadorActual << ". Ingresa la celda que quieres ocupar: ";
            std::cin >> input;
            std::vector<int> movimientos = tablero.convertirMovimiento(input);
                if (movimientos[0] != -1 && movimientos[1] != -1) {
                    int fila = movimientos[0];
                    int columna = movimientos[1];
                    if (tablero.realizarMovimiento(fila, columna, jugadorActual)) {
                        break;
                    }
                } else {
                    std::cout << "Movimiento inválido. Inténtalo nuevamente." << std::endl;
                }
            } while(true);
        } else {
            std::cout << "Turno de la IA (Jugador O). Computando humillacion..." << std::endl;
            std::vector<int> mejorMovimiento = tablero.mejorMovimiento();
            fila = mejorMovimiento[0];
            columna = mejorMovimiento[1];
            tablero.realizarMovimiento(fila, columna, jugadorActual);
            std::cout << "La IA te papea ocupando la celda: " << tablero.movimientoInverso(mejorMovimiento) << std::endl;
        }
        
        int ganador = tablero.revisarTablero();
        std::cout << "---------------------------------------------------------------" << std::endl;

        if (ganador == -10) {
            tablero.mostrarTablero();
            std::cout << "El jugador X ha ganado!" << std::endl;
            break;
        } else if (ganador == 10){
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