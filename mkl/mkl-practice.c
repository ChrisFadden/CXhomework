/******************************************************************************
* Name        : mkl-practice.c
* Author      : Daniel Henderson
* Version     : 1.0
* Copyright   : None
* Description : Practice with mkl on the Jinx cluster
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "mkl.h"


int main(int argc, char **argv)
{
	// Matrix size. Any bigger than 8 and it looks really messy when you print
	// the result matrix out. But you can change this to whatever size you
	// want.
	int n = 8;

	// The cblas_dgemm function down below performs this operation:
	// C = alpha*A*B + beta*C
	// You can choose whatever values you want for alpha and beta.
	double alpha = -1.0;
	double beta = 0.0;

	// allocate memory for our matrices
	double *A = (double *) mkl_malloc(n * n * sizeof(double), 64);
	double *B = (double *) mkl_malloc(n * n * sizeof(double), 64);
	double *C = (double *) mkl_malloc(n * n * sizeof(double), 64);

	// initialize matrices with some values
	for (int i = 0; i < n*n; i++)
	{
		A[i] = (double) (i + 1);
		B[i] = (double) (-i - 1);
		C[i] = 0.0;
	}


	// This call to the dgemm routine multiplies the matrices:
	//
	// cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
	//            m, n, k, alpha, A, k, B, n, beta, C, n);
	//
	// The arguments provide options for how Intel MKL performs the operation.
	// In this case:
	//
	// CblasRowMajor:
	// 		Indicates that the matrices are stored in row major order, with the
	//		elements of each row of the matrix stored contiguously as shown in
	//		the figure above.
	//
	// CblasNoTrans:
	// 		Enumeration type indicating that the matrices A and B should not be
	//		transposed or conjugate transposed before multiplication.
	//
	// m, n, k:
	// 		Integers indicating the size of the matrices:
	// 			A: m rows by k columns
	// 			B: k rows by n columns
	// 			C: m rows by n columns
	//
	// alpha:
	// 		Real value used to scale the product of matrices A and B.
	//
	// A:
	// 		Array used to store matrix A.
	//
	// k:
	// 		Leading dimension of array A, or the number of elements between
	//		successive rows (for row major storage) in memory. In the case of
	//		this exercise the leading dimension is the same as the number of
	//		columns.
	//
	// B:
	// 		Array used to store matrix B.
	//
	// n:
	// 		Leading dimension of array B, or the number of elements between
	//		successive rows (for row major storage) in memory. In the case of
	//		this exercise the leading dimension is the same as the number of
	//		columns.
	//
	// beta:
	// 		Real value used to scale matrix C.
	//
	// C:
	// 		Array used to store matrix C.
	//
	// n:
	// 		Leading dimension of array C, or the number of elements between
	//		successive rows (for row major storage) in memory. In the case of
	//		this exercise the leading dimension is the same as the number of
	//		columns.
	cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 
                n, n, n, alpha, A, n, B, n, beta, C, n);


	// print the results
	for (int i = 0; i < n; i++)
	{
		printf("%lf", C[i*n]);
		for (int j = 1; j < n; j++)
			printf(" %lf", C[i*n + j]);
		printf("\n");
	}

	printf("\n");

	// free memory used
	mkl_free(A);
	mkl_free(B);
	mkl_free(C);

	// finished!!!
	return 0;
}
