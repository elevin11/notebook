// notebook.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<sstream>
#include<string>
#include<vector>

#include"Note.h"
#include"NoteManager.h"
#include"Utility.h"
using namespace std;



int main()
{
	cout << "Enter a command from the following list:" << endl
		<< "create" << endl
		<< "show" << endl
		<< "view <label>" << endl
		<< "edit <label>" << endl
		<< "delete <label>" << endl
		<< endl;

	NoteManager manager;

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
				manager.create_note(parse[1]);
			}
			else
			{
				manager.create_note();
			}
		}
		else if (parse[0] == "show")
		{
			manager.show_notes();
		}
		else if (parse.size() <= 1)	//Check if a label was entered along with a command. 
		{
			cout << "ERROR: Please enter a label." << endl;
			continue;
		}
		else if (parse[0] == "view")
		{

			manager.view_note(parse[1]);
		}
		else if (parse[0] == "edit")
		{
			manager.edit_note(parse[1]);
		}
		else if (parse[0] == "delete")
		{
			manager.delete_note(parse[1]);
		}

		parse.clear();

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
