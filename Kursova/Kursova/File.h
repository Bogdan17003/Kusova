#include "Container.h"
#include <fstream>

class File
{
public:

	File();
	void	write_in_file(List *head);
	int		put_out_file(List **head, Container *Cont);

	~File();
};