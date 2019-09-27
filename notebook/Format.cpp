#include "Format.h"



Format::Format()
{
}

Format::Format(const Format &)
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
	cout << endl;
	cout << "Variables: ";
	for (auto it = variables.begin(); it != variables.end(); ++it)
	{
		cout << (*it)->get_display() << " ";
	}
	cout << endl << endl;
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

//substitutes in-place
void Format::substitute(Variable * var_sub, Term * term_sub)
{
	for (auto it = symbols.begin(); it != symbols.end(); ++it)
	{
		if ((*it) == var_sub)
		{
			for (auto v = variables.begin(); v != variables.end(); ++v)
			{
				if ((*v) == var_sub)
				{
					//cout << (*v)->get_display();
					variables.erase(v);
					break;
				}
			}

			(*it) = term_sub;
		}
	}
}
