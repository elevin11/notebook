#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*	Grammatical classification of a symbol or block of symbols
*/

class Type
{
public:
	Type();
	~Type();
	Type(string typeName_in);
	bool operator == (Type const &comp); //check if two types are equal
	string get_string();
private:
	int degree;
	string typeName;
	string description;
	Type * parent; //link to parent if subtype
};

