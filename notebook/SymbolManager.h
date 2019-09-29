#pragma once
#include <iostream>
#include <vector>
#include "Manager.h"
#include "Symbol.h"
#include "Term.h"
#include "Type.h"
using namespace std;

class SymbolManager :
	public Manager
{
public:
	SymbolManager();
	~SymbolManager();
	void create(string symName_in);
	void createType(string typeName_in);
	void createTerm(Type type_in, string termName_in);
	void createTerm(string typeName_in, string termName_in); //creates new type along with term
	void show();
	void destroy(string);

private:
	vector<Symbol> symbolSet;
	vector<Type> typeSet;
	vector<Term> termSet;
};

