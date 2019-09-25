#include "Format.h"



Format::Format()
{
}


Format::~Format()
{
}

void Format::show()
{
	for (auto it = symbols.begin(); it != symbols.end(); ++it)
	{
		cout << (*it)->get_display() << " ";
	}
}

void Format::add_word(Word * word_in)
{
	symbols.push_back(word_in);
}

void Format::add_variable(Variable * var_in)
{
	symbols.push_back(var_in);
	variables.push_back(var_in);
}

Bracket * Format::enclose()
{
	Bracket * left = new Bracket('l');
	Bracket * right = new Bracket('r');
	symbols.insert(symbols.begin(), left);
	symbols.push_back(right);
	return left;
}
