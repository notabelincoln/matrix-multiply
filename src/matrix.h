/*
 * Abe Jordan
 * matrix-multiply
 * matrix.h
 */
#ifndef ABE_MATRIX_H
#define ABE_MATRIX_H
struct matrix {
	unsigned int m;
	unsigned int n;
	double *values;
};

struct matrix *matrix_init(unsigned int m, unsigned int n);

struct matrix *matrix_identity(unsigned int size);

struct matrix *matrix_multiply(struct matrix *a, struct matrix *b);

double matrix_dot_product(struct matrix *a,
				struct matrix *b,
				unsigned int a_row,
				unsigned int b_col);

inline double *matrix_index(struct matrix *mtrx,
				unsigned int i,
				unsigned int j);

int matrix_randomize(struct matrix *mtrx);
#endif
