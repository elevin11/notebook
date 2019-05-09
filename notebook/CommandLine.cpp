#include "pch.h"
#include "CommandLine.h"


CommandLine::CommandLine()
{
}


CommandLine::~CommandLine()
{
}

void CommandLine::show_welcome()
{
	cout << "Welcome to Notebook! Please enter a command. " << endl;
}

void CommandLine::show_help()
{
	cout << "List of valid commands:" << endl
		<< "\t create" << endl
		<< "\t show" << endl
		<< "\t view <label>" << endl
		<< "\t edit <label>" << endl
		<< "\t remove <label>" << endl
		<< "\t help" << endl
		<< "\t quit" << endl
		<< endl;
}

void CommandLine::show_prompt()
{
	cout << "::";
}

string CommandLine::get_command()
{
	command.clear();
	parse.clear();

	getline(cin, command);
	stringstream stream(command);
	string temp;

	while (stream >> temp)
	{
		parse.push_back(temp);
	}

	cout << endl << endl;

/*
	//Check for errors
	if (parse.size() <= 0)
	{
		cout << "ERROR: Invalid number of arguments" << endl;
		continue;
	}

	//switch on keyword
	if (parse[0] == "create")
	{
		if (parse.size() >= 2)
		{
			create_note(parse[1]);
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
	else if (parse[0] == "remove")
	{
		manager.remove_note(parse[1]);
	}

	parse.clear();
*/

}
