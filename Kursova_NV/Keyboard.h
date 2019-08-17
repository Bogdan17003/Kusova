#ifndef KEYBOARD_H
#define KEYBOARD_H
#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Container.h"

class Keyboard
{
public:
	Keyboard();

	static List *Input(Container *Cont, int switcher);

	~Keyboard();
};

#endif