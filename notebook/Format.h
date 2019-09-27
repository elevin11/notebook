#pragma once
#include <vector>

#include "Symbol.h"
#include "Term.h"
using namespace std;

/*	String of symbols representing data.
	Symbols must satisfy certain conditions.
*/

class Format
{
public:
	Format();
	Format(const Format&);
	~Format();
	void show();
	void add_word(Word * word_in); //add a word symbol to list
	void add_variable(Variable * var_in); //add a variable symbol to list	
//	void add_format(Format format_in); //adds another format to list
	Bracket * enclose(); //inserts bracket pair in first, last entries of list
	void substitute(Variable * var_sub, Term * term_sub);	//returns format after substituting a term for a variable
private:
	vector<Symbol *> symbols;
	vector<Variable *> variables;
};


/*
class Predicate
	: public Format
{
public:
	Predicate();
	~Predicate();
	void mark_variable(Variable mark_var_in, Part mark_in); //marks a variable with given part
	Predicate substitute(Variable &sub_var_in, Term sub_term_in); //substitues term for given variable
	Predicate compose(Variable &sub_var_in_pred, Predicate sub_pred_in); //substitutes predicate for given variable
	Predicate substitute(vector<Term> input); //substitutes terms in input list for all variables of matching type
private:
	Type predicateType; 
	vector<Type> typeSig;
	bool typeSigCheck(vector<Term> inputCheck); //checks if given list of terms matches type with predicate's signature 
};

*/