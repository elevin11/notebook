#pragma once
#include <iostream>
#include <vector>
#include "Manager.h"
#include "Symbol.h"
using namespace std;

class SymbolManager :
	public Manager
{
public:
	SymbolManager();
	~SymbolManager();
	void create(string);
	void show();
	void destroy(string);

private:
	vector<Symbol> symbolSet;
};

