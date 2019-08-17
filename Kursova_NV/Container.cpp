/* ************************************************************************** */
/*                                                                            */
/*   Container.cpp                                  :::::::::::     :::       */
/*                                                          :+:   :+:+:       */
/*                                                          +:+     +:+       */
/*   By: bdeomin <Bogdan Deomin>                          +#+       +#+       */
/*                                                      +#+         +#+       */
/*   Created: 2018/11/15 14:03:21 by bdeomin           #+#          #+#       */
/*   Updated: 2018/05/12 20:48:53 by bdeomin           #+#       ########.BS  */
/*                                                                            */
/* ************************************************************************** */

#include "Container.h"

Container::Container() : element(NULL) {}

// ----------------------------------------------------------------------------
// Функція для визначення кількості елементів у контейнері
int		Container::Len() const
{
	int len = 0;
	if (element)
	{
		List *temp = element;
		while (temp)
		{
			len++;
			temp = temp->next;
		}
	}
	return (len);
}

// ----------------------------------------------------------------------------
// Функція для порівняння дати двох культурних інститутів
int		Container::Check(const Cultural_institution* data1,
	const Cultural_institution* data2)
{
	if (data1->getYof() < data2->getYof())
		return (0);
	else if (data1->getYof() > data2->getYof())
		return (1);
	else
	{
		if (data1->give_mounth() < data2->give_mounth())
			return (0);
		else if (data1->give_mounth() > data2->give_mounth())
			return (1);
		else
		{
			if (data1->getDof() < data2->getDof())
				return (0);
			else
				return (1);
		}
	}
	return (1);
}

// ----------------------------------------------------------------------------
// Функція для додавання елементу в контейнер
void	Container::Add_elem(Cultural_institution *data)
{
	if (data->give_mounth() < 1 || data->give_mounth() > 12 ||
		data->getDof() < 1 || data->getDof() > 31 || data->getYof() < 1)
	{
		data->setYof(200000);	//перезапис данних для коректного відображення
		data->setDof(-1);
	}
	List *copy = element;
	List *temp = new List;
	temp->data = data;
	temp->next = NULL;
	if (element == NULL)
		element = temp;
	else
	{
		if (typeid(*data) == typeid(Cinema))
		{
			if ((typeid(*(element)->data) == typeid(Cinema)) && !Check(data,
				(element)->data))
			{
				element = temp;
				temp->next = copy;
				return;
			}
			while (element && typeid(*(element)->data) == typeid(Theater))
			{
				if (((element)->next) && (typeid(*(element)->next->data) ==
					typeid(Cinema)) && !Check(data, (element)->next->data))
				{
					List *next = (element)->next;
					(element)->next = temp;
					temp->next = next;
					element = copy;
					return;
				}
				else if (!(element)->next)
				{
					(element)->next = temp;
					element = copy;
					return;
				}
				element = (element)->next;
			}
			while ((element)->next && Check(data, (element)->next->data))
				element = (element)->next;
			List *next = (element)->next;
			(element)->next = temp;
			temp->next = next;
			element = copy;
		} // end of "if (typeid(*data) == typeid(Cinema))"
		else
		{
			if (typeid(*(element)->data) == typeid(Cinema) ||
				((typeid((element)->data) == typeid(Theater)) && !Check(data,
				(element)->data)))
			{
				element = temp;
				temp->next = copy;
			}
			else
			{
				while ((element)->next && Check(data, (element)->next->data) &&
					typeid(*(element)->next->data) == typeid(Theater))
					element = (element)->next;
				List *next = (element)->next;
				(element)->next = temp;
				temp->next = next;
				element = copy;
			}
		} // end of "else (typeid(*data) == typeid(Cinema))"
	}
}

// ----------------------------------------------------------------------------
// Група функцій для відображення контейнера у консолі (у вигляді таблиці)
void	print_symb(int n, const char *str)
{
	while (n-- > 0)
		cout << "\xC4";
	cout << str;
}

void	print_spase(int n, const char *str)
{
	while (n-- > 0)
		cout << " ";
	cout << str;
}

void	print_header(void)
{
	cout << "\xDA";
	print_symb(12, "\xC2");
	print_symb(40, "\xC2");
	print_symb(30, "\xC2");
	print_symb(27, "\xC2");
	print_symb(21, "\xC2");
	print_symb(32, "\xBF\n");
	cout << "\xB3   Object   \xB3" << setw(41) << right << "\xB3" << setw(31)
		<< right << "\xB3" << setw(28) << right <<"\xB3" << setw(22) << right
		<< "\xB3" << "        Object parametrs        \xB3" << endl;
	cout << "\xC3" ;
	print_symb(12, "\xB4");
	print_spase(40, "\xB3");
	print_spase(30, "\xB3");
	print_spase(27, "\xB3");
	print_spase(21, "\xC3");
	print_symb(15, "\xC2");
	print_symb(16, "\xB4\n");
	cout << "\xB3   Theater  \xB3                  Name                  \xB3"
		<< "           Country            \xB3           City            \xB3"
		<< "        Date         \xB3 Actors number \xB3 Balcons number \xB3" << endl;
	cout << "\xC3";
	print_symb(12, "\xB4");
	print_spase(40, "\xB3");
	print_spase(30, "\xB3");
	print_spase(27, "\xB3");
	print_spase(21, "\xC3");
	print_symb(7, "\xC2");
	print_symb(7, "\xC1");
	print_symb(2, "\xC2");
	print_symb(13, "\xB4\n");
	cout << "\xB3   Cinema   \xB3" << setw(41) << right << "\xB3" << setw(31)
		<< right << "\xB3" << setw(28) << right << "\xB3" << setw(22) << right
		<< "\xB3" << " Halls \xB3 3D Halls \xB3 D-BOX Halls \xB3" << endl;
}

