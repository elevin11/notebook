#include "pch.h"
#include<cstdio>
#include<filesystem>

#include "NoteManager.h"
#include "Utility.h"



void NoteManager::create_note()
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

void NoteManager::create_note(string newLabel)
{
	string new_text;
	cout << "Enter text for Note:" << endl;
	getline(cin, new_text);

	Note * newNote = new Note(newLabel, new_text);
	newNote->save();
}


void NoteManager::view_note(string viewLabel)
{


	//create note from given label and loaded text
	Note * viewNote = open(viewLabel);

	if (viewNote != nullptr)
	{
		cout << endl;
		viewNote->display();
		cout << endl;
	}

	delete viewNote;
}

void NoteManager::edit_note(string editLabel)
{
	Note * editNote = open(editLabel);
	string newText;

	cout << "Enter new text: " << endl;
	getline(cin, newText);

	editNote->set_text(newText);
	editNote->save();
}

void NoteManager::show_notes()
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



Note * NoteManager::open(string openLabel)
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

void NoteManager::remove_note(string deleteLabel)
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

void NoteManager::add_symbol(string label_in)
{
	Symbol * new_symbol = new Symbol(label_in);
	symbols.push_back(new_symbol);
}

void NoteManager::show_symbols()
{
	cout << symbols.size() << " symbols in use" << endl;
	for (auto it = symbols.begin(); it != symbols.end(); ++it)
	{
		cout << (*it)->get_display() << endl;
	}
}

NoteManager::NoteManager()
{
}


NoteManager::~NoteManager()
{
	//delete symbols[]
}
