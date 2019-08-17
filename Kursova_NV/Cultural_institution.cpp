/* ************************************************************************** */
/*                                                                            */
/*   Cultural_institution.cpp                       :::::::::::     :::       */
/*                                                          :+:   :+:+:       */
/*                                                          +:+     +:+       */
/*   By: bdeomin <Bogdan Deomin>                          +#+       +#+       */
/*                                                      +#+         +#+       */
/*   Created: 2018/11/15 14:03:21 by bdeomin           #+#          #+#       */
/*   Updated: 2018/05/12 20:52:11 by bdeomin           #+#       ########.BS  */
/*                                                                            */
/* ************************************************************************** */

#include "Cultural_institution.h"
// ---------------------------------------------------------------------------- 
Date::Date(int _date_of_foundation, string _month_of_foundation,
	int _year_of_foundation) : date_of_foundation(_date_of_foundation),
	month_of_foundation(_month_of_foundation),
	year_of_foundation(_year_of_foundation) {}
Date::Date() : date_of_foundation(0), month_of_foundation("\0"),
	year_of_foundation(0) {}

// ----------------------------------------------------------------------------
Cultural_institution::Cultural_institution(string _name, string _country,
	string _city, int _date_of_foundation, string _month_of_foundation,
	int _year_of_foundation) : name(_name), country(_country), city(_city),
	date(_date_of_foundation, _month_of_foundation, _year_of_foundation) {}
Cultural_institution::Cultural_institution() : name("\0"), country("\0"),
	city("\0"), date() {}

// ----------------------------------------------------------------------------
const string	Cultural_institution::getName(void) const { return(name); }
void			Cultural_institution::setName(const string _name) { name = _name; }

// ----------------------------------------------------------------------------
const string	Cultural_institution::getCountry(void) const { return(country); }
void			Cultural_institution::setCountry(const string _country)
	{ country = _country; }

// ----------------------------------------------------------------------------
const string	Cultural_institution::getCity(void) const { return(city); }
void			Cultural_institution::setCity(const string _city) { city = _city; }

// ----------------------------------------------------------------------------
const int		Cultural_institution::getDof(void) const 
	{ return(date.date_of_foundation); }
void			Cultural_institution::setDof(const int _date_of_foundation)
	{ date.date_of_foundation = _date_of_foundation; }

// ----------------------------------------------------------------------------
const string	Cultural_institution::getMof(void) const
	{ return(date.month_of_foundation); }
void			Cultural_institution::setMof(const string _month_of_foundation)
	{ date.month_of_foundation = _month_of_foundation; }

// ----------------------------------------------------------------------------
const int		Cultural_institution::getYof(void) const
	{ return(date.year_of_foundation); }
void			Cultural_institution::setYof(const int _year_of_foundation)
	{ date.year_of_foundation = _year_of_foundation; }

// ----------------------------------------------------------------------------
// Функція визначає кількість пропусків яку потрібно відобразити
void			whitespace(const int month)
{
	switch (month)
	{
	case 2:
	case 11:
	case 12:
		cout << " ";
		break;
	case 1:
	case 10:
		cout << "  ";
		break;
	case 8:
		cout << "   ";
		break;
	case 3:
	case 4:
		cout << "    ";
		break;
	case 6:
	case 7:
		cout << "     ";
		break;
	case 5:
		cout << "      ";
		break;
	default:
		break;
	}
}

// ----------------------------------------------------------------------------
// Функція відображає дату створення культурної установи(Театр, Кінотеатр)
void			Cultural_institution::show_data(void) const
{
	int numb = 0;
	int month = give_mounth();
	if (month > 12 || month < 1 || date.date_of_foundation == -1)
	{
		cout << " Date not detected ";
		return;
	}
	if (numb = atoi(date.month_of_foundation.c_str()))	// відображення відносно вхідних данних
	{
		date.date_of_foundation >= 1 && date.date_of_foundation <= 9 ? 
			cout << setw(6) << right << "0" : cout << setw(5) << "";
		cout << date.date_of_foundation << ".";
		numb >= 1 && numb <= 9 ? cout << "0" : cout << "";
		cout << numb << "." << setw(8) << left << date.year_of_foundation ;
	}
	else
	{
		whitespace(month);
		date.date_of_foundation >= 1 && date.date_of_foundation <= 9 ?
			cout << "0" : cout << "";
		cout << date.date_of_foundation << " ";
		switch (month)
		{
		case 1:
			cout << "January";
			break;
		case 2:
			cout << "February";
			break;
		case 3:
			cout << "March";
			break;
		case 4:
			cout << "April";
			break;
		case 5:
			cout << "May";
			break;
		case 6:
			cout << "June";
			break;
		case 7:
			printf("July");
			break;
		case 8:
			cout << "August";
			break;
		case 9:
			cout << "September";
			break;
		case 10:
			cout << "October";
			break;
		case 11:
			cout << "November";
			break;
		case 12:
			cout << "December";
			break;
		default:
			break;
		}
		cout << " " << setw(6) << left << date.year_of_foundation;
	}
}

