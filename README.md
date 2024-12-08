# Taller-2
Integrantes:
Andres Giovanni Hidalgo Ramallo - RUT: 21.795.550-5 - Paralelo C1 - Correo Institucional: andres.hidalgo01@alumnos.ucn.cl
Diego Javier Ravanal Vanzi - RUT: 22.228.372-2 - Paralelo C2 - Correo Institucional: diego.ravanal@alumnos.ucn.cl

## Instrucciónes de Ejecución

Al iniciar el programa, se le dejara elegir la posision de una ficha entre el 1 y el 9
en un tablero numerado tal que:
1 2 3
4 5 6
7 8 9
Una vez realizada su acción, la IA tomará la acción más apropiada/óptima para ganar la partida.
El juego prosigue hasta que se alcanza un empate, o dado a un error del jugador, la IA logra
ganar la partida.

## Algoritmo Minimax

El algoritmo minimax es un algoritmo de tipo backtracking que se encarga de 
encontrar el movimiento optimo para una jugada que haga un oponente mediante la
comparación de los casos posibles a partir de la jugada del oponente.

Es principalmente usado en juegos de dos jugadores con tableros pequeños, ya que
el tiempo que requiere el algoritmo para calcular los posibles movimientos incrementa
con la complejidad del juego.

## Que es Minimax y la poda Alfa-Beta

El Minimax es un algoritmo que toma a los dos jugadores de un juego como Min y Max, respectivamente o viceversa.
Trabaja comparando todos los posibles movimientos que puedan suceder y asignandoles un valor dependiendo de
los factores involucrados en esos movimientos.
EJ: substraer puntaje al valor de un movimiento si este termina en derrota o si tarda muchos turnos en ganar.
adicionar puntaje al valor de un movimiento si este este lleva a la victoria en pocos turnos.

## Diagrama de Árbol

El diagrama está adjunto en el repositorio junto con el resto del código.

## Complejidad Temporal

### Sin poda Alfa-Beta

### Con poda Alfa-Beta