void	print_for_Object(const char *s1, const char *s2, const char *s3,
	const char *s4)
{
	print_symb(7, s1);
	print_symb(7, s2);
	print_symb(2, s3);
	print_symb(13, s4);
}

void	print_bottom(List *previos)
{
	cout << "\xC0";
	print_symb(12, "\xC1");
	print_symb(40, "\xC1");
	print_symb(30, "\xC1");
	print_symb(27, "\xC1");
	print_symb(21, "\xC1");
	typeid(*(previos->data)) == typeid(Theater) ?
		print_for_Object("\xC4", "\xC1", "\xC4", "\xD9\n") :
		print_for_Object("\xC1", "\xC4", "\xC1", "\xD9\n");
}

void	print_all_string(List **copy, List *previous)
{
	cout << "\xC3";
	print_symb(12, "\xC5");
	print_symb(40, "\xC5");
	print_symb(30, "\xC5");
	print_symb(27, "\xC5");
	print_symb(21, "\xC5");
	if (*copy == previous)
		typeid(*((*copy)->data)) == typeid(Theater) ?
		print_for_Object("\xC1", "\xC2", "\xC1", "\xB4\n") :
		print_for_Object("\xC5", "\xC4", "\xC5", "\xB4\n");
	else
	{
		if (typeid(*((*copy)->data)) == typeid(Theater) &&
			typeid(*((previous)->data)) == typeid(Theater))
			print_for_Object("\xC4", "\xC5", "\xC4", "\xB4\n");
		else if (typeid(*((*copy)->data)) == typeid(Cinema) &&
			typeid(*((previous)->data)) == typeid(Cinema))
			print_for_Object("\xC5", "\xC4", "\xC5", "\xB4\n");
		else if (typeid(*((*copy)->data)) == typeid(Cinema) &&
			typeid(*((previous)->data)) == typeid(Theater))
			print_for_Object("\xC2", "\xC1", "\xC2", "\xB4\n");
	}
	(*copy)->data->show();
	*copy = (*copy)->next;
}

// ----------------------------------------------------------------------------
// Функція для відображення контейнера у консолі
void	Container::Print_container() const
{
	if (element)
	{
		print_header();
		List *previous = element;
		List *copy = element;
		print_all_string(&copy, previous);
		while (copy)
		{
			List *temp = copy;
			print_all_string(&copy, previous);
			previous = temp;
		}
		print_bottom(previous);
	}
	else
		cout << AC_YELLOW << "No items found" << AC_RESET << endl;
}

// ----------------------------------------------------------------------------
// Функція для видалення єлемента контейнера
void	Container::Delete_elem(Cultural_institution *data)
{
	if (element)
	{
		List *temp = new List;
		temp = NULL;
		List *copy = element;
		while (copy)
		{
			List *next = copy->next;
			if (copy->data == data)
			{
				if (temp)
					temp->next = next;
				else
					element = next;
				delete copy;
			}
			else
				temp = copy;
			copy = next;
		}
	}
	else
		cout << AC_YELLOW << "No items found for deletion" << AC_RESET << endl;

}

// ----------------------------------------------------------------------------
// Функція для видалення контейнера
void	Container::Delete_container()
{
	if (!(element))
		cout << AC_YELLOW << "No items found" << AC_RESET << endl;
	else
	{
		while (element)
		{
			List *temp;
			temp = (element)->next;
			(element)->next = NULL;
			delete element;
			element = temp;
		}
		cout << AC_GREEN << "Container removal successful" << AC_RESET << endl;
	}
}

// ----------------------------------------------------------------------------
// Функція для відображення запиту (найстаріший Театр)
void	Container::Show_oldest_theater()
{
	cout << "The search for the oldest theater is underway ..." << endl;
	if (element && typeid(*(element->data)) == typeid(Theater))
	{
		cout << AC_GREEN << "Successful search!" << AC_RESET << endl;
		cout << element->data->getName()
			<< " - theater, which has the oldest date of foundation" << endl;
	}
	else if (element && typeid(*(element->data)) == typeid(Cinema))
		cout << AC_RED << "Failed search!" << AC_RESET << endl << AC_YELLOW
			<< "No theaters found" << AC_RESET << endl;
	else
		cout << AC_RED << "Failed search!" << AC_RESET << endl << AC_YELLOW
			<< "No items found for show" << AC_RESET << endl;
}

