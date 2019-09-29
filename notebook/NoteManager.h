#pragma once
#include <vector>

#include "Manager.h"
#include "Note.h"
#include "Symbol.h"
using namespace std;

class NoteManager : 
	public Manager
{
public:
	void create();
	void create(string);
	void view(string);
	void edit(string);
	void show();
	void destroy(string);
	Note * open(string);


//	void add_symbol(string label_in);
//	void show_symbols();

	NoteManager();
	~NoteManager();
};

