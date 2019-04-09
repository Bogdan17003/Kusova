#include "Theater.h"
using namespace std;

Theater::Theater(string _name, string _country, string _city, int _date_of_foundation, string _month_of_foundation, int _year_of_foundation, int _actors_number, int _balcon):
	Cultural_institution(_name, _country, _city, _date_of_foundation, _month_of_foundation, _year_of_foundation),
	actors_number(_actors_number), balcon(_balcon) {}

Theater::Theater() : actors_number(0), balcon(0) {}

void			Theater::setActors_number(int _actors_number) { actors_number = _actors_number; }
int				Theater::getActors_number(void) const { return(actors_number); }

void			Theater::setBalcon(bool _balcon) { balcon = _balcon; }
int				Theater::getBalcon(void) const { return(balcon); }


ofstream& operator << (ofstream& ofs, Theater &object)
{
	ofs << object.name << object.city << object.country << object.date.date_of_foundation << object.date.month_of_foundation << object.date.year_of_foundation << object.actors_number << object.balcon;
	return ofs;
}

ifstream& operator >> (ifstream& ifs, Theater &object)
{
	ifs >> object.name >> object.city >> object.country >> object.date.date_of_foundation >> object.date.month_of_foundation >> object.date.year_of_foundation >> object.actors_number >> object.balcon;
	return ifs;
}

void			Theater::show() const
{
	printf("\xB3   Theater  ");
	Cultural_institution::show();
	printf(" \xB3 %13d \xB3 %14d \xB3\n", actors_number, balcon);
}

Theater::~Theater() {}