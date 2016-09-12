/*
	David Brown
	9.11.16
	ReadFile Struct
*/
#if !defined READFILE_H
#define READFILE_H

#include "Text.h"
#include <fstream>

using namespace std;
namespace CSC2100
{

	struct ReadFile
	{
		ifstream inFile;
		bool closed;
		bool _eof;
	};
	
	ReadFile* createReadFile(const char* fileName);
	void destroyReadFile(ReadFile* rf);
	Text* readLine(ReadFile* rf);
	bool eof(ReadFile* rf);
	void close(ReadFile* rf);
}

#endif