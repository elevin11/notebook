#pragma once
#include <string>
using namespace std;

class Manager
{
public:
	Manager();
	void create();
	void create(string);
	void view(string);
	void edit(string);
	void show();
	void destroy(string);
	~Manager();
};

