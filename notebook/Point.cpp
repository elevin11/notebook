#include "Point.h"



Point::Point()
{
}


Point::~Point()
{
}

Point::Point(Term  &source_in, Term &target_in, Word &link_in, Format &form_in)
{
	source = source_in;
	target = target_in;
	link = link_in;
	outputForm = form_in;
//	string disp = "[ " + link_in->get_display() + " : " + source_in->get_display() + " -> " + target_in->get_display() + " ]";
	string disp = outputForm.get_string();
	set_display(disp);
}

void Point::show()
{
	outputForm.show();
}

void Point::info()
{
	cout << &source << endl;
	cout << source.get_display() << endl;

	cout << &target << endl;
	cout << target.get_display() << endl;
}
