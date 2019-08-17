/* ************************************************************************** */
/*                                                                            */
/*   Container.h                                    :::::::::::     :::       */
/*                                                          :+:   :+:+:       */
/*                                                          +:+     +:+       */
/*   By: bdeomin <Bogdan Deomin>                          +#+       +#+       */
/*                                                      +#+         +#+       */
/*   Created: 2018/11/15 14:03:21 by bdeomin           #+#          #+#       */
/*   Updated: 2018/05/12 20:49:33 by bdeomin           #+#       ########.BS  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTAINER_H
#define CONTAINER_H

#include "Theater.h"
#include "Cinema.h"

struct	List
{
	Cultural_institution	*data;
	List					*next;
};

class	Container
{
private:
	List *element;

public:
	Container();

	int		Check(const Cultural_institution* data1,
		const Cultural_institution* data2);
	int		Len() const;

	void	Add_elem(Cultural_institution *data);
	void	Print_container() const;
	void	Delete_elem(Cultural_institution *data);
	void	Delete_container();
	void	Show_oldest_theater();

	void	Input(Container Cont, int switcher);

	void	write_in_file() const;
	int		put_out_file(Container Cont);

	friend ofstream& operator<<(ofstream&, List*);

	friend Cultural_institution &operator>>(ifstream& in,
		Cultural_institution	&object);
	~Container();
};

#endif