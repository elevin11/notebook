#include "Term.h"



Term::Term()
{
}

Term::Term(Type type_in, string disp_in)
{
	termType = type_in;
	set_display(disp_in);
}


Term::~Term()
{
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
