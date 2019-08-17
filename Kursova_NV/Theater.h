/* ************************************************************************** */
/*                                                                            */
/*   Theater.h                                      :::::::::::     :::       */
/*                                                          :+:   :+:+:       */
/*                                                          +:+     +:+       */
/*   By: bdeomin <Bogdan Deomin>                          +#+       +#+       */
/*                                                      +#+         +#+       */
/*   Created: 2018/11/15 14:03:21 by bdeomin           #+#          #+#       */
/*   Updated: 2018/05/12 20:51:28 by bdeomin           #+#       ########.BS  */
/*                                                                            */
/* ************************************************************************** */

#ifndef THEATER_H
#define THEATER_H
#include "Cultural_institution.h"

class Theater : public Cultural_institution
{
private:
	int		actors_number;
	int		balcon;

public:
	Theater(string _name, string _country, string _city, int _date_of_foundation,
		string _mounth_of_foundation, int _year_of_foundation,
		int _actors_number, int _balcon);

	Theater();

	void			setActors_number(const int _actors_number);
	int				getActors_number(void)  const;

	void			setBalcon(const int _balcon);
	int				getBalcon(void) const;

	virtual void	show(void) const;


	virtual ofstream	&returned(ofstream& out, const Cultural_institution *data) const;
	virtual Cultural_institution &input(ifstream& in,
		Cultural_institution *object) const;
	friend ofstream& operator << (ofstream& out, const Theater *data);
	friend Cultural_institution &operator >> (ifstream& in, Theater *object);


	virtual			~Theater();
};
#endif