// notebook.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<sstream>
#include<string>
#include<vector>

#include "CommandLine.h"
#include "Format.h"
#include "Note.h"
#include "NoteManager.h"
#include "Utility.h"
using namespace std;


/*
int main()
{
	NoteManager manager;
	CommandLine shell(&manager);

	shell.show_welcome();

	while (true)
	{
		//Get user input
		string command = shell.get_command();
	}

	return 0;
}
*/

int main()
{
	cout << "PREDICATE SYSTEM TEST" << endl;
	Format form;
	Word * word1 = new Word("Test");
	Type object("OBJ");
	Variable * var1 = new Variable(object, "var1");
	form.add_word(word1);
	form.add_variable(var1);
	form.enclose();
	form.show();

	return 0;
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
