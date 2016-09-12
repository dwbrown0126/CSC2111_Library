/*
	David Brown
	9.6.16
	Matrix Struct, Lab 11
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Matrix.h"

using namespace std;
namespace CSC2100
{
	Matrix* createMatrix (int rows, int cols)
	{
		Matrix* matrix = new Matrix;
		matrix->cols = cols;
		matrix->rows = rows;
		double* myArray = new double[rows * cols];
		matrix->matrixArray = myArray;
		return matrix;
	}
	
	void destroyMatrix (Matrix* matrix)
	{
		delete[] matrix->matrixArray;
		delete matrix;
	}
	
	void displayMatrix (Matrix* matrix)
	{
		int rows = matrix->rows;
		int cols = matrix->cols;
		int item;
		for (int i = 1; i <= rows; i++)
		{
			for (int j = 1; j <= cols; j++)
			{
				item = getElement (matrix, i, j);
				cout << setw(5) << item;
			}
			cout << endl;
		}
		cout << endl;
	}
	
	//int index = (row - 1) * numCols + col - 1
	double getElement (Matrix* matrix, int row, int col)
	{
		int index = (row - 1) * matrix->cols + col - 1;
		return matrix->matrixArray[index];
	}
	
	void setElement (Matrix* matrix, int row, int col, double val)
	{
		int index = (row - 1) * matrix->cols + col - 1;
		matrix->matrixArray[index] = val;
	}
	
	Matrix* add(Matrix* left, Matrix* right)
	{
		int rrows, rcols, lrows, lcols;
		double lval, rval, result;
		
		rrows = right->rows;
		lrows = left->rows;
		rcols = right->cols;
		lcols = left->cols;
		if (rrows != lrows && rcols != lcols)
		{
			cout << "Rows and Cols are not identical, cannot add matricies" << endl;
			return 0;
		}
		Matrix* matrix = createMatrix (rrows, rcols);
		for (int i = 1; i <= rrows; i++)
		{
			for (int j = 1; j <= rcols; j++)
			{
				rval = getElement (right, i, j);
				lval = getElement (left, i, j);
				result = rval + lval;
				setElement (matrix, i, j, result);
			}
		}
		return matrix;
	}
	
	void writeMatrix (Matrix* matrix, const char* fileName)
	{
		ofstream outFile;
		int rows, cols;
		double value;
		
		outFile.open (fileName);
		rows = matrix->rows;
		cols = matrix->cols;
		
		for (int i = 1; i <= rows; i++)
		{
			for (int j = 1; j <= cols; j++)
			{
				value = getElement (matrix, i, j);
				outFile << setw(5) << value;
			}
			outFile << endl;
		}
	}
	
	Matrix* multiply (Matrix* left, Matrix* right) //Already completed
	{
		int rows1 = left->rows;
		int cols1 = left->cols;

		int rows2 = right->rows;
		int cols2 = right->cols;

		if (cols1 != rows2)
		{
			cout << "Cannot multiply matrices." << endl;
			return createMatrix(1, 1);
		}

		Matrix* result = createMatrix(rows1, cols2);

		int rows = rows1;
		int cols = cols2;

		double x;

		//loop over all elements of resulting matrix
		for (int i = 1; i <= rows; i++)
		{
			for (int j = 1; j <= cols; j++)
			{
				x = 0;
				//sum up multiplying matrices to obtain value placed in new matrix
				for (int k = 1; k <= cols1; k++)
				{
				x = x + getElement(left, i, k) * getElement(right, k, j);
				}
			setElement(result, i, j, x);
			}
		}
		return result;
	}
	
	Matrix* readMatrix (const char* fileName)		//Already completed
	{
		ifstream inFile;
		inFile.open(fileName);

		int rows = 1;
		int cols = 1;

		inFile >> rows >> cols;

		if (rows < 1)
		{
			rows = 1;
		}
		if (cols < 1)
		{
			cols = 1;
		}
		Matrix* matrix = createMatrix(rows, cols);

		for (int i = 1; i <= rows; i++)
		{
			for (int j = 1; j <= cols; j++)
			{
				double val = 0.0;
				inFile >> val;
				setElement(matrix, i, j, val);
			}
		}
		inFile.close();
		return matrix;
	}
}