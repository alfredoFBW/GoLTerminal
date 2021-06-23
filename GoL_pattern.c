
#include <string.h>
#include "GoL_pattern.h"


/* Name of entities */
const char *entities[MAX_ENTITIES] = { "block", "beehive", "loaf", "tub",
				       "blinker", "toad", "beacon", "glider",
				       "lwss", "penta" };

/* Returns pattern's size (entity size) */
void pattern_size(int *nrows, int *ncols, const char *pattern)
{
	if(strcmp(pattern, "block") == 0){
		*nrows = 2;
		*ncols = 2;
	}
	else if(strcmp(pattern, "beehive") == 0){
		*nrows = 3;
		*ncols = 4;
	}
	else if(strcmp(pattern, "loaf") == 0){
		*nrows = 4;
		*ncols = 4;
	}
	else if(strcmp(pattern, "boat") == 0){
		*nrows = 4;
		*ncols = 4;
	}
	else if(strcmp(pattern, "tub") == 0){
		*nrows = 3;
		*ncols = 5;
	}
	else if(strcmp(pattern, "blinker") == 0){
		*nrows = 3;
		*ncols = 3;
	}
	else if(strcmp(pattern, "toad") == 0){
		*nrows = 2;
		*ncols = 4;
	}
	else if(strcmp(pattern, "beacon") == 0){
		*nrows = 4;
		*ncols = 4;
	}
	else if(strcmp(pattern, "glider") == 0){
		*nrows = 3;
		*ncols = 3;
	}
	else if(strcmp(pattern, "lwss") == 0){
		*nrows = 4;
		*ncols = 5;
	}
	else if(strcmp(pattern, "penta") == 0){
		*nrows = 14;
		*ncols = 3;
	}
	else{			/* Error */
		*nrows = -1;
		*ncols = -1;
	}
}

