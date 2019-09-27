#pragma once
#include <algorithm>
#include <string>
#include "Format.h"
#include "Point.h"
#include "Symbol.h"
#include "Term.h"
using namespace std;

class Predicate
{
public:
	Predicate();
	Predicate(string link_in, Variable * source_in, Variable * target_in);
	Predicate(string link_in, Variable * source_in, Variable * target_in,  Format form_in);
	void show();
	Point apply(Term * source_term, Term * target_term);
	~Predicate();
private:
	Word * link;
	Variable * source_var;
	Variable * target_var;
	Format output_form;
};

