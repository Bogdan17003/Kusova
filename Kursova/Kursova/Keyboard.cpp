#include "Keyboard.h"
#include <iostream>
#include <string>
using namespace std;

Keyboard::Keyboard() {}

List *Keyboard::Input(List * head, Container *Cont)
{
	printf(AC_RED "RED\n" AC_RESET AC_GREEN "GREEN\n" AC_RESET AC_YELLOW "YELLOW\n" AC_RESET AC_BLUE "BLUE\n" AC_RESET AC_MAGENTA "MAGENTA\n" AC_RESET AC_CYAN "CYAN\n" AC_RESET);
	while (true)
	{
		int switcher;
		printf( AC_YELLOW "\n\nCreate Cultural institution: Theater input '0'\nCreate Cultural institution: Cinema input '1'\nInput other parameter if you want end entering data\n\n" AC_RESET "Input: ");
		scanf_s("%d", &switcher);
		printf("\n");
		if (switcher == 0 || switcher == 1)
		{
			string	NAME;
			string	COUNTRY;
			string	CITY;
			int		DATE_OF_FOUNDATION;
			string	MOUNTH_OF_FOUNDATION;
			int		YEAR_OF_FOUNDATION;

			switcher == 0 ? printf(AC_MAGENTA): printf(AC_CYAN);
			getchar();
			printf("Input Name of the ");
			switcher == 0 ? printf("Theater: ") : printf("Cinema: ");
			getline(cin, NAME, '\n');
			printf("Input Country: ");
			getline(cin, COUNTRY, '\n');
			printf("Input City: ");
			getline(cin, CITY, '\n');
			printf("Input Date of foundation: ");
			scanf_s("%d", &DATE_OF_FOUNDATION);
			getchar();
			printf("Input Mounth of foundation: ");
			getline(cin, MOUNTH_OF_FOUNDATION, '\n');
			printf("Input Year of foundation: ");
			scanf_s("%d", &YEAR_OF_FOUNDATION);

			if (switcher == 0)
			{
				int		ACTORS_NUMBER;
				int		BALCON;
				printf("Input How Actors in the Theater: ");
				scanf_s("%d", &ACTORS_NUMBER);
				printf("Input How Balcon in the Theater: ");
				scanf_s("%d", &BALCON);

				Cultural_institution *object = new Theater(NAME, COUNTRY, CITY, DATE_OF_FOUNDATION, MOUNTH_OF_FOUNDATION, YEAR_OF_FOUNDATION, ACTORS_NUMBER, BALCON);
				Cont->Add_elem(&head, object);
				//delete object;
			}
			else if (switcher == 1)
			{
				int		HALL_NUMBER;
				int		HALL_3D;
				int		HALL_D_BOX;
				printf("Input How many Hall in the Cinema: ");
				scanf_s("%d", &HALL_NUMBER);
				printf("Input How many 3d Hall in the Cinema: ");
				scanf_s("%d", &HALL_3D);
				printf("Input How many D-BOX Hall in the Cinema: ");
				scanf_s("%d", &HALL_D_BOX);
				Cultural_institution *object = new Cinema(NAME, COUNTRY, CITY, DATE_OF_FOUNDATION, MOUNTH_OF_FOUNDATION, YEAR_OF_FOUNDATION, HALL_NUMBER, HALL_3D, HALL_D_BOX);
				Cont->Add_elem(&head, object);
				//delete object;
			}
			//Cont->Print_container(head);
			printf(AC_RESET);
		}
		else
			break;
	}
	return (head);
}

Keyboard::~Keyboard() {}