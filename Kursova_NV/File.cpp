#include "File.h"

File::File() {}
/*
fstream& operator << (fstream& fs, List* head)
{
	while (head)
	{
		head->data->returned(fs, head->data);
		head = head->next;	
	}
	return fs;
}

void	File::write_in_file(List *head)
{
	if (head == NULL)
	{
		cout << "No items found." << endl;
		return;
	}
	fstream out("Cultur_institution.dat");
	if (!out.is_open())
	{
		cout << "Error opening file!" << endl;
		return;
	}
	out << head;
	out.close();
}

Cultural_institution &operator>>(fstream& in, Cultural_institution	&object)
{
	object.input(in, &object);
	return (object);
}

int		File::put_out_file(List **head, Container *Cont)
{
	fstream in;
	in.open("Cultur_institution.dat");
	if (!in.is_open())
	{
		cout << "Error opening file!" << endl;
		return (0);
	}

	int k;
	int count = 0;
	while (in >> k)
	{
		if (k == 1)
		{
			Cultural_institution	*T = new Theater;
			in >> *T;
			Cont->Add_elem(head, T);
			count++;
		}
		else if (k == 2)
		{
			Cultural_institution	*C = new Cinema;
			in >> *C;
			Cont->Add_elem(head, C);
			count++;
		}
	}
	return (count);
}
*/
File::~File() {}
