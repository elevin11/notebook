#include "pch.h"
#include "Utility.h"


Utility::Utility()
{
}

string Utility::file_extend(string input_s)
{

	string file = input_s.append(".txt");
	string output = path().append(file);
	return output;
}

string Utility::file_extend(string input_s, string extension)
{
	string file = input_s.append(".");
	file.append(extension);
	string output = path().append(file);
	return output;
}

string Utility::path()
{
	string path = ".\\notes\\";
	return path;
}

Utility::~Utility()
{
}
