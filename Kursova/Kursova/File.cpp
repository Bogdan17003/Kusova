#include "File.h"

File::File() {}

void	File::write_in_file(List *head)
{
	if (head == NULL)
	{
		printf("Conteiner free");
		return;
	}
	ofstream out("Cultur_institution.dat");
	if (!out.is_open())
	{
		cout << "Error opening file!" << endl;
		return;
	}
	while (head)
	{
		if (typeid (*(head->data)) == typeid(Theater))
		{
			out << 1 << ' ';
			out << (Theater *)(head->data) ;
		}
		else
		{
			out << 2 << ' ';
			out << (Cinema *)(head->data);
		}
		head = head->next;
	}
	out.close();
}

int		File::put_out_file(List **head, Container *Cont)
{
	ifstream in;
	in.open("Cultur_institution.dat");
	if (!in.is_open())
	{
		cout << "Error opening file!" << endl;
		return (0);
	}

	Theater	*T;
	Cinema	*C;
	int k;
	int count = 0;
	while (!in.eof())
	{
		in >> k;
		if (k == 1)
		{
			T = new Theater;
			in >> *T;
			Cont->Add_elem(head, T);
			count++;
		}
		else if (k == 2)
		{
			C = new Cinema;
			in >> *C;
			Cont->Add_elem(head, C);
			count++;
		}
	}
	return (count);
}

File::~File() {}
