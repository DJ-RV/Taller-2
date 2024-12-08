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
    int revisarTablero();
    bool movimientosDisponibles();
    bool realizarMovimiento(int row, int col, char jugador);
    int getTurnos();
    void setTurnos(int turnos);
    std::vector<int> mejorMovimiento();
    int minimax(int nivel, bool maximizar, int alfa, int beta);
};

#endif