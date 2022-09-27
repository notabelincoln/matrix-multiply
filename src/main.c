/* Abe Jordan
 * matrix-multiply
 * main.c
 */
#include <stdio.h>
#include "matrix.h"

int main(int argc, char **argv)
{
	struct matrix	*a,
		    		*b,
		    		*c;
	a = create_matrix(50, 50);
	b = create_matrix(50, 50);
	
	for (int i = 0; i < a->num_rows; i++) {
		for (int j = 0; j < a->num_columns; j++)
			*(a->values + i * a->num_columns + j) = i;
	}

	for (int i = 0; i < b->num_rows; i++) {
		for (int j = 0; j < b->num_columns; j++)
			*(b->values + i * b->num_columns + j) = j;
	}

	c = multiply_matrices(a, b);

	printf("a:\n");
	display_matrix(a);
	
	printf("b:\n");
	display_matrix(b);
	
	printf("c:\n");
	display_matrix(c);

	destroy_matrix(a);
	destroy_matrix(b);
	destroy_matrix(c);

	return 0;
}
