/* ************************************************************************** */
/*                                                                            */
/*   Cultural_institution.h                         :::::::::::     :::       */
/*                                                          :+:   :+:+:       */
/*                                                          +:+     +:+       */
/*   By: bdeomin <Bogdan Deomin>                          +#+       +#+       */
/*                                                      +#+         +#+       */
/*   Created: 2018/11/15 14:03:21 by bdeomin           #+#          #+#       */
/*   Updated: 2018/05/12 20:52:32 by bdeomin           #+#       ########.BS  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CULTURAL_INSTITUTION_H
#define CULTURAL_INSTITUTION_H
#pragma warning(disable:4996)

#define AC_RED		"\x1b[31m"
#define AC_GREEN	"\x1b[32m"
#define AC_YELLOW	"\x1b[33m"
#define AC_BLUE		"\x1b[34m"     //константи для кольорового відображення
#define AC_MAGENTA	"\x1b[35m"
#define AC_CYAN		"\x1b[36m"
#define AC_RESET	"\x1b[0m"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

struct Date
{
	int		date_of_foundation;
	string	month_of_foundation;
	int		year_of_foundation;
	Date(int _date_of_foundation, string _month_of_foundation, 
		int _year_of_foundation);
	Date();
};

class Cultural_institution
{
protected:
	string	name;
	string	country;
	string	city;
	Date	date;

public:
	Cultural_institution(string _name, string _country, string _city,
		int _date_of_foundation, string _month_of_foundation,
		int _year_of_foundation);

	Cultural_institution();

	void			setName(const string _name);
	const string	getName(void) const;

	void			setCountry(const string _country);
	const string	getCountry(void) const;

	void			setCity(const string _city);
	const string	getCity(void) const;

	void			setDof(const int _date_of_foundation);
	const int		getDof(void) const;

	void			setMof(const string _mounth_of_foundation);
	const string	getMof(void) const;

	void			setYof(const int _year_of_foundation);
	const int		getYof(void) const;

	void			show_data(void) const;
		
	const int		give_mounth(void) const;

	virtual void	show(void) const;

	virtual ofstream	&returned(ofstream& out, const Cultural_institution *data) const;
	virtual	Cultural_institution &input(ifstream& in,
		Cultural_institution *object) const;

	friend ofstream& operator << (ofstream& out, const Cultural_institution *data);

	virtual	~Cultural_institution();
};
#endif