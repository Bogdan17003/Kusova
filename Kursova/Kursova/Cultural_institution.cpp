#include "Cultural_institution.h"

Date::Date(int _date_of_foundation, string _month_of_foundation, int _year_of_foundation) : date_of_foundation(_date_of_foundation), month_of_foundation(_month_of_foundation), year_of_foundation(_year_of_foundation) {}

Cultural_institution::Cultural_institution(string _name, string _country, string _city, int _date_of_foundation, string _month_of_foundation, int _year_of_foundation) :
	name(_name), country(_country), city(_city), date(_date_of_foundation, _month_of_foundation, _year_of_foundation) { }


Cultural_institution::Cultural_institution() : name(nullptr), country(nullptr), city(nullptr), date(0, nullptr, 0) {}

const string	Cultural_institution::getName(void) const { return(name); }
void			Cultural_institution::setName(string _name) { name = _name; }

const string	Cultural_institution::getCountry(void) const { return(country); }
void			Cultural_institution::setCountry(string _country) { country = _country; }

const string	Cultural_institution::getCity(void) const { return(city); }
void			Cultural_institution::setCity(string _city) { city = _city; }

const int		Cultural_institution::getDof(void) const { return(date.date_of_foundation); }
void			Cultural_institution::setDof(int _date_of_foundation) {date.date_of_foundation = _date_of_foundation; }

const string	Cultural_institution::getMof(void) const { return(date.month_of_foundation); }
void			Cultural_institution::setMof(string _month_of_foundation) {	date.month_of_foundation = _month_of_foundation; }

const int		Cultural_institution::getYof(void) const { return(date.year_of_foundation); }
void			Cultural_institution::setYof(int _year_of_foundation) {	date.year_of_foundation = _year_of_foundation; }

void			whitespace(int month)
{
	switch (month)
	{
	case 2:
	case 11:
	case 12:
		printf(" ");
		break;
	case 1:
	case 10:
		printf("  ");
		break;
	case 8:
		printf("   ");
		break;
	case 3:
	case 4:
		printf("    ");
		break;
	case 6:
	case 7:
		printf("     ");
		break;
	case 5:
		printf("      ");
		break;
	default:
		break;
	}
}

void			Cultural_institution::show_data(void) const
{
	int numb = 0;
	int month = give_mounth();
	if (month > 12 || month < 1 || date.date_of_foundation == -1)
	{
		printf(" Date not detected ");
		return;
	}
	if (numb = atoi(date.month_of_foundation.c_str()))
	{
		date.date_of_foundation >= 1 && date.date_of_foundation <= 9 ? printf("       0") : printf("       ");
		printf("%d.", date.date_of_foundation);
		numb >= 1 && numb <= 9 ? printf("0") : printf("");
		printf("%d.%6d", numb, date.year_of_foundation);
	}
	else
	{
		whitespace(month);
		date.date_of_foundation >= 1 && date.date_of_foundation <= 9 ? printf("0") : printf("");
		printf("%d ", date.date_of_foundation);
		switch (month)
		{
		case 1:
			printf("January");
			break;
		case 2:
			printf("February");
			break;
		case 3:
			printf("March");
			break;
		case 4:
			printf("April");
			break;
		case 5:
			printf("May");
			break;
		case 6:
			printf("June");
			break;
		case 7:
			printf("July");
			break;
		case 8:
			printf("August");
			break;
		case 9:
			printf("September");
			break;
		case 10:
			printf("October");
			break;
		case 11:
			printf("November");
			break;
		case 12:
			printf("December");
			break;
		default:
			break;
		}
		printf(" %6d", date.year_of_foundation);
	}
}

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
			}
			break;
			default:
				break;
			}
		}
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
		}
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
		}
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
		}
	}
	return (numb);
}

void			Cultural_institution::show(void) const
{
	printf("\xB3 %38s \xB3 %28s \xB3 %23s \xB3 ", name.c_str(), country.c_str(), city.c_str());
	show_data();
}


ofstream& operator << (ofstream& ofs, Cultural_institution &object)
{
	ofs << object.name << object.city << object.country << object.date.date_of_foundation << object.date.month_of_foundation << object.date.year_of_foundation;
	return ofs;
}

ifstream& operator >> (ifstream& ifs, Cultural_institution &object)
{
	ifs >> object.name >> object.city >> object.country >> object.date.date_of_foundation >> object.date.month_of_foundation >> object.date.year_of_foundation;
	return ifs;
}

Cultural_institution::~Cultural_institution(void) {}