/* Returns pattern */
void pattern_gen(char *entity_matrix[], const char *pattern_name)
{	
	if(strcmp(pattern_name, "block") == 0){
		entity_matrix[0][0] = 1;
		entity_matrix[0][1] = 1;
		entity_matrix[1][0] = 1;
		entity_matrix[1][1] = 1;
	}
	else if(strcmp(pattern_name, "beehive") == 0){
		entity_matrix[0][0] = 0;
		entity_matrix[0][1] = 1;	
		entity_matrix[0][2] = 1;
		entity_matrix[0][3] = 0;
		entity_matrix[1][0] = 1;
		entity_matrix[1][1] = 0;
		entity_matrix[1][2] = 0;	
		entity_matrix[1][3] = 1;
		entity_matrix[2][0] = 0;
		entity_matrix[2][1] = 1;	
		entity_matrix[2][2] = 1;
		entity_matrix[2][3] = 0;	
	}
	else if(strcmp(pattern_name, "loaf") == 0){
		entity_matrix[0][0] = 0; 
		entity_matrix[0][1] = 1;
		entity_matrix[0][2] = 1;
		entity_matrix[0][3] = 1;
		entity_matrix[1][0] = 1;
		entity_matrix[1][1] = 1;
		entity_matrix[1][2] = 1;
		entity_matrix[1][3] = 1;
		entity_matrix[2][0] = 1;
		entity_matrix[2][1] = 1;
		entity_matrix[2][2] = 1;
		entity_matrix[2][3] = 1;
		entity_matrix[3][0] = 1;
		entity_matrix[3][1] = 1;
		entity_matrix[3][2] = 1;
		entity_matrix[3][3] = 1;
	}
	else if(strcmp(pattern_name, "boat") == 0){
		entity_matrix[0][0] = 0; 
		entity_matrix[0][1] = 1;
		entity_matrix[0][2] = 1;
		entity_matrix[0][3] = 0;
		entity_matrix[1][0] = 1;
		entity_matrix[1][1] = 0;
		entity_matrix[1][2] = 0;
		entity_matrix[1][3] = 1;
		entity_matrix[2][0] = 0;
		entity_matrix[2][1] = 1;
		entity_matrix[2][2] = 0;
		entity_matrix[2][3] = 1;
		entity_matrix[3][0] = 0;
		entity_matrix[3][1] = 0;
		entity_matrix[3][2] = 1;
		entity_matrix[3][3] = 0;
	}
	else if(strcmp(pattern_name, "tub") == 0){
		entity_matrix[0][0] = 0; 
		entity_matrix[0][1] = 0;
		entity_matrix[0][2] = 1;
		entity_matrix[0][3] = 0;
		entity_matrix[0][4] = 0;
		entity_matrix[1][0] = 0;
		entity_matrix[1][1] = 1;
		entity_matrix[1][2] = 0;
		entity_matrix[1][3] = 1;
		entity_matrix[1][4] = 0;
		entity_matrix[2][0] = 0;
		entity_matrix[2][1] = 0;
		entity_matrix[2][2] = 1;
		entity_matrix[2][3] = 0;
		entity_matrix[2][4] = 0;
	}
	else if(strcmp(pattern_name, "blinker") == 0){
		entity_matrix[0][0] = 0; 
		entity_matrix[0][1] = 0;
		entity_matrix[0][2] = 0;
		entity_matrix[1][0] = 1;
		entity_matrix[1][1] = 1;
		entity_matrix[1][2] = 1;
		entity_matrix[2][0] = 0;
		entity_matrix[2][1] = 0;
		entity_matrix[2][2] = 0;
	}
	else if(strcmp(pattern_name, "toad") == 0){
		entity_matrix[0][0] = 0; 
		entity_matrix[0][1] = 1;
		entity_matrix[0][2] = 1;
		entity_matrix[0][3] = 1;
		entity_matrix[1][0] = 1;
		entity_matrix[1][1] = 1;
		entity_matrix[1][2] = 1;
		entity_matrix[1][3] = 0;
	}
	else if(strcmp(pattern_name, "beacon") == 0){
		entity_matrix[0][0] = 1; 
		entity_matrix[0][1] = 1;
		entity_matrix[0][2] = 0;
		entity_matrix[0][3] = 0;
		entity_matrix[1][0] = 1;
		entity_matrix[1][1] = 0;
		entity_matrix[1][2] = 0;
		entity_matrix[1][3] = 0;
		entity_matrix[2][0] = 0;
		entity_matrix[2][1] = 0;
		entity_matrix[2][2] = 0;
		entity_matrix[2][3] = 1;
		entity_matrix[3][0] = 0;
		entity_matrix[3][1] = 0;
		entity_matrix[3][2] = 1;
		entity_matrix[3][3] = 1;
	}
	else if(strcmp(pattern_name, "glider") == 0){
		entity_matrix[0][0] = 0;
		entity_matrix[0][1] = 1;
		entity_matrix[0][2] = 0;
		entity_matrix[1][0] = 0;
		entity_matrix[1][1] = 0;
		entity_matrix[1][2] = 1;
		entity_matrix[2][0] = 1;
		entity_matrix[2][1] = 1;
		entity_matrix[2][2] = 1;
	}
	else if(strcmp(pattern_name, "lwss") == 0){
		entity_matrix[0][0] = 1; 
		entity_matrix[0][1] = 0;
		entity_matrix[0][2] = 0;
		entity_matrix[0][3] = 1;
		entity_matrix[0][4] = 0;
		entity_matrix[1][0] = 0;
		entity_matrix[1][1] = 0;
		entity_matrix[1][2] = 0;
		entity_matrix[1][3] = 0;
		entity_matrix[1][4] = 1;
		entity_matrix[2][0] = 1;
		entity_matrix[2][1] = 0;
		entity_matrix[2][2] = 0;
		entity_matrix[2][3] = 0;
		entity_matrix[2][4] = 1;
		entity_matrix[3][0] = 0;
		entity_matrix[3][1] = 1;
		entity_matrix[3][2] = 1;
		entity_matrix[3][3] = 1;
		entity_matrix[3][4] = 1;
	}
	else if(strcmp(pattern_name, "penta") == 0){
		entity_matrix[0][0] = 0; 
		entity_matrix[0][1] = 1;
		entity_matrix[0][2] = 0;
		entity_matrix[1][0] = 1; 
		entity_matrix[1][1] = 1; 
		entity_matrix[1][2] = 1; 
		entity_matrix[2][0] = 0; 
		entity_matrix[2][1] = 0; 
		entity_matrix[2][2] = 0; 
		entity_matrix[3][0] = 0; 
		entity_matrix[3][1] = 0; 
		entity_matrix[3][2] = 0; 
		entity_matrix[4][0] = 1; 
		entity_matrix[4][1] = 1; 
		entity_matrix[4][2] = 1; 
		entity_matrix[5][0] = 0; 
		entity_matrix[5][1] = 0; 
		entity_matrix[5][2] = 0; 
		entity_matrix[6][0] = 1; 
		entity_matrix[6][1] = 0; 
		entity_matrix[6][2] = 1; 
		entity_matrix[7][0] = 1; 
		entity_matrix[7][1] = 0; 
		entity_matrix[7][2] = 1; 
		entity_matrix[8][0] = 0; 
		entity_matrix[8][1] = 0; 
		entity_matrix[8][2] = 0; 
		entity_matrix[9][0] = 1; 
		entity_matrix[9][1] = 1; 
		entity_matrix[9][2] = 1; 
		entity_matrix[10][0] = 0; 
		entity_matrix[10][1] = 0; 
		entity_matrix[10][2] = 0; 
		entity_matrix[11][0] = 0; 
		entity_matrix[11][1] = 0; 
		entity_matrix[11][2] = 0; 
		entity_matrix[12][0] = 1; 
		entity_matrix[12][1] = 1; 
		entity_matrix[12][2] = 1; 
		entity_matrix[13][0] = 0; 
		entity_matrix[13][1] = 1; 
		entity_matrix[13][2] = 0; 
	}
}


