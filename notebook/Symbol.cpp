#include "Symbol.h"



Symbol::Symbol()
{
}

Symbol::Symbol(string display_in)
{
	display = display_in;
}


Symbol::~Symbol()
{
}

bool Symbol::operator==(Symbol const & comp)
{
	if (comp.get_display() == get_display())
	{
		return true;
	}
	return false;
}

string Symbol::get_display() const
{
	return display;
}

void Symbol::set_display(string display_new)
{
	display = display_new;
}

Part::Part()
{
}

Part::~Part()
{
}

Word::Word()
{
}

Word::Word(string display_in)
{
	set_display(display_in);
}

Word::~Word()
{
}


string Word::get_display_space()
{
	string display_space = get_display() + ' ';
	return display_space;
}

Bracket::Bracket(char leftOrRight_in)
{
	if (leftOrRight_in == 'l' || leftOrRight_in == 'L' )
	{
		right = false;
		set_display("[");
	}
	else if (leftOrRight_in == 'r' || leftOrRight_in == 'R')
	{
		right = true;
		set_display("]");
	}
	
}

Bracket::Bracket(Bracket * twin_in)
{
}

Bracket::~Bracket()
{
}
