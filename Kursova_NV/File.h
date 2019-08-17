#ifndef FILE_H
#define FILE_H

#include "Theater.h"
#include "Cinema.h"

#include "Container.h"
#include <fstream>

class File
{
public:

	File();
	static void		write_in_file(List *head);
	static int		put_out_file(List **head, Container *Cont);

	friend fstream& operator<<(fstream&, List*);

	friend Cultural_institution &operator>>(fstream& in, Cultural_institution	&object);
	~File();
};

#endif