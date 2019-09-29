#include "Predicate.h"



Predicate::Predicate()
{
}

Predicate::Predicate(string link_in, Variable &source_in, Variable &target_in)
{
	
	sourceVar = source_in;
	targetVar = target_in;
	Word link(link_in);

	
	Word colon(":");
	Word arrow("->");
	
	outputForm.add_word(link);
	outputForm.add_word(colon);
	outputForm.add_variable(sourceVar);
	outputForm.add_word(arrow);
	outputForm.add_variable(targetVar);
	outputForm.enclose();
}

Predicate::Predicate(string link_in, Variable &source_in, Variable &target_in, Format &form_in)
{
	sourceVar = source_in;
	targetVar = target_in;
	Word link(link_in);
	outputForm = form_in;
}

void Predicate::show()
{
	outputForm.show();
}

Point Predicate::apply(Term &source_term, Term &target_term)
{
	Format newForm(outputForm);
	newForm.substitute(sourceVar, source_term);
	newForm.substitute(targetVar, target_term);

	Point newPoint(source_term, target_term, link, newForm);
	return newPoint;
}


Predicate::~Predicate()
{
}
