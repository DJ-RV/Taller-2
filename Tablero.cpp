#include "Tablero.h"
#include <iostream>
#include <string>
#include <vector>

Tablero::Tablero() {
    this -> tablero = std::vector<std::vector<char>>(3, std::vector<char>(3, '-'));
    this -> turnos = 1;
}

Tablero& Tablero::getInstance() {
    static Tablero instance;
    return instance;
}

void Tablero::mostrarTablero() {
    int cont = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tablero[i][j] != 'X' && tablero[i][j] != 'O') {
                std::cout << cont << " ";
            } else {
                std::cout << tablero[i][j] << " ";
            }
            cont++;
        }
        std::cout << std::endl;
    }
}

char Tablero::determinarTurno() {
    return (turnos % 2 == 1) ? 'X' : 'O';
}

int Tablero::revisarTablero() {
    for (int i = 0; i < 3; i++) {
        if (tablero[i][0] != '-' && tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2]) {
            return (tablero[i][0] == 'O') ? 10 : -10;
        }
        if (tablero[0][i] != '-' && tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i]) {
            return (tablero[0][i] == 'O') ? 10 : -10;
        }
    }
    if (tablero[0][0] != '-' && tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2]) {
        return (tablero[0][0] == 'O') ? 10 : -10;
    }
    if (tablero[0][2] != '-' && tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0]) {
        return (tablero[0][2] == 'O') ? 10 : -10;
    }
    return 0;
}

bool Tablero::movimientosDisponibles() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tablero[i][j] == '-') {
                return true;
            }
        }
    }
    return false;
}

bool Tablero::realizarMovimiento(int row, int col, char jugador) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3) {
        std::cout << "Movimiento inválido: fuera de los límites del tablero." << std::endl;
        return false;
    }

    if (tablero[row][col] == '-') {
        tablero[row][col] = jugador;
        return true;
    } else {
        std::cout << "Movimiento inválido: la celda ya está ocupada." << std::endl;
        return false;
    }
}

int Tablero::getTurnos() {
    return this -> turnos;
}

void Tablero::setTurnos(int turnos) {
    this -> turnos = turnos;
}

std::vector<int> Tablero::mejorMovimiento() {
    int mejorValor = -999999;
    std::vector<int> mejorMovimiento(2, -1);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tablero[i][j] == '-') {
                tablero[i][j] = 'O';
                int valor = minimax(0, false, -10000, 10000);
                tablero[i][j] = '-';

                if (valor > mejorValor) {
                    mejorMovimiento[0] = i;
                    mejorMovimiento[1] = j;
                    mejorValor = valor;
                }
            }
        }
    }
    return mejorMovimiento;
}

int Tablero::minimax(int nivel, bool maximizar, int alfa, int beta) {
    int valor = 0;
    int puntaje = revisarTablero();
    if (puntaje == 10) return puntaje - nivel;
    if (puntaje == -10) return puntaje + nivel;
    if (!movimientosDisponibles()) return 0;

    if (maximizar) {
        int mejor = -10000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tablero[i][j] == '-') {
                    tablero[i][j] = 'O';
                    valor = minimax(nivel + 1, false, alfa, beta);
                    tablero[i][j] = '-';
                    mejor = std::max(mejor, valor);
                    alfa = std::max(alfa, valor);
                    if (beta <= alfa) {
                        return mejor;
                    }
                }
            }
        }
        return mejor;
    } else {
        int mejor = 9999;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tablero[i][j] == '-') {
                    tablero[i][j] = 'X';
                    valor = minimax(nivel + 1, true, alfa, beta);
                    tablero[i][j] = '-';
                    mejor = std::min(mejor, valor);
                    beta = std::min(beta, valor);
                    if (beta <= alfa) {
                        return mejor;
                    }
                }
            }
        }

        return mejor;
    }
}

std::vector<int> Tablero::convertirMovimiento(int input) {
    std::vector<int> movimientos(2, -1);

    if (input < 1 || input > 9) {
        std::cout << "Error: El movimiento debe estar entre 1 y 9." << std::endl;
        return movimientos;
    }

    movimientos[0] = (input - 1) / 3;
    movimientos[1] = (input - 1) % 3;

    return movimientos;
}

int Tablero::movimientoInverso(std::vector<int> movimiento) {
    int cont = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == movimiento[0] && j == movimiento[1]) {
                return cont;
            }
            cont++;
        }
    }
    return 0;
}

Tablero::~Tablero() {}