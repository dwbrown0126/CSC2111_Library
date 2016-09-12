/*
	David Brown
	9.6.16
	Numbered list permutations, Lab 10
*/
#include "Permute.h"
#include "Random.h"

namespace CSC2100
{
	/*
		Pre: permute is an array of integers of size perSize, 
				index is an integer between 0 inclusive and perSize exclusive
		Post: item at index in array is removed, all other elements 
				to the right of the index are shifted one to the left
	*/
	void removePermutation (int* permute, int perSize, int index)
	{
		for (int i = index; i < perSize; i++)
		{
			permute[i] = permute[i + 1];
		}
		permute[perSize] = 0;
	}
	
	int* initPermutation (int n)
	{
		int* permute = new int[n];
		for (int i = 0; i < n; i++)
		{
			permute[i] = i + 1;
		}
		return permute;
	}
	
	int nextPermutation(int* permute, int& perSize)
	{
		int index, 	//Index to pull number from
			myNum;	//Number being pulled from the array

		seedRandom();
		index = getRandomInt (0, perSize);
		myNum = permute[index];
		removePermutation (permute, perSize, index);
		perSize--;
		return myNum;
	}
}
