
#ifndef GOL_FUNC_H_
#define GOL_FUNC_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M_ROW 40 
#define M_COL 80 
#define K_ROW 3
#define K_COL 3
#define CONV_ROW (M_ROW + K_ROW - 1)
#define CONV_COL (M_COL + K_COL - 1)

#define MAX(X,Y) ((X < Y) ? (Y) : (X))
#define MIN(X,Y) ((X < Y) ? (X) : (Y))

/* GoL world */
extern char world[M_ROW][M_COL];

/* Auxiliary world, result of convolution, purpose: counting neighbours */
extern int aux_world[M_ROW][M_COL];

/* Convolution kernel */
extern const char kernel[K_ROW][K_COL];

/* Convolves world with kernel and stores it into aux_world */
void conv2_same();

/* 
 * Put the pattern entity_matrix with prows and pcols into the world, starting
 * in the row y, and column x 
 */
void put_pattern(char *entity_matrix[], int prows, int pcols, int x, int y);

/* Initializes the world with pattern_nmb random patterns */
void init_world(int pattern_nmb);

/* Returns the next state of the cell with now_state, (1) alive or (0) dead */
char next_state(int neighbours, char now_state);

/* Steps the world, i.e decide which cells resurrect, die or live and actualizes world */
void world_step();

void show_world();

/* Prints world frontiers */
void print_border();


#endif /* GOL_FUNC_H_ */
