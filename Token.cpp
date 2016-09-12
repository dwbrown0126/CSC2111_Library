/*
	David Brown
	9.8.16
	Token Struct, Lab 13
*/
#include "Text.h"
#include "Token.h"

namespace CSC2100
{
	//Hidden functions
	void resize (Tokens* tokens)
	{
		//Get the old max
		int oldMax = tokens->maxTokens;
		//Double it
		int newMax = oldMax * 2;
		//Create a new tokens array to hold the stuff
		Text** newStrings = new Text*[newMax];
		Text** oldStrings = tokens->tokens;
		
		//Copy the old token array over to the new
		for (int i = 0; i < oldMax; i++)
		{
			newStrings[i] = oldStrings[i];
		}
		//Initialize all the other tokens to null
		for (int i = oldMax; i < newMax; i++)
		{
			newStrings[i] = 0;
		}
		//Set up tokens with the new information
		tokens->tokens = newStrings;
		tokens->maxTokens = newMax;
	}

	Tokens* initTokens (int startSize)
	{
		Tokens* tokens = new Tokens;
		tokens->sz = 0;
		tokens->maxTokens = startSize;
		Text** strings = new Text*[startSize];
		for (int i = 0; i < startSize; i++)
		{
			strings[i] = 0;
		}
		tokens->tokens = strings;
		return tokens;
	}

	void addToken (Tokens* tokens, Text* str)
	{
		//Create my local holding variables
		int curr = tokens->sz;
		int max = tokens->maxTokens;
		
		//Test to see if I am full
		if (curr == max)
			resize (tokens);
		
		//Add the stuff to my array
		Text** text = tokens->tokens;
		text[curr] = str;
		
		//Let the array know I am one larger
		tokens->sz++;
	}

	//Public functions
	Tokens* createTokens (Text* str, char delimiter)
	{
		int maxSize = 2;
		int foundDelimiter, 	//Location in string delimiter was found
			sizeStr, 			//Size of the passed Text string
			start;				//Starting point of search for next delimiter
		Text* subString;		//Substring of original string for tokenizing
		
		Tokens* tokens = initTokens(maxSize);
		start = 0;				//Start at beginning
		do {
			foundDelimiter = find (str, delimiter, start);
			if (foundDelimiter > 0)
			{
				subString = substr (str, start, foundDelimiter);
				addToken (tokens, subString);
				start = foundDelimiter + 1;
			}
		} while (foundDelimiter != -1);
		if (start != str->sz)
		{
			subString = substr (str, start, str->sz);
			addToken (tokens, subString);
		}
		return tokens;
	}

	void destroyTokens (Tokens* tokens)
	{
		//Get my local variables
		int total = tokens->sz;
		Text** strings = tokens->tokens;
		//Delete each entry
		for (int i = 0; i < total; i++)
		{
			destroyText (strings[i]);
		}
		//Delete the containers
		delete[] strings;
		delete tokens;
	}

	void displayTokens (Tokens* tokens)
	{
		//Local variables
		int sz = tokens->sz;
		Text** strings = tokens->tokens;
		
		//Step through and display each token
		for (int i = 0; i < sz; i++)
		{
			Text* curr = strings[i];
			displayText (curr);
		}
	}

	Text* getToken (Tokens* tokens, int index)
	{
		//Local variables;
		Text** strings = tokens->tokens;
		//Get the one the user wants and return it...
		Text* curr = strings[index];
		return curr;
	}
}