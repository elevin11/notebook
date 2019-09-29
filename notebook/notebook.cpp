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
#include "Predicate.h"
#include "Term.h"
#include "Utility.h"
using namespace std;



int main()
{
	NoteManager noteMan;
	SymbolManager symMan;
	CommandLine shell(&noteMan, &symMan);

	shell.show_welcome();

	while (true)
	{
		//Get user input
		string command = shell.get_command();
	}

	return 0;
}

/*
int main()
{
	cout << "PREDICATE SYSTEM TEST" << endl;

	Type object("OBJ");
	Type adjective("ADJ");
	Variable X(object, "X");
	Variable a(adjective, "a");
	Word word1("Test");
	Word word2("Chicken");


	Predicate pred("modifies", a, X);
	pred.show();

	Term abel(adjective, "abelian");
	Term grp(object, "group");
	Point dummy = pred.apply(abel, grp);
	Point second = pred.apply(dummy, grp);
	second.show();

	Term chicken(adjective, "chicken");
	Term biscuit(object, "biscuit");
	Predicate madeFrom("made from", a, X);
	madeFrom.show();
	Point chickenBiskeys = madeFrom.apply(chicken, biscuit);
	chickenBiskeys.show();

	/*
		form.add_word(word1);
		form.add_variable(var1);
		form.enclose();
		form.show();
		Term blah(object, "blah");

		form.substitute(var1, blah);
		form.show();
		/*
		Format form;
		Word * word1 = new Word("Test");
		Word * word2 = new Word("Chicken");

		form.add_word(word1);
		form.add_word(word2);

		form.show();

		Type object("OBJ");
		Variable * X = new Variable(object, "X");
	
		form.add_variable(X);
		form.show();

		Type adjective("ADJ");
		Variable * a = new Variable(adjective, "a");

		form.add_variable(a);
		form.show();
		form.enclose();
		form.show();

		Word * word3 = new Word("Biscuits");
		form.add_word(word3);
		form.show();
	
		form.enclose();
		form.show();

		
	return 0;
}
*/


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
