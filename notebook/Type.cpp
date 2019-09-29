#include "Type.h"



Type::Type()
{
	parent = nullptr;
}


Type::~Type()
{
}

Type::Type(string typeName_in)
{
	typeName = typeName_in;
	parent = nullptr;
}

bool Type::operator==(Type const & comp)
{
	if (comp.typeName == typeName)
	{
		return true;
	}
	return false;
}

string Type::get_string()
{
	return typeName;
}
