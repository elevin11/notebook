// notebook.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include<cstdio>
#include<filesystem>
#include <iostream>
#include<sstream>
#include<string>
#include<vector>

#include"Note.h"
#include"Utility.h"
using namespace std;

void create_note();
void create_note(string);
void view_note(string);
void edit_note(string);
void show_notes();
Note * open(string);
void delete_note(string);

int main()
{
	cout << "Enter a command from the following list:" << endl
		<< "create" << endl
		<< "show" << endl
		<< "view <label>" << endl
		<< "edit <label>" << endl
		<< "delete <label>" << endl
		<< endl;


	while (true)
	{
		string command;
		vector<string> parse;

		//Get user input
		cout << "::";		
		getline(cin, command);
		stringstream stream(command);
		string temp;

		while (stream >> temp)
		{
			parse.push_back(temp);
		}
	
		cout << endl << endl;

		//Check for errors
		if (parse.size() <= 0)
		{
			cout << "ERROR: Invalid number of arguments" << endl;
			continue;
		}

		//switch on keyword
		if(parse[0] == "create")
		{
			if (parse.size() >= 2)
			{
				create_note(parse[1]);
			}
			else
			{
				create_note();
			}
		}
		else if (parse[0] == "show")
		{
			show_notes();
		}
		else if (parse.size() <= 1)	//Check if a label was entered along with a command. 
		{
			cout << "ERROR: Please enter a label." << endl;
			continue;
		}
		else if (parse[0] == "view")
		{

			view_note(parse[1]);
		}
		else if (parse[0] == "edit")
		{
			edit_note(parse[1]);
		}
		else if (parse[0] == "delete")
		{
			delete_note(parse[1]);
		}

		parse.clear();

	}
}


void create_note()
{
	string newLabel;
	string newText;

	cout << "Enter label for Note:" << endl;
	getline(cin, newLabel);
	cout << "Enter text for Note:" << endl;
	getline(cin, newText);
	
	Note * newNote = new Note(newLabel, newText);

	newNote->save();
}

void create_note(string newLabel)
{
	string new_text;
	cout << "Enter text for Note:" << endl;
	getline(cin, new_text);

	Note * newNote = new Note(newLabel, new_text);
	newNote->save();
}


void view_note(string viewLabel)
{


	//create note from given label and loaded text
	Note * viewNote = open(viewLabel);

	if(viewNote != nullptr)
	{
		cout << endl;
		viewNote->display();
		cout << endl;
	}
	
	delete viewNote;
}

void edit_note(string editLabel)
{
	Note * editNote = open(editLabel);
	string newText;

	cout << "Enter new text: " << endl;
	getline(cin, newText);

	editNote->set_text(newText);
	editNote->save();
}

void show_notes()
{
	string dir = Utility::path();
	string noteLabel;

	for (const auto & file : experimental::filesystem::directory_iterator(dir))
	{
		string fullName = file.path().filename().string();
		auto dot = fullName.find_last_of('.');
		noteLabel = fullName.substr(0, dot);
		cout << noteLabel << endl;
	}
}

Note * open(string openLabel)
{
	string filename = Utility::file_extend(openLabel);
	string openText;
	ifstream openFile(filename);


	if (openFile.is_open())
	{
		getline(openFile, openText);
	}
	else
	{
		cout << "ERROR: Could not open " << openLabel << ".txt" << endl;
		return nullptr;
	}

	Note * openNote = new Note(openLabel, openText);
	return openNote;
}

void delete_note(string deleteLabel)
{
	string path = Utility::file_extend(deleteLabel);
	if (remove(path.c_str()) != 0)
	{
		cout << "ERROR: Could not delete file." << endl;
	}
	else
	{
		cout << "Note \"" << deleteLabel << "\" deleted." << endl;
	}
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
