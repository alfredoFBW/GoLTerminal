
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <signal.h>
#include "GoL_pattern.h"
#include "GoL_func.h"


#define ARG_ERR 1
#define MALLOC_ERR 2
#define SIGNAL_ERR 3
#define AUTHOR "Alfredo Gonzalez Calvin"

extern char world[M_ROW][M_COL];
extern int aux_world[M_ROW][M_COL];
extern const char kernel[K_ROW][K_COL];
extern const char *entities[MAX_ENTITIES];

int end_proccess = 0;

void clean_terminal()
{
	printf("\033[2J\033[1;1H");
}

void sig_int(int arg)
{	
	end_proccess = 1;
}

void sig_term(int arg)
{
	end_proccess = 1;
}


void print_author()
{
	printf("Game of Life. %s (Ctrl + C to quit)", AUTHOR);
}

int main(int argc, char *argv[])
{
	srand(time(NULL));	
	struct sigaction sa_int, sa_term;
	if(argc != 2){
		fprintf(stderr, "Usage: %s <number_of_entities>\n", argv[0]);
		return ARG_ERR;
	}
	/* One handler per signal */
	sa_int.sa_handler = sig_int; sa_term.sa_handler = sig_term;
	sigemptyset(&sa_int.sa_mask); sigemptyset(&sa_term.sa_mask);
	sa_int.sa_flags = 0; sa_term.sa_flags = 0;
	if(sigaction(SIGINT, &sa_int, NULL) == -1){
		perror("Sig_int() error ");
		return SIGNAL_ERR;
	}
	if(sigaction(SIGTERM, &sa_term, NULL) == -1){
		perror("Sig_term() error ");
		return SIGNAL_ERR;
	}

	struct timespec *req = malloc(sizeof(struct timespec));
	if(req == NULL){
		fprintf(stderr, "malloc() error\n");
		return MALLOC_ERR;
	}
	/* Sleep for tv_sec + tv_nsec */
	req->tv_sec  = 0;
	req->tv_nsec = 90000000L;

	init_world(atoi(argv[1]));

	while(!end_proccess){
		clean_terminal();
		show_world();
		print_border();
		print_author();
		fflush(stdout);
		world_step();	
		if(nanosleep(req, NULL) == -1){
			int errsv = errno;
			if((errsv == EFAULT) || (errsv == EINVAL)){
				perror("Error with nanosleep ");
				free(req);
				return -1;
			}
			/* Else: we sent signal */
		}
	}
	clean_terminal();
	free(req);
	return 0;
}
