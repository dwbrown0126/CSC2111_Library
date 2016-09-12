/*
	David Brown
	9.11.16
	WriteFile Struct.cpp
*/
#include <fstream>
#include "Text.h"
#include "WriteFile.h"

using namespace std;
namespace CSC2100
{
	WriteFile* createWriteFile(const char* fileName)
	{
		WriteFile* oFile = new WriteFile;
		oFile->outFile.open (fileName);
		oFile->closed = false;
		return oFile;
	}

	void destroyWriteFile(WriteFile* wf)
	{
		close (wf);
		delete wf;
	}

	void writeLine(WriteFile* wf, Text* text)
	{
		if ((!wf->closed) && (text->sz > 0))
			wf->outFile << text->text << endl;
	}

	void close(WriteFile* wf)
	{
		wf->outFile.close();
	}

}