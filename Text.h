/*
	David Brown
	9.6.16
	Text Struct, Lab 12
*/
#if !defined TEXT_STRUCT_H
#define TEXT_STRUCT_H

namespace CSC2100
{
	struct Text
	{
		const char* text;
		int sz;
	};
	
	Text* createText (const char* charArray);
	void destroyText (Text* str);
	void displayText (Text* str);
	int find(Text* str, char delimiter, int start);
	Text* substr (Text* str, int start, int end);
	int compare (Text* str1, Text* str2);

	int a_to_i(Text* text);
	float a_to_f(Text* text);
	Text* i_to_a(int number);
	Text* f_to_a(float number);
}
#endif