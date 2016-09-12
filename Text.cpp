/*
	David Brown
	9.6.16
	Text Struct, Lab 12
*/
#include <iostream>
#include <cstring>
#include <sstream>
#include <stdlib.h>
#include "Text.h"

using namespace std;
namespace CSC2100
{
	Text* createText (const char* charArray)
	{
		Text* str = new Text;
		str->text = charArray;
		str->sz = strlen(charArray);
		return str;
	}
	
	void destroyText (Text* str)
	{
		delete str;
	}
	
	void displayText (Text* str)
	{
		cout << str->text << endl;
	}
	
	int find(Text* str, char delimiter, int start)
	{
		const char* myText = str->text;
		int sz = str->sz;
		if (start < 0 || start > sz)
		{
			return -1;
		}
		for (int i = start; i < sz; i++)
		{
			if (myText[i] == delimiter)
			{
				return i;
			}
		}
		return -1;
	}
	
	Text* substr (Text* str, int start, int end)
	{
		const char* oldStr = str->text;
		int length = end - start;
		char* newStr = new char[length + 1];
		for (int i = start; i < end; i++)
		{
			newStr[i - start] = oldStr[i];
		}
		newStr[length] = '\0';
		Text* newText = createText (newStr);
		return newText;
	}
	
	int compare (Text* str1, Text* str2)
	{
		int sz1 = str1->sz;
		int sz2 = str2->sz;
		//Make sure they are the same size
		if (sz1 > sz2)
		{
			return 1;
		}
		else if (sz1 < sz2)
		{
			return -1;
		}
		const char* first = str1->text;
		const char* second = str2->text;
		for (int i = 0; i < sz1; i++)
		{
			if (first[i] != second[i])
			{
				if (first[i] > second[i]) return 1;
				return -1;
			}
		}
		return 0;
	}
	
	int a_to_i(Text* text)
	{
		const char* str = text->text;
		return atoi(str);
	}

	float a_to_f(Text* text)
	{
		const char* str = text->text;
		return atof(str);
	}

	Text* i_to_a(int number)
	{
		stringstream out;
		out << number;
		const char* text = out.str().c_str();
		return createText (text);
	}

	Text* f_to_a(float number)
	{
		stringstream out;
		out << number;
		const char* text = out.str().c_str();
		return createText (text);
	}
}