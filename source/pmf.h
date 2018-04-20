#ifndef PMF_H_
#define PMF_H_

#include "stddef.h"

typedef struct matrix_size{
  size_t row_size;
  size_t col_size;
} matrix_size;

typedef struct decomposition{
	float **X;
  matrix_size MX;
  float **Y;
  matrix_size MY;
}decomposition;

typedef struct prob_params{
  float lambda;
  float mu;
  float num_iter;
  float iter;
  size_t dim;
  unsigned int num_threads;
  float lr;
}prob_params;

int _randomizer(float **R, matrix_size MR, unsigned int **correspondance);
void _launch_sched(matrix_size MR, unsigned int num_threads);
void _factorize_block(prob_params *params, float** R, matrix_size MR, \
  decomposition *dec, unsigned int iteration);
void matrix_factorize(prob_params *params, float** R,\
  decomposition *dec, matrix_size MR);

#endif // PMF_H_