#ifndef CINEMA_H
#define CINEMA_H
#include "Cultural_institution.h"

class Cinema : public Cultural_institution
{
private:
	int		hall_number;
	int		hall_3D;
	int		hall_D_BOX;

public:
	Cinema(string _name, string _country, string _city, int _date_of_foundation, string _mounth_of_foundation, int _year_of_foundation, int _hall_number, int _hall_3D, int _hall_D_BOX);

	Cinema();

	void			setHall_number(int _hall_number);
	int				getHall_number(void) const;

	void			setHall_3D(int _hall_3D);
	int				getHall_3D(void) const;

	void			setHall_D_BOX(int _hall_D_BOX);
	int				getHall_D_BOX(void) const;

	friend ofstream& operator << (ofstream& ofs, Cinema &object);
	friend ifstream& operator >> (ifstream& ifs, Cinema &object);

	virtual	void	show(void) const;

	virtual			~Cinema(void);
};
#endif