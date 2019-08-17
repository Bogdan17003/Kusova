/* ************************************************************************** */
/*                                                                            */
/*   Cinema.cpp                                     :::::::::::     :::       */
/*                                                          :+:   :+:+:       */
/*                                                          +:+     +:+       */
/*   By: bdeomin <Bogdan Deomin>                          +#+       +#+       */
/*                                                      +#+         +#+       */
/*   Created: 2018/11/15 14:03:21 by bdeomin           #+#          #+#       */
/*   Updated: 2018/05/12 20:50:08 by bdeomin           #+#       ########.BS  */
/*                                                                            */
/* ************************************************************************** */

#include "Cinema.h"

// ----------------------------------------------------------------------------
Cinema::Cinema(string _name, string _country, string _city,
	int _date_of_foundation, string _month_of_foundation,
	int _year_of_foundation, int _hall_number, int _hall_3D, int _hall_D_BOX) :
	Cultural_institution(_name, _country, _city, _date_of_foundation,
		_month_of_foundation, _year_of_foundation), hall_number(_hall_number),
	hall_3D(_hall_3D), hall_D_BOX(_hall_D_BOX) {}
Cinema::Cinema() : Cultural_institution(), hall_number(0), hall_3D(0),
	hall_D_BOX(0) {}

// ----------------------------------------------------------------------------
void			Cinema::setHall_number(const int _hall_number)
	{ hall_number = _hall_number; }
int				Cinema::getHall_number(void) const { return(hall_number); }

// ----------------------------------------------------------------------------
void			Cinema::setHall_3D(const int _hall_3D) { hall_3D = _hall_3D; }
int				Cinema::getHall_3D(void) const { return(hall_3D); }

// ----------------------------------------------------------------------------
void			Cinema::setHall_D_BOX(const int _hall_D_BOX)
	{ hall_D_BOX = _hall_D_BOX; }
int				Cinema::getHall_D_BOX(void) const { return(hall_D_BOX); }

// ----------------------------------------------------------------------------
// Віртуальна функція для відображення данних про культурну установу
void			Cinema::show() const
{
	cout << "\xB3   Cinema   ";
	Cultural_institution::show();
	cout << " \xB3 " << setw(4) << right << hall_number << setw(1) << "" 
		<< " \xB3 " << setw(5) << right	<< hall_3D << setw(3) << "" << " \xB3 "
		<< setw(6) << right << hall_D_BOX << setw(5) << "" << " \xB3" << endl;
}

// ----------------------------------------------------------------------------
// Перевантаження оператора << для запису у файл
ofstream& operator << (ofstream& out, const Cinema *data)
{
	out << data->getHall_number() << endl;
	out << data->getHall_3D() << endl;
	out << data->getHall_D_BOX() << endl;

	return (out);
}

// ----------------------------------------------------------------------------
// Віртуальна функція для запису данних у файл
ofstream&		Cinema::returned(ofstream& out, const Cultural_institution *data) const
{
	out << 2 << endl;
	Cultural_institution::returned(out, data);
	out << (Cinema *)data;
	return (out);
}

// ----------------------------------------------------------------------------
// Перевантаження оператора >> для зчитки з файлу
Cultural_institution &operator >> (ifstream& in, Cinema *object)
{
	int _hall_number;
	int _hall_3D;
	int _hall_D_BOX;
	in >> _hall_number;
	in >> _hall_3D;
	in >> _hall_D_BOX;
	object->setHall_number(_hall_number);
	object->setHall_3D(_hall_3D);
	object->setHall_D_BOX(_hall_D_BOX);

	return (*object);
}

// ----------------------------------------------------------------------------
// Віртуальна функція для зчитки данних з файлу
Cultural_institution &Cinema::input(ifstream& in,
	Cultural_institution *object) const
{
	Cultural_institution::input(in, object);
	in >> (Cinema *)object;
	return (*object);
}

Cinema::~Cinema() {}