#include "Cinema.h"

Cinema:: Cinema(string _name, string _country, string _city, int _date_of_foundation, string _month_of_foundation, int _year_of_foundation, int _hall_number, int _hall_3D, int _hall_D_BOX):
	Cultural_institution(_name, _country, _city, _date_of_foundation, _month_of_foundation, _year_of_foundation), 
	hall_number(_hall_number), hall_3D(_hall_3D), hall_D_BOX(_hall_D_BOX) {}

Cinema:: Cinema() : hall_number(0), hall_3D(0), hall_D_BOX(0) {}

void			Cinema::setHall_number(int _hall_number) { hall_number = _hall_number; }
int				Cinema::getHall_number(void) const { return(hall_number); }

void			Cinema::setHall_3D(int _hall_3D) { hall_3D = _hall_3D; }
int				Cinema::getHall_3D(void) const { return(hall_3D); }

void			Cinema::setHall_D_BOX(int _hall_D_BOX) { hall_D_BOX = _hall_D_BOX; }
int				Cinema::getHall_D_BOX(void) const { return(hall_D_BOX); }

ofstream& operator << (ofstream& ofs, Cinema &object)
{
	ofs << object.name << object.city << object.country << object.date.date_of_foundation << object.date.month_of_foundation << object.date.year_of_foundation << object.hall_number << object.hall_3D << object.hall_D_BOX;
	return ofs;
}

ifstream& operator >> (ifstream& ifs, Cinema &object)
{
	ifs >> object.name >> object.city >> object.country >> object.date.date_of_foundation >> object.date.month_of_foundation >> object.date.year_of_foundation >> object.hall_number >> object.hall_3D >> object.hall_D_BOX;
	return ifs;
}

void			Cinema::show() const
{
	printf("\xB3   Cinema   ");
	Cultural_institution::show();
	printf(" \xB3 %5d \xB3 %8d \xB3 %11d \xB3\n", hall_number, hall_3D, hall_D_BOX);
}

Cinema::~Cinema() {}