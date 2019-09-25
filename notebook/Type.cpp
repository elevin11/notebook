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