// ----------------------------------------------------------------------------
// Функція для коректного вводу цілочислених даних користувачем
int		integer_input(const char *str, int switcher)
{
	int data;
	while (true)
	{
		cout << str;
		try
		{
			cin >> data;
			if (cin.fail() || cin.get() != '\n')
				throw "ERROR!";
			break;
		}
		catch (const char *str)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << AC_RED << str << AC_RESET << endl;
			cout << "Please input integer data" << endl;
			switcher == 1 ? cout << AC_MAGENTA : cout << AC_CYAN;
		}
	}
	return data;
}

// ----------------------------------------------------------------------------
// Функція для вводу данних про культурний інститут користувачем
void	Container::Input(Container Cont, int switcher)
{
	if (switcher == 1 || switcher == 2)
	{
		string	NAME;
		string	COUNTRY;
		string	CITY;
		int		DATE_OF_FOUNDATION;
		string	MOUNTH_OF_FOUNDATION;
		int		YEAR_OF_FOUNDATION;

		switcher == 1 ? cout << AC_MAGENTA : cout << AC_CYAN;
		cout << "Input Name of the ";
		switcher == 1 ? cout << "Theater: " : cout << "Cinema: ";
		getline(cin, NAME, '\n');
		cout << "Input Country: ";
		getline(cin, COUNTRY, '\n');
		cout << "Input City: ";
		getline(cin, CITY, '\n');
		DATE_OF_FOUNDATION = integer_input("Input Date of foundation: ",
			switcher);
		cout << "Input Mounth of foundation: ";
		getline(cin, MOUNTH_OF_FOUNDATION, '\n');
		YEAR_OF_FOUNDATION = integer_input("Input Year of foundation: ",
			switcher);

		if (switcher == 1)
		{
			int		ACTORS_NUMBER;
			int		BALCON;
			ACTORS_NUMBER = integer_input("Input How Actors in the Theater: ",
				switcher);
			BALCON = integer_input("Input How Balcon in the Theater: ",
				switcher);
			Cultural_institution *object = new Theater(NAME, COUNTRY, CITY, DATE_OF_FOUNDATION, MOUNTH_OF_FOUNDATION, YEAR_OF_FOUNDATION, ACTORS_NUMBER, BALCON);
			Cont.Add_elem(object);
		}
		else if (switcher == 2)
		{
			int		HALL_NUMBER;
			int		HALL_3D;
			int		HALL_D_BOX;
			HALL_NUMBER = integer_input("Input How many Hall in the Cinema: ",
				switcher);
			HALL_3D = integer_input("Input How many 3d Hall in the Cinema: ",
				switcher);
			HALL_D_BOX = integer_input("Input How many D-BOX Hall in the Cinema: ",
				switcher);
			Cultural_institution *object = new Cinema(NAME, COUNTRY, CITY, DATE_OF_FOUNDATION, MOUNTH_OF_FOUNDATION, YEAR_OF_FOUNDATION, HALL_NUMBER, HALL_3D, HALL_D_BOX);
			Cont.Add_elem(object);
		}
		cout << AC_RESET;
		*this = Cont;
	}
}

// ----------------------------------------------------------------------------
// Перевантаження оператора << для запису у файл
ofstream& operator << (ofstream& out, List* head)
{
	while (head)
	{
		head->data->returned(out, head->data);
		head = head->next;
	}
	return out;
}

// ----------------------------------------------------------------------------
// Функція для запису контейнера у файл (серіалізація)
void	Container::write_in_file() const
{
	if (element == NULL)
	{
		cout << AC_YELLOW << "No items found." << AC_RESET << endl;
		return;
	}
	ofstream out("Cultur_institution.txt");
	if (!out.is_open())
	{
		cout << AC_RED << "Error opening file!" << AC_RESET << endl;
		return;
	}
	out << element;
	out.close();
	cout << AC_GREEN << "Successful saving to file" << AC_RESET << endl;
}

// ----------------------------------------------------------------------------
// Перевантаження оператора << для запису у файл
Cultural_institution &operator>>(ifstream& in, Cultural_institution	&object)
{
	object.input(in, &object);
	return (object);
}

// ----------------------------------------------------------------------------
// Функція для зчитки елементів контейнера з файлу (десеріалізація)
int		Container::put_out_file(Container Cont)
{
	ifstream in;
	in.open("Cultur_institution.txt");
	if (!in.is_open())
	{
		cout << "Error opening file!" << endl;
		return (0);
	}

	int k;
	int count = 0;
	while (in >> k)
	{
		string trash;
		getline(in, trash);
		if (k == 1)
		{
			Cultural_institution	*T = new Theater;
			in >> *T;
			Cont.Add_elem(T);
			count++;
		}
		else if (k == 2)
		{
			Cultural_institution	*C = new Cinema;
			in >> *C;
			Cont.Add_elem(C);
			count++;
		}
	}
	*this = Cont;
	return (count);
}

Container::~Container() {};
