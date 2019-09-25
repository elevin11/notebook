#include "pch.h"
#include "CommandLine.h"


CommandLine::CommandLine()
{
}

CommandLine::CommandLine(NoteManager * managerInput)
{
	manager = managerInput;
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
		<< "\t symbol <label>" << endl
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

	show_prompt();
	getline(cin, command);
	stringstream stream(command);
	string temp;


	while (stream >> temp)
	{
		parse.push_back(temp);
	}

	//Check for errors
	if (parse.size() <= 0)
	{
		cout << "ERROR: Invalid number of arguments" << endl;
		return string();
	}

	//create map from string inputs -> keyword values
	map<string, Keyword> keywordMap = boost::assign::map_list_of("create", create)("show", show)("view", view)("edit", edit)("remove", remove)("symbol", symbol)("help", help)("quit", quit);
	auto keyIter = keywordMap.find(parse[0]);

	if (keyIter == keywordMap.end())
	{
		cout << "ERROR: Please enter a valid keyword." << endl;
		return string();
	}

	Keyword key = keyIter->second;

	cout << endl << endl;

	switch (key)
	{
	case CommandLine::create:
		if (parse.size() >= 2)
		{
			manager->create_note(parse[1]);
		}
		else
		{
			manager->create_note();
		}
		break;
	case CommandLine::show:
		cout << "NOTES:" << endl;
		manager->show_notes();
		cout << endl << "SYMBOLS: " << endl;
		manager->show_symbols();
		break;
	case CommandLine::view:
		if (parse.size() < 2)
		{
			cout << "ERROR: Please enter a label." << endl;
			break;
		}
		manager->view_note(parse[1]);
		break;
	case CommandLine::edit:
		if (parse.size() < 2)
		{
			cout << "ERROR: Please enter a label." << endl;
			break;
		}
		manager->edit_note(parse[1]);
		break;
	case CommandLine::remove:
		if (parse.size() < 2)
		{
			cout << "ERROR: Please enter a label." << endl;
			break;
		}
		manager->remove_note(parse[1]);
		break;
	case CommandLine::symbol:
		if (parse.size() < 2)
		{
			cout << "ERROR: Please enter a label." << endl;
			break;
		}
		manager->add_symbol(parse[1]);
		break;
	case CommandLine::help:
		show_help();
		break;
	case CommandLine::quit:
		break;
	default:
		break;
	}

	return string();

	
}
