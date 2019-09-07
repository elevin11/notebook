#pragma once
#include<fstream>
#include<iostream>
#include<string>

using namespace std;


class Point;

class Note
{
public:
	Note(); //creates empty Note
	Note(string); //creates Note from text file with given label
	Note(string, string); //creates new Note with given text
	void display(); //outputs current contents
	int save(); //saves Note to file, returns 1 if sucessful
	void set_text(string); //updates text contents
	~Note();

private:
	Point * p;
	string label;
	string text;

};

