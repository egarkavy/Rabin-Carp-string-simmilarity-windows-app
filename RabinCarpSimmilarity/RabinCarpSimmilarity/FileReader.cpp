#include "FileReader.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace System::IO;

System::String^ readFile(System::String^ path)
{
	StreamReader fileStream(path);

	System::String^ text = fileStream.ReadToEnd();

	return text;

}
