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

void SymbolManager::show()
{
	for (auto it = symbolSet.begin(); it != symbolSet.end(); ++it)
	{
		cout << it->get_display() << " ";
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
