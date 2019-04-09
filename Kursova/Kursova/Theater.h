#ifndef THEATER_H
#define THEATER_H
#include "Cultural_institution.h"

class Theater : public Cultural_institution
{
private:
	int		actors_number;
	int		balcon;

public:
	Theater(string _name, string _country, string _city, int _date_of_foundation, string _mounth_of_foundation, int _year_of_foundation, int _actors_number, int _balcon);

	Theater();

	void			setActors_number(int _actors_number);
	int				getActors_number(void)  const;

	void			setBalcon(bool _balcon);
	int				getBalcon(void) const;

	friend ofstream& operator << (ofstream& ofs, Theater &object);
	friend ifstream& operator >> (ifstream& ifs, Theater &object);

	virtual void	show(void) const;

	virtual			~Theater();
};
#endif