# Taller-2
Integrantes:
Andres Giovanni Hidalgo Ramallo - RUT: 21.795.550-5 - Paralelo C1 - Correo Institucional: andres.hidalgo01@alumnos.ucn.cl
Diego Javier Ravanal Vanzi - RUT: 22.228.372-2 - Paralelo C2 - Correo Institucional: diego.ravanal@alumnos.ucn.cl

## Instrucciónes de Ejecución

Para la compilación del ejecutable, utilizar:
g++ main.cpp Tablero.cpp -o juego
./juego

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

El algoritmo Minimax es una técnica utilizada en juegos de dos jugadores para determinar el mejor movimiento posible, 
asumiendo que ambos jugadores juegan de manera óptima. Funciona evaluando todas las posibles 
jugadas futuras y eligiendo la que maximiza la ganancia del jugador actual, mientras 
minimiza la ganancia del oponente. Se basa en la idea de que un jugador tratará de maximizar 
su propio beneficio (maximizar), mientras que el oponente intentará minimizar el beneficio del jugador (minimizar). 
Este proceso se repite hasta llegar a una condición terminal del juego (como victoria, derrota o empate).

La poda alfa-beta es una optimización del algoritmo Minimax que mejora su eficiencia al eliminar 
ramas del árbol de búsqueda que no es necesario explorar. 
Funciona manteniendo dos valores, alfa (el mejor valor encontrado hasta el momento para el jugador maximizador) y 
beta (el mejor valor para el jugador minimizador). 
Si en cualquier punto un nodo tiene un valor peor que el de un nodo ya evaluado, se poda esa rama, 
evitando la exploración innecesaria y reduciendo el número de nodos evaluados. 
Esto acelera significativamente el proceso sin afectar el resultado final.

## Diagrama de Árbol

El diagrama está adjunto en el repositorio junto con el resto del código.

## Complejidad Temporal

con b como el número de casillas vacías en el tablero en cada turno, y d como la profundidad 
del árbol de decisiones, es decir, cuántos niveles de decisiones se exploran:

### Sin poda Alfa-Beta

La complejidad temporal de Minimax para el juego del gato es 
sin poda Alfa-Beta es O(b^d)

### Con poda Alfa-Beta

La comprejidad temporal de Minimax para el juego del gato,
si se utiliza el metodo de poda alfa-beta, será de O(b^d/2)

