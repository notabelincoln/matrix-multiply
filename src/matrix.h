#include <stdint.h>
#ifndef MATRIX_H
#define MATRIX_H
// matrix structure which holds all data about the matrix
struct matrix {
	uint16_t num_rows,
		 num_columns;
	float	 *values;
};

// create new matrix structure
struct matrix *create_matrix(uint16_t rows, uint16_t columns);

// multiply two matrices together, unless their dimensions are incompatible
struct matrix *multiply_matrices(struct matrix *matrix1, struct matrix *matrix2);

// compute dot product of row in matrix1 and column in matrix2, assuming compatibility
float dot_product(struct matrix *matrix1, struct matrix *matrix2, uint16_t row, uint16_t column);

// fetch address of element in matrix located at row, column
float *fetch_value_addr(struct matrix *matrix_in, uint16_t row, uint16_t column);

// create random values in matrix elements
void randomize_matrix(struct matrix *matrix_in);

// frees space previously taken up by matrix
void destroy_matrix(struct matrix *matrix_in);

// print out matrix values
void display_matrix(struct matrix *matrix_in);
#endif
