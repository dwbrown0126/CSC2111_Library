/*
	David Brown
	9.6.16
	Numbered list permutations, Lab 10
*/
#if !defined PERMUTE_H
#define PERMUTE_H

namespace CSC2100
{
	/*
		Pre: n is an integer greater than 0
		Post: returns a list of integers between 1 and n
	*/
	int* initPermutation (int n);
	/*
		Pre: permute is an array of integers of size perSize
		Post: Returns a random number from the array, perSize is adjusted accordingly
	*/
	int nextPermutation(int* permute, int& perSize);
}

#endif