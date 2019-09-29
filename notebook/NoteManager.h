#pragma once
#include <vector>

#include "Note.h"
#include "Symbol.h"
using namespace std;

class NoteManager
{
public:
	void create_note();
	void create_note(string);
	void view_note(string);
	void edit_note(string);
	void show_notes();
	Note * open(string);
	void remove_note(string);

	void add_symbol(string label_in);
	void show_symbols();

	NoteManager();
	~NoteManager();
private:
	vector<Symbol *> symbols; //list of symbols currently in use by manager
};

