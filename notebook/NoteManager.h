#pragma once

#include"Note.h"
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
	void delete_note(string);

	NoteManager();
	~NoteManager();
};

