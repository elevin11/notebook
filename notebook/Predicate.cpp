#include "Predicate.h"



Predicate::Predicate()
{
}

Predicate::Predicate(string link_in, Variable * source_in, Variable * target_in)
{
	
	source_var = source_in;
	target_var = target_in;
	link = new Word(link_in);

	

	Word * colon = new Word(":");
	Word * arrow = new Word("->");

	output_form.add_word(link);
	output_form.add_word(colon);
	output_form.add_variable(source_var);
	output_form.add_word(arrow);
	output_form.add_variable(target_var);
	output_form.enclose();
}

Predicate::Predicate(string link_in, Variable * source_in, Variable * target_in, Format form_in)
{
	source_var = source_in;
	target_var = target_in;
	link = new Word(link_in);
	output_form = form_in;
}

void Predicate::show()
{
	output_form.show();
}

Point Predicate::apply(Term * source_term, Term * target_term)
{
	Format newForm(output_form);
	newForm.substitute(source_var, source_term);
	newForm.substitute(target_var, target_term);

	Point newPoint(source_term, target_term, link, newForm);
	return newPoint;
}


Predicate::~Predicate()
{
}
