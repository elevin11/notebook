#pragma once
#include <iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;


class CommandLine
{
public:
	CommandLine();
	~CommandLine();
	void show_welcome();
	void show_help();
	void show_prompt();
	string get_command();
private:
	enum Keyword{ create, show, view, edit, remove, help, quit};
	string command;
	vector<string> parse;
};

