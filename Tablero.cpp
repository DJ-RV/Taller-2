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

char Tablero::ganadorFinal() {
    for (int i = 0; i < 3; i++) {
        if (tablero[i][0] != '-' && tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2]) {
            return tablero[i][0];
        }
        if (tablero[0][i] != '-' && tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i]) {
            return tablero[0][i];
        }
    }
    if (tablero[0][0] != '-' && tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2]) {
        return tablero[0][0];
    }
    if (tablero[0][2] != '-' && tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0]) {
        return tablero[0][2];
    }
    return '-';
}

bool Tablero::isEmpate() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tablero[i][j] == '-') {
                return false;
            }
        }
    }
    return true;
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

Tablero::~Tablero() {}