/* ************************************************************************** */
/*                                                                            */
/*   Theater.cpp                                    :::::::::::     :::       */
/*                                                          :+:   :+:+:       */
/*                                                          +:+     +:+       */
/*   By: bdeomin <Bogdan Deomin>                          +#+       +#+       */
/*                                                      +#+         +#+       */
/*   Created: 2018/11/15 14:03:21 by bdeomin           #+#          #+#       */
/*   Updated: 2018/05/12 20:50:59 by bdeomin           #+#       ########.BS  */
/*                                                                            */
/* ************************************************************************** */

#include "Theater.h"
using namespace std;

// ----------------------------------------------------------------------------
Theater::Theater(string _name, string _country, string _city,
	int _date_of_foundation, string _month_of_foundation,
	int _year_of_foundation, int _actors_number, int _balcon) :
	Cultural_institution(_name, _country, _city, _date_of_foundation,
		_month_of_foundation, _year_of_foundation),
	actors_number(_actors_number), balcon(_balcon) {}
Theater::Theater() : Cultural_institution(), actors_number(0), balcon(0) {}

// ----------------------------------------------------------------------------
void			Theater::setActors_number(const int _actors_number) 
	{ actors_number = _actors_number; }
int				Theater::getActors_number(void) const
{ return(actors_number); }

// ----------------------------------------------------------------------------
void			Theater::setBalcon(const int _balcon) { balcon = _balcon; }
int				Theater::getBalcon(void) const { return(balcon); }

// ----------------------------------------------------------------------------
// Віртуальна функція для відображення данних про культурну установу
void			Theater::show() const
{
	cout << "\xB3   Theater  ";
	Cultural_institution::show();
	cout << " \xB3 " << setw(8) << right << actors_number << setw(5) << "" 
		<<	" \xB3 " << setw(7) << right << balcon << setw(7) << "" << " \xB3"
		<< endl;
}

// ----------------------------------------------------------------------------
// Перевантаження оператора << для запису у файл
ofstream& operator << (ofstream& out, const Theater *data)
{
	out << data->getActors_number() << endl;
	out << data->getBalcon() << endl;

	return (out);
}

// ----------------------------------------------------------------------------
// Віртуальна функція для запису данних у файл
ofstream&		Theater::returned(ofstream& out, const Cultural_institution *data) const
{
	out << 1 << endl;
	Cultural_institution::returned(out, data);
	out << (Theater *)data;
	return (out);
}

// ----------------------------------------------------------------------------
// Перевантаження оператора >> для зчитки з файлу
Cultural_institution &operator >> (ifstream& in, Theater *object) 
{
	int _actors_number;
	int	_balcon;

	in >> _actors_number;
	in >> _balcon;
	object->setActors_number(_actors_number);
	object->setBalcon(_balcon);

	return (*object);
}

// ----------------------------------------------------------------------------
// Віртуальна функція для зчитки данних з файлу
Cultural_institution &Theater::input(ifstream& in,
	Cultural_institution *object) const
{
	Cultural_institution::input(in, object);
	in >> (Theater *)object;
	return (*object);
}


Theater::~Theater() {}