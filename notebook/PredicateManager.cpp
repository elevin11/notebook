#include "PredicateManager.h"



PredicateManager::PredicateManager()
{
}


PredicateManager::~PredicateManager()
{
}

void PredicateManager::create(string predName_in)
{
	Type noType("null");
	Variable addSource(noType, "S");
	Variable addTarget(noType, "T");
	Predicate addPred(predName_in, addSource, addTarget);
	predSet.push_back(addPred);
}

void PredicateManager::create(string predName_in, Type type_in)
{
	Variable addSource(type_in, "S");
	Variable addTarget(type_in, "T");
	Predicate addPred(predName_in, addSource, addTarget);
	predSet.push_back(addPred);
}

void PredicateManager::create(string predName_in, Type sourceType_in, Type targetType_in)
{
	Variable addSource(sourceType_in, "S");
	Variable addTarget(targetType_in, "T");
	Predicate addPred(predName_in, addSource, addTarget);
	predSet.push_back(addPred);
}


void PredicateManager::show()
{
	for (auto it = predSet.begin(); it != predSet.end(); ++it)
	{
		it->show();
		cout << endl;
	}
}
