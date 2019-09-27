#include "Term.h"



Term::Term()
{
}

Term::Term(Type type_in, string disp_in)
{
	termType = type_in;
	set_display(disp_in);
}

bool Term::operator==(Term const & comp)
{
//	const string disp = get_display();
//	const string compDisp = comp.get_display();
	if (comp.get_display() == get_display() && comp.get_type() == get_type())
	{
		return true;
	}
	return false;
}


Term::~Term()
{
}

Type Term::get_type() const
{
	return termType;
}

void Term::set_type(Type type_in)
{
	termType = type_in;
}

Variable::Variable(Type type_in, string disp_in)
{
	this->set_type(type_in);
	this->set_display(disp_in);
}
