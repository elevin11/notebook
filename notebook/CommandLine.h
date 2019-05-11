#pragma once
#include<boost/assign/list_of.hpp>
#include <iostream>
#include <map>
#include<sstream>
#include<string>
#include<vector>
#include "Command.h"
#include "NoteManager.h"
using namespace std;


class CommandLine
{
public:
	CommandLine();
	CommandLine(NoteManager *); //Attach CommandLine to given NoteManager
	~CommandLine();
	void show_welcome();	//display welcome message
	void show_help();		//display help message
	void show_prompt();		//display command prompt
	string get_command(); 
							//	Command get_command(string); //converts user input string to a Command object
private:
	enum Keyword{ create, show, view, edit, remove, help, quit};
	string command;
	vector<string> parse;
	NoteManager * manager;
};