// ----------------------------------------------------------------------------
// Функція визначає номер місяця 
const int		Cultural_institution::give_mounth(void) const
{
	int numb = 0;
	if (numb = atoi(date.month_of_foundation.c_str()))
		return (numb);
	else
	{
		char f;
		f = date.month_of_foundation.c_str()[0];
		switch (f)
		{
		case 'J':
		case 'j':
		{
			char s;

			s = date.month_of_foundation.c_str()[1];
			switch (s)
			{
			case 'A':
			case 'a':
				numb = 1;
				break;
			case 'U':
			case 'u':
			{
				char t;

				t = date.month_of_foundation.c_str()[2];
				switch (t)
				{
				case 'N':
				case 'n':
					numb = 6;
					break;
				case 'L':
				case 'l':
					numb = 7;
					break;
				default:
					break;
				}
			} // end of "case 'U'" і "case 'u':"
			break;
			default:
				break;
			}
		} // end of "case 'J'" і "case 'j':"
		break;
		case 'F':
		case 'f':
			numb = 2;
			break;
		case 'M':
		case 'm':
		{
			char t;

			t = date.month_of_foundation.c_str()[2];
			switch (t)
			{
			case 'R':
			case 'r':
				numb = 3;
				break;
			case 'Y':
			case 'y':
				numb = 5;
				break;
			default:
				break;
			}
		} // end of "case 'M'" і "case 'm':"
		break;
		case 'A':
		case 'a':
		{
			char s;

			s = date.month_of_foundation.c_str()[1];
			switch (s)
			{
			case 'P':
			case 'p':
				numb = 4;
				break;
			case 'U':
			case 'u':
				numb = 8;
				break;
			default:
				break;
			}
		} // end of "case 'A'" і "case 'a':"
		break;
		case 'S':
		case 's':
			numb = 9;
			break;
		case 'O':
		case 'o':
			numb = 10;
			break;
		case 'N':
		case 'n':
			numb = 11;
			break;
		case 'D':
		case 'd':
			numb = 12;
			break;
		default:
			break;
		} // end of "switch (f)"
	}
	return (numb);
}

// ----------------------------------------------------------------------------
// Віртуальна функція для відображення данних про культурну установу
void			Cultural_institution::show(void) const
{
	cout << left << "\xB3 " << setw(38) << name << " \xB3 " << setw(28) << country << " \xB3 " << setw(25) << city << " \xB3 ";
	show_data();
}

// ----------------------------------------------------------------------------
// Перевантаження оператора << для запису у файл
ofstream& operator << (ofstream& out, const Cultural_institution *data)
{
	out << data->getName() << endl;
	out << data->getCountry() << endl;
	out << data->getCity() << endl;
	out << data->getDof() << endl;
	out << data->getMof() << endl;
	out << data->getYof() << endl;

	return (out);
}

// ----------------------------------------------------------------------------
// Віртуальна функція для запису данних у файл
ofstream&		Cultural_institution::returned(ofstream& out,
	const Cultural_institution *data) const
{
	out << data;
	return (out);
}

// ----------------------------------------------------------------------------
// Віртуальна функція для зчитки данних з файлу
Cultural_institution&		Cultural_institution::input(ifstream& in,
	Cultural_institution *object) const
{
	string _name;
	string _country;
	string _city;
	int _date_of_foundation;
	string _mounth_of_foundation;
	int _year_of_foundation;

	string trash;
	getline(in, _name);
	getline(in, _country);
	getline(in, _city);
	in >> _date_of_foundation;
	getline(in, trash);
	getline(in, _mounth_of_foundation);
	in >> _year_of_foundation;

	*object = Cultural_institution(_name, _country, _city, _date_of_foundation,
		_mounth_of_foundation, _year_of_foundation);
	return (*object);
}

Cultural_institution::~Cultural_institution(void) {}