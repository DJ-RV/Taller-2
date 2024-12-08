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
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << tablero[i][j];
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
            return (tablero[i][0] == 'X') ? 10 : -10;
        }
        if (tablero[0][i] != '-' && tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i]) {
            return (tablero[0][i] == 'X') ? 10 : -10;
        }
    }
    if (tablero[0][0] != '-' && tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2]) {
        return (tablero[0][0] == 'X') ? 10 : -10;
    }
    if (tablero[0][2] != '-' && tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0]) {
        return (tablero[0][2] == 'X') ? 10 : -10;
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
                tablero[i][j] = 'X';
                int valor = minimax(0, false);
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

int Tablero::minimax(int nivel, bool maximizar) {
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
                    tablero[i][j] = 'X';
                    valor = minimax(nivel + 1, false);
                    tablero[i][j] = '-';
                    mejor = std::max(mejor, valor);
                }
            }
        }
        return mejor;
    } else {
        int mejor = 9999;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tablero[i][j] == '-') {
                    tablero[i][j] = 'O';
                    valor = minimax(nivel + 1, true);
                    tablero[i][j] = '-';
                    mejor = std::min(mejor, valor);
                }
            }
        }
        return mejor;
    }
}

Tablero::~Tablero() {}