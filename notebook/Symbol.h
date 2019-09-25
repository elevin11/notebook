#pragma once
#include<string>
#include<vector>
using namespace std;


/*	Basic unit of data in program.
	List of these satisfying various conditions makes a Format.
*/


//String of text that corresponds to some data object
class Symbol
{
public:
	Symbol();
	Symbol(string display_in); //construct with given string as output text
	~Symbol();
	string get_display(); //get output text
	void set_display(string display_new); //change output text
private:
	string display;	//text representation to display in console
};




//English word, or sequence of words. Has limited formatting capabilities.
class Word :
	public Symbol
{
public:
	Word();
	Word(string display_in);
	~Word();
	string get_display_cap(); //display word capitalized
	string get_display_space(); //display word with space following it
	string get_synonym(); //return an equivalent word
	void add_synonym(string synonym_in); //add word to list 'synonyms'
	void set_to_synonym(int choice); //set to one of the words in 'synonyms', user inputs entry from list
private:
	vector<string> synonyms; //list of equivalent words
};

//Either left [ or right ] bracket. Encloses predicate.
class Bracket :
	public Symbol
{
public:
	Bracket(); //constructor must set display to '[' or ']'
	Bracket(char leftOrRight_in); //construct left or right bracket - returns error if other character given
	Bracket(Bracket * twin_in); //construct as part of pair
	~Bracket();
private:
	Bracket * twin; //other bracket in part
	bool right; //0 if left bracket [, and 1 if right bracket ]
};

//Marks the grammatical parts of a sentence, such as subject or function arguments.
class Part :
	public Symbol
{
public:
	Part();
	~Part();
	Part(int part_in);
	int get_part_value(); 
private:
	int partSignature; //change to enum later on
};

