/*
	David Brown
	9.11.16
	Readfile.cpp
*/
#include "ReadFile.h"
#include "Text.h"
#include <fstream>

using namespace std;
namespace CSC2100
{

	ReadFile* createReadFile(const char* fileName)
	{
		ReadFile* rf = new ReadFile;
		rf->inFile.open (fileName);
		if (!rf->inFile)
		{
			ofstream outFile;
			outFile.open(fileName);
			outFile.close();
			rf->inFile.open(fileName);
		}
		rf->closed = false;
		rf->_eof = false;
		return rf;
	}
	
	void destroyReadFile(ReadFile* rf)
	{
		close (rf);
		delete rf;
	}
	
	Text* readLine(ReadFile* rf)
	{
		if (rf->closed) return NULL;
		if (rf->_eof) return NULL;

		string str;
		rf->_eof = !(getline (rf->inFile, str));
		Text* text = createText (str.c_str());
		return text;
	}
	
	bool eof(ReadFile* rf)
	{
		return rf->_eof;
	}
	
	void close(ReadFile* rf)
	{
		if (rf->closed == false)
		{
			rf->inFile.close();
			rf->closed = true;
		}
	}
}