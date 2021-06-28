
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GoL_func.h"
#include "GoL_pattern.h"	

char world[M_ROW][M_COL];
int aux_world[M_ROW][M_COL];

const char kernel[K_ROW][K_COL] = { {1, 1, 1},
				    {1, 0, 1},
				    {1, 1, 1}};
extern const char *entities[MAX_ENTITIES];

/* Convolves world with kernel and stores it into aux_world */
void conv2_same()
{
	int m, n, p, q, r, s;
	int pmin, pmax, qmin, qmax;
	int tmp;
	int row, col;
	/* Just use C division */
	/*row = (int)(floor(K_ROW/2.0));
	col = (int)(floor(K_COL/2.0));*/
	row = K_ROW/2;
	col = K_COL/2;
	for(m = 0, r = 0; m < CONV_ROW; m++){
		for(n = 0, s = 0; n < CONV_COL; n++){
			tmp = 0;
			pmin = MAX(0, m-K_ROW+1);
			pmax = MIN(m, M_ROW-1);
			qmin = MAX(0, n-K_COL+1);
			qmax = MIN(n, M_COL-1);
			for(p = pmin; p <= pmax; p++){
				for(q = qmin; q <= qmax; q++){
					tmp += world[p][q]*kernel[m-p][n-q];
				}
			}
			if((m >= row) && (m < M_ROW + row)){
				if((n >= col) && (n < M_COL + col)){
					aux_world[r][s] = tmp;
					s++;
				}
			}
		}
		if((m >= row) && (m <= M_ROW + row))
			r++;
	
	}
}

/* 
 * Put the pattern entity_matrix with prows and pcols into the world, starting
 * in the row y, and column x 
 */
void put_pattern(char *entity_matrix[], int prows, int pcols, int x, int y)
{
	int k, n, i, j;
	for(k = y, i = 0; k < y + prows; k++, i++){
		for(n = x, j = 0; n < x + pcols; n++, j++){
			world[k][n] = entity_matrix[i][j];
		}
	}
}

/* Initializes the world with pattern_nmb random patterns */
void init_world(int pattern_nmb)
{
	int k, n, x, y, prows, pcols, randi;
	for(k = 0; k < M_ROW; k++){
		for(n = 0; n < M_COL; n++){
			world[k][n] = 0;
		}
	}
	for(k = 0; k < pattern_nmb; k++){
		randi = rand() % MAX_ENTITIES;
		pattern_size(&prows, &pcols, entities[randi]);
		x = rand() % (M_COL - pcols);		/* x represents cols */
		y = rand() % (M_ROW - prows);		/* y represents rows */
		char *entity_matrix[prows];
		for(n = 0; n < prows; n++)
			entity_matrix[n] = malloc(pcols*sizeof(char));
		pattern_gen(entity_matrix, entities[randi]);
		put_pattern(entity_matrix, prows, pcols, x, y);
		/* So we can allocate memory with different size */
		for(n = 0; n < prows; n++)
			free(entity_matrix[n]);
	}
}

/* Returns the next state of the cell with now_state, (1) alive or (0) dead */
char next_state(int neighbours, char now_state)
{
	char alive = 1;
	/* If it was alive and is surrounded by 2 or 3 neighbours -> lives */
	if((now_state == alive) && ((neighbours == 2) || (neighbours == 3)))
		return 1;
	else if((now_state == alive) && ((neighbours >= 4) || (neighbours <= 1)))
		return 0;
	else if((now_state != alive) && ((neighbours == 3)))
		return 1;
	else
		return now_state;	/* Keep the same */
}

/* Steps the world, i.e decide which cells resurrect, die or live and actualizes world */
void world_step()
{
	int k, n;
	conv2_same();
	for(k = 0; k < M_ROW; k++){
		for(n = 0; n < M_COL; n++){
			world[k][n] = next_state(aux_world[k][n], world[k][n]);
		}
	}
}

void show_world()
{
	int k, n;
	for(k = 0; k < M_COL; k++)
		printf(" ");
	printf("\n");
	for(k = 0; k < M_ROW; k++){
		printf(" ");
		for(n = 0; n < M_COL; n++){
			if(world[k][n] == 1)
				printf("%s", "█");
			else
				printf("%c", ' ');
		}
		printf("\n");
	}
}

/* Prints world frontiers */
void print_border()
{
	int k;
	printf("\033[1;1H");
	/* Upper */
	for(k = 0; k < M_COL+1; k++){
		printf("-");
	}
	/* Left */
	printf("\033[1;1H");
	printf("+");
	for(k = 1; k < M_ROW+1; k++){
		printf("\033[%d;1H", k+1);
		printf("|");
	}
	/* Right */
	printf("\033[%d;%dH", 1, M_COL+2);
	printf("+");
	printf("\033[%d;%dH", 2, M_COL+2);
	for(k = 0; k < M_ROW+1; k++){
		printf("|");
		printf("\033[%d;%dH", k+2, M_COL+2);
	}
	/* Bottom */
	printf("\033[%d;%dH", M_ROW+2, 1);
	printf("+");
	for(k = 1; k < M_COL+1; k++)
		printf("-");

	printf("+");
	printf("\n");
}
