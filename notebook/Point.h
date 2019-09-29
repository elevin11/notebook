#pragma once
#include<utility>
#include <iostream>

#include "Format.h"
#include "Symbol.h"
#include "Term.h"

using namespace std;

/*	Unit of knowledge. 
	String of words, brackets, concepts, and names that conveys a piece of information.
	Has reference to 'dependent' points which build on it.
	Built from predicate and list of matching-type terms. Point inherits type from predicate.
	Marked variables in predicate correspond to assigned parts in point.
*/

class Point
	: public Term
{
public:
	Point();
	~Point();
	Point(Term * source_in, Term * target_in, Word * link_in, Format form_in);
	void show();
	void info();
//	Point(Predicate pred_in, vector<Concept *> concepts_in, vector<Name *> names_in, vector<Point *> dependents_in);	//constructs point with given inputs as data members if concept/name/point types match corresponding types in given predicate
private:
//	vector<Variable *> variables; //should always be empty
	Term * source;
	Term * target;
	Word * link;
	Format outputForm;
	vector<Concept *> concepts;
	vector<Name *> names;
	vector<Point *> dependents; //list of dependent points
//	pair<const Term *, Part> sentenceParts; //assignment of sentence part to each term
//	void assign_parts(Predicate pred_in_parts); //fills sentenceParts according to given predicate
};

