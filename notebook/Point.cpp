#include "Point.h"



Point::Point()
{
}


Point::~Point()
{
}

Point::Point(Term * source_in, Term * target_in, Word * link_in, Format form_in)
{
	source = source_in;
	target = target_in;
	link = link_in;
	outputForm = form_in;
}

void Point::show()
{
	outputForm.show();
}
