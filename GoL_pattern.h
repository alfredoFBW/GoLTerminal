

#ifndef GOL_PATTERN_H_
#define GOL_PATTERN_H_

#include <string.h>

#define MAX_ENTITIES 10

/* Name of entities */
extern const char *entities[MAX_ENTITIES];

/* Returns pattern's size (entity size) */
void pattern_size(int *nrows, int *ncols, const char *pattern);

/* Return pattern */
void pattern_gen(char *entity_matrix[], const char *pattern_name);

#endif /* GOL_PATTERN_H_ */
