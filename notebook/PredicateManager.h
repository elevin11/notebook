#pragma once
#include "Manager.h"
#include "Predicate.h"
#include <string>
#include <vector>
using namespace std;

class PredicateManager :
	public Manager
{
public:
	PredicateManager();
	~PredicateManager();
	void create(string predName_in); //creates predicate with variables X and Y
	void create(string predName_in, Type type_in );
	void create(string predName_in, Type sourceType_in, Type targetType_in);
	void show();
private:
	vector<Predicate> predSet;
};

