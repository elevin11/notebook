#include "pch.h"
#include "Note.h"
#include "Utility.h"


Note::Note()
{
}

Note::Note(string label_in)
{
	label = label_in;
	string filename = Utility::file_extend(label);
	ifstream text_in(filename);

	if (text_in.is_open())
	{
		string input_line;
		while (getline(text_in, input_line))
		{
			text.append(input_line);
		}
	}
	else
	{
		cout << "Could not find " << filename << endl << endl;
	}
}

Note::Note(string label_in, string text_in)
{
	label = label_in;
	text = text_in;
}

void Note::display()
{
	cout << label << endl;
	cout << '\t' << text << endl;
	cout << endl;
}

void Note::set_text(string newText)
{
	text = newText;
	return;
}

int Note::save()
{
	string filename = Utility::file_extend(label);

	ifstream checkfile(filename);
	bool overwrite = true;

	if (checkfile.is_open())
	{
		cout << "Overwrite " << filename << "? (Y/N)" << endl;
		string check;
		getline(cin, check);
		if (check == "Y" || check == "y")
		{
			overwrite = true;
		}
		else if (check == "N" || check == "n")
		{
			overwrite = false;
		}
	}

	if (overwrite)
	{
		ofstream writefile(filename);
		if (writefile.is_open())
		{
			writefile << text;
			return 1;
		}
		else
		{
			cout << "Could not write to " << filename << endl << endl;
			return 0;
		}
	}
	return 0;
}

Note::~Note()
{
}
