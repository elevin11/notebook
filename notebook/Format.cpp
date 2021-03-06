
#include "Format.h"



Format::Format()
{
}

Format::Format(const Format &other)
{
	for (auto it = other.symbols.begin(); it != other.symbols.end(); ++it)
	{
		Symbol addSym(it->get_display());
		symbols.push_back(addSym);
		//		symbols.push_back(new Symbol((*it)->get_display()));
	}

	for (auto it = other.variables.begin(); it != other.variables.end(); ++it)
	{
		Variable addVar(it->get_type(), it->get_display());
		variables.push_back(addVar); //push back copy of variables
	}
}


Format::~Format()
{
}

string Format::get_string()
{
	string disp;
	for (auto it = symbols.begin(); it != symbols.end(); ++it)
	{
		disp.append(it->get_display());
	//	disp.append((*it)->get_display());
		disp.append(" ");
	}
	return disp;
}

void Format::show()
{
	for (auto it = symbols.begin(); it != symbols.end(); ++it)
	{
		cout << (it)->get_display() << " ";
	}
	cout << endl;
/*	cout << "Variables: ";
	for (auto it = variables.begin(); it != variables.end(); ++it)
	{
		cout << (*it)->get_display() << " ";
	}
	cout << endl << endl;
*/
}

void Format::add_word(Word &word_in)
{
	symbols.push_back(word_in);
}

void Format::add_variable(Variable &var_in)
{
	symbols.push_back(var_in);
	variables.push_back(var_in);
}

void Format::enclose()
{
	Bracket left('l'); 
	Bracket right('r');
	symbols.insert(symbols.begin(), left);
	symbols.push_back(right);
}


void Format::substitute(Variable & var_sub, Term & term_sub)
{
	for (auto it = symbols.begin(); it != symbols.end(); ++it)
	{
		if ((*it) == var_sub)
		{
			for (auto v = variables.begin(); v != variables.end(); ++v)
			{
				if (*v == var_sub)
				{
					//cout << (*v)->get_display();
					variables.erase(v);
					break;
				}
			}

			//cout << "sub " << term_sub->get_display() << " for " << var_sub->get_display() << endl;
			(*it) = term_sub;
		}
	}
}

