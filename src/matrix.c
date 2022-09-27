#include "matrix.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// create new matrix structure
struct matrix *create_matrix(uint16_t rows, uint16_t columns)
{
	struct matrix *new_matrix;

	new_matrix = (struct matrix *)calloc(1, sizeof(struct matrix));
	new_matrix->num_rows = rows;
	new_matrix->num_columns = columns;

	new_matrix->values = (float *)calloc(rows * columns, sizeof(float));
	return new_matrix;
}

// multiply two matrices together, unless their dimensions are incompatible
struct matrix *multiply_matrices(struct matrix *matrix1, struct matrix *matrix2)
{
	uint32_t	i,
			j;
	struct matrix	*new_matrix;

	if ((matrix1->num_columns) != (matrix2->num_rows)) {
		printf("Error: matrix 1 columns not equal to matrix 2 rows!\n");
		return 0;
	}

	new_matrix = (struct matrix *)calloc(1, sizeof(struct matrix));
	new_matrix->num_rows = matrix1->num_rows;
	new_matrix->num_columns = matrix2->num_columns;
	new_matrix->values =
		(float *)calloc((new_matrix->num_rows) * (new_matrix->num_columns),sizeof(float));
	
	for (i = 0; i < new_matrix->num_rows; i++) {
		for (j = 0; j < new_matrix->num_columns; j++) {
			*(fetch_value_addr(new_matrix, i, j)) = dot_product(matrix1, matrix2, i, j);
		}
	}

	return new_matrix;
}

// compute dot product of row in matrix1 and column in matrix2, assuming compatibility
float dot_product(struct matrix *matrix1, struct matrix *matrix2, uint16_t row, uint16_t column)
{
	uint16_t	i;
	float		result;

	result = 0;

	for (i = 0; i < matrix1->num_columns; i++)
		result += *(fetch_value_addr(matrix1, row, i)) * *(fetch_value_addr(matrix2, i, column));

	return result;
}

// fetch address of element in matrix located at row, column
float *fetch_value_addr(struct matrix *matrix_in, uint16_t row, uint16_t column)
{
	float *result;
	result = matrix_in->values + (row * matrix_in->num_columns) + column;
	return result;
}

// insert random values into matrix
void randomize_matrix(struct matrix *matrix_in)
{
	uint32_t i;
	srand(time(NULL));

	for (i = 0; i < ((matrix_in->num_rows) * (matrix_in->num_columns)); i++)
		*(matrix_in->values + i) = ((float)rand())/RAND_MAX;
}

// frees space previously taken up by matrix
void destroy_matrix(struct matrix *matrix_in)
{
	free(matrix_in->values);
	free(matrix_in);
}

// print out matrix values
void display_matrix(struct matrix *matrix_in)
{
	uint16_t i,
		 j;

	for (i = 0; i < matrix_in->num_rows; i++) {
		for (j = 0; j < matrix_in->num_columns; j++)
			printf("%f ", *(fetch_value_addr(matrix_in, i, j)));
		printf("\n");
	}
}
