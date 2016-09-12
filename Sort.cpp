/*
	David Brown
	9.6.16
	Selection Sort, Lab 8
*/
#include "Sort.h"

namespace CSC2100
{
	void sort (int stuff[], int sz)
	{
		int minIndex,	//Index of the minimum number in the list
			minValue;	//Value of array at minIndex
			
		for (int i = 0; i < sz -1; i++)
		{
			minIndex = i;
			minValue = stuff[minIndex];
			for (int j = i + 1; j < sz; j++)
			{
				if (stuff[j] < minValue)
				{
					minIndex = j;
					minValue = stuff[minIndex];
				}
			}
			stuff[minIndex] = stuff[i];
			stuff[i] = minValue;
		}
	}
}