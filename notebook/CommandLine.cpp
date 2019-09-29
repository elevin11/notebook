#include "pch.h"
#include "CommandLine.h"


CommandLine::CommandLine()
{
}

CommandLine::CommandLine(NoteManager * noteManInput)
{
	noteMan = noteManInput;
}

CommandLine::CommandLine(NoteManager * noteManInput, SymbolManager * symManInput, PredicateManager * predManInput)
{
	noteMan = noteManInput;
	symbolMan = symManInput;
	predMan = predManInput;
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
		<< "\t term <type> <label>" << endl
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
	map<string, Keyword> keywordMap = boost::assign::map_list_of("create", create)("show", show)("view", view)("edit", edit)("remove", remove)("symbol", symbol)("term", term)("predicate", predicate)("help", help)("quit", quit);
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
			noteMan->create(parse[1]);
		}
		else
		{
			noteMan->create();
		}
		break;
	case CommandLine::show:
		cout << "NOTES:" << endl;
		noteMan->show();
		cout << endl << "SYMBOLS: " << endl;
		symbolMan->show();
		cout << endl << "PREDICATES:" << endl;
		predMan->show();
		break;
	case CommandLine::view:
		if (parse.size() < 2)
		{
			cout << "ERROR: Please enter a label." << endl;
			break;
		}
		noteMan->view(parse[1]);
		break;
	case CommandLine::edit:
		if (parse.size() < 2)
		{
			cout << "ERROR: Please enter a label." << endl;
			break;
		}
		noteMan->edit(parse[1]);
		break;
	case CommandLine::remove:
		if (parse.size() < 2)
		{
			cout << "ERROR: Please enter a label." << endl;
			break;
		}
		noteMan->destroy(parse[1]);
		break;
	case CommandLine::symbol:
		if (parse.size() < 2)
		{
			cout << "ERROR: Please enter a label." << endl;
			break;
		}
		symbolMan->create(parse[1]);
		break;
	case CommandLine::term:
		if (parse.size() < 3)
		{
			cout << "ERROR: Please enter a type and a label." << endl;
		}
		symbolMan->createTerm(parse[1], parse[2]);
		break;
	case CommandLine::predicate:
		if (parse.size() < 2)
		{
			cout << "ERROR: Please enter a predicate name." << endl;
		}
		if (parse.size() == 2) //only link name is given
		{
			predMan->create(parse[1]);
		}
		else if (parse.size() == 3) //link name and single type is given
		{
			Type varType(parse[2]);
			symbolMan->createType(parse[2]);
			predMan->create(parse[1], varType);

		}
		else //link name and two types are given
		{
			Type srcType(parse[2]);
			Type tgtType(parse[3]);
			symbolMan->createType(parse[2]);
			symbolMan->createType(parse[3]);
			predMan->create(parse[1], srcType, tgtType);
		}
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
