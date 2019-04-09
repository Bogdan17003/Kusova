#ifndef CONTAINER_H
#define CONTAINER_H

#include "Theater.h"
#include "Cinema.h"

int		check(Cultural_institution *data1, Cultural_institution *data2);

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

	void	Add_elem(List **element, Cultural_institution *data);
	void	Print_container(List *element);
	void	Delete_elem(List **element, Cultural_institution *data);
	void	Delete_container(List **element);
	~Container();
};

#endif