#pragma once
#include<vector>

#include "Note.h"
#include "Symbol.h"
#include "Type.h"

using namespace std;

/* Term is a symbol with an assigned type. 
*/

class Term :
	public Symbol
{
public:
	Term();	
	Term(Type type_in, string disp_in);
	~Term();
	Type type_check(); //returns the term's assigned type
protected:
	void set_type(Type type_in);
private:
	Type termType;  
};

/*	Variable is a placeholder term that represents a type in a format. 
	It can have identifiers, for when it is used to construct a compound term. 
*/
class Variable :
	public Term
{
public:
	Variable();
	Variable(Type type_in, string disp_in);
	~Variable();
private:
	Part identifier;
};


/*	Concept is a term with an associated note that gives its defintion.
*/
class Concept :
	public Term
{
public:
	Concept();
	~Concept();
	Concept(Note * definition_in);
private:
	const Note * definition;
};

/*	Name is a term which represents a reference to a specific data object.
	Named terms are kept track of by notes containing them.
	They can be linked to other terms
*/
class Name :
	public Term
{
public:
	Name();
	~Name();
	Name(Term abstract_in); //initializes references to contain abstract
	void add_term_reference(Term add_in); //name refers to additional term
	void remove_term_reference(int remove_in); //delete reference from list
private:
	Term abstract; //reference to abstract term of which name is concrete instance
	vector<Term *> references; //list of terms that name refers to
};