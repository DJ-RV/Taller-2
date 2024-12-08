#pragma once
#ifndef TABLERO_H
#define TABLERO_H

#include <string>
#include <vector>

class Tablero {
    private:
    Tablero();
    std::vector<std::vector<char>> tablero;
    int turnos;
    Tablero(const Tablero&) = delete;
    Tablero& operator=(const Tablero&) = delete;
    ~Tablero();
    
    public:
    static Tablero& getInstance();
    void mostrarTablero();
    char determinarTurno();
    char ganadorFinal();
    bool isEmpate();
    bool realizarMovimiento(int row, int col, char jugador);
    int getTurnos();
    void setTurnos(int turnos);
};

#endif