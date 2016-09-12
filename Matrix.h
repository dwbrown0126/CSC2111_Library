/*
	David Brown
	9.6.16
	Matrix Structure, Lab 11
*/
#if !defined MATRIX_STRUCT_H
#define MATRIX_STRUCT_H

namespace CSC2100
{
	struct Matrix
	{
		int rows;
		int cols;
		double* matrixArray;
	};
	
	Matrix* createMatrix (int rows, int cols);
	void destroyMatrix (Matrix* matrix);
	void displayMatrix (Matrix* matrix);
	
	//int index = (row - 1) * numCols + col - 1
	double getElement (Matrix* matrix, int row, int col);
	void setElement (Matrix* matrix, int row, int col, double val);
	Matrix* add(Matrix* left, Matrix* right);
	void writeMatrix (Matrix* matrix, const char* fileName);
	
	Matrix* multiply (Matrix* left, Matrix* right); //Already completed
	Matrix* readMatrix (const char* fileName);		//Already completed
	
}

#endif