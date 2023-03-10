/**
 * @file snake_labyrinth.c
 * @author federico scaggiante
 * @brief a simple game where a snake tries to escape from a labyrinth
 * @date 2023-01-05
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

/**number of rows in the board*/
int rows;

/**number of cols in the board*/
int cols;

/**matrix of chars that represent the labyrinth*/
char **board;

/**is the game finished?*/
int gameover;

/**is the game won or lost?*/
int win;

/**game score, it starts at 1000*/
int score;

/**it rapresents the direction of the snake move*/
int direction;

/**lenght of the tail array*/
int tail_lenght;

/**number of usages of the drill*/
int drill_usages;

/**is the game in ai mode or in user input mode*/
int ai_mode;

/**array of moves*/
int *moves;

/**moves counter*/
int moves_lenght;

/**
 * @brief structure that represent a coordinate
 * @details made with two i and j integers
 */
typedef struct
{
    /**it indicates the position in the y axis of the board*/
    int i;
    /**it indicates the position in the x axis of the board*/
    int j;
} coordinates;

/**i split the snake head from the tail to make implementation of the game clearer*/
coordinates snake_head;

/**array of coordinates that rappresent the tail of the snake*/
coordinates *snake_tail;

/**dove vengono richieste il numero di colonne, righe e il labirinto e poi vengono inizializzate tutte le variabili necessario al funzionamento del gioco.*/
void setup();

/**funzione principale del gioco che controlla dopo che ogni mossa viene inserita, se lo snake può muoversi in quella direzione e successivamente controllo tutte le possibili collisioni e gestisce il movimento della coda.*/
void logic();

/**dopo ogni mossa refresha e ridisegna il labyrinto stampando anche il punteggio e il numero di utilizzi del trapano rimasti. Se è l’AI ha giocare mostra anche tutte le mosse intraprese.*/
void draw();

/**
 * @brief simple function that changes the direction flag from user input
 * @details the current input choice is wasd style
 * @details it uses the getChar() function;
 */
void input();

/**
 * @brief simple function that pick a random direction after checking if possible to make
 */
void random_ai();

/**
 * @brief function that allows the snake to follow the right wall of the labyrinth untill it reaches the end
 * @attention not yet implemented
 */
void wall_follow_ai();

/**print ending massage according to the win flag, also print the score*/
void ending();

/**it frees the all the dinamically allocated memory*/
void free_memory();

/**
 * @brief main loop
 *
 * \code{.c}
 * setup();

    while (!gameover)
    {
        draw();
        if (ai_mode)
        {
            random_ai();
        }
        else
        {
            input();
        }
        logic();
    }
    ending();

    free_memory();
  \endcode
 */
void main();