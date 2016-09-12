/*
	David Brown
	9.8.16
	Token Struct, Lab 13
*/
#if !defined NULL
#define NULL = 0
#endif

#if !defined TOKENS_H
#define TOKENS_H

#include "Text.h"

namespace CSC2100
{
	struct Tokens
	{
		Text** tokens;
		int maxTokens;
		int sz;
	};

	//Public functions
	Tokens* createTokens (Text* str, char delimiter);
	void destroyTokens (Tokens* tokens);
	void displayTokens (Tokens* tokens);
	Text* getToken (Tokens* tokens, int index);	
}

#endif