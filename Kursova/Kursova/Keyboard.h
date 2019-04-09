#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Container.h"

class Keyboard
{
public:
	Keyboard();

	List *Input(List *head, Container *Cont);

	~Keyboard();
};

