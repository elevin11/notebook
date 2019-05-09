#pragma once
#include<string>
using namespace std;

class Utility
{
public:
	Utility();
	static string file_extend(string); //takes label as input and outputs path to .txt file
	static string file_extend(string, string);	//takes label as input and outputs path to given file type
	static string path(); //returns path to note directory
	~Utility();
};

