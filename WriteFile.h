/*
	David Brown
	9.11.16
	WriteFile Struct.h
*/
#if !defined WRITEFILE_H
#define WRITEFILE_H

#include "Text.h"
#include <fstream>

using namespace std;
namespace CSC2100
{

	struct WriteFile
	{
		ofstream outFile;
		bool closed;
	};
	
	WriteFile* createWriteFile(const char* fileName);
	void destroyWriteFile(WriteFile* wf);
	void writeLine(WriteFile* wf, Text* text);
	void close(WriteFile* wf);
}

#endif