#include "SymbolManager.h"



SymbolManager::SymbolManager()
{
}


SymbolManager::~SymbolManager()
{
}

void SymbolManager::create(string symName)
{
	Symbol newSym(symName);
	symbolSet.push_back(symName);
}

void SymbolManager::createType(string typeName_in)
{
	Type addType(typeName_in);
	typeSet.push_back(addType);
}

void SymbolManager::createTerm(Type type_in, string termName_in)
{
	Term addTerm(type_in, termName_in);
	symbolSet.push_back(addTerm);
	termSet.push_back(addTerm);
}

void SymbolManager::createTerm(string typeName_in, string termName_in)
{
	Type addType(typeName_in);
	Term addTerm(addType, termName_in);
	symbolSet.push_back(addTerm);
	termSet.push_back(addTerm);
}

void SymbolManager::show()
{
	for (auto it = symbolSet.begin(); it != symbolSet.end(); ++it)
	{
		cout << it->get_display() << " ";
	}
	cout << endl;
	for (auto it = termSet.begin(); it != termSet.end(); ++it)
	{
		cout << it->get_type().get_string() << " " << it->get_display() << "; ";
	}
	cout << endl;
}

void SymbolManager::destroy(string symName)
{
	for (auto it = symbolSet.begin(); it != symbolSet.end(); ++it)
	{
		if (*it == symName)
		{
			symbolSet.erase(it);
		}
	}
}
