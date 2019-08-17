/* ************************************************************************** */
/*                                                                            */
/*   Cinema.h                                       :::::::::::     :::       */
/*                                                          :+:   :+:+:       */
/*                                                          +:+     +:+       */
/*   By: bdeomin <Bogdan Deomin>                          +#+       +#+       */
/*                                                      +#+         +#+       */
/*   Created: 2018/11/15 14:03:21 by bdeomin           #+#          #+#       */
/*   Updated: 2018/05/12 20:50:29 by bdeomin           #+#       ########.BS  */
/*                                                                            */
/* ************************************************************************** */

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
	Cinema(string _name, string _country, string _city, int _date_of_foundation,
		string _mounth_of_foundation, int _year_of_foundation, int _hall_number,
		int _hall_3D, int _hall_D_BOX);

	Cinema();

	void			setHall_number(const int _hall_number);
	int				getHall_number(void) const;

	void			setHall_3D(const int _hall_3D);
	int				getHall_3D(void) const;

	void			setHall_D_BOX(const int _hall_D_BOX);
	int				getHall_D_BOX(void) const;

	virtual	void	show(void) const;

	virtual ofstream	&returned(ofstream& out, const Cultural_institution *data) const;
	virtual	Cultural_institution &input(ifstream& in,
		Cultural_institution *object) const;
	friend ofstream& operator << (ofstream& out, const Cinema *data);
	friend Cultural_institution &operator >> (ifstream& in, Cinema *object);

	virtual			~Cinema(void);
};
#endif