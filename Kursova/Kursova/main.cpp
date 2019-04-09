/* ************************************************************************** */
/*                                                                            */
/*   MainSubject.cpp                                :::::::::::     :::       */
/*                                                          :+:   :+:+:       */
/*                                                          +:+     +:+       */
/*   By: bdeomin <Bogdan Deomin>                          +#+       +#+       */
/*                                                      +#+         +#+       */
/*   Created: 2018/11/15 14:03:21 by bdeomin           #+#          #+#       */
/*   Updated: 2018/11/25 20:03:24 by bdeomin           #+#       ########.BS  */
/*                                                                            */
/* ************************************************************************** */

#include "Cultural_institution.h"
#include "Theater.h"
#include "Cinema.h"

#include "Container.h"

#include "Keyboard.h"

#include "File.h"


#include <iostream>
#include <string.h>

#include <conio.h>

using namespace std; 

/*
struct	List
{
	Cultural_institution	*data;
	List					*next;
}	*head;

List	*Add_elem(List *element, Cultural_institution *data)
{
	if (!element)
	{
		element = new List;
		element->data = data;
		element->next = 0;
	}
	else
		element->next = Add_elem(element->next, data);
	return (element);
}

void	Print_container(List *element)
{
	if (element == NULL)
		return ;
	else
		element->data->show();
	Print_container(element->next);
}

List	*Delete_elem(List *element, Cultural_institution *data)
{
	List *temp;

	if (element->data == data)
	{
		temp = element->next;
		element->next = NULL;
		delete element;
		element = temp;
	}
	else
		element->next = Delete_elem(element->next, data);
	return (element);
}

List	*Delete_container(List *element)
{
	List *temp;

	while (element)
	{
		temp = element->next;
		element->next = NULL;
		delete element;
		element = temp;
	}
	return (element);
}*/

int		main(void)
{
	system("mode con cols=180");

	List *head = NULL;
	Container *Cont = new Container();
	File *file = new File();

	// Ввод с помощью клавиатуры
	/*
	Keyboard *Enter_data = new Keyboard();
	head = Enter_data->Input(head, Cont);
	*/

	// Иннициализация обьектов базового класса
	/*
	Cultural_institution *object31 = new Theater("qwerty", "Ukraine", "Kiev", 1, "March", 2000, 10, 0);
	Cultural_institution *object1 = new Theater("Malyatko1", "Ukraine", "Kiev", 1, "2March", 2000, 10, 0);
	Cultural_institution *object2 = new Cinema("Oscar", "Ukraine", "Kiev", 03, "qwerty", 2010, 10, 10, 1);
	Cultural_institution *object18 = new Cinema("Oscar", "Ukraine", "Kiev", 04, "2", 2010, 10, 10, 1);
	Cultural_institution *object19 = new Cinema("Oscar", "Ukraine", "Kiev", 05, "3", 2010, 10, 10, 1);
	Cultural_institution *object26 = new Cinema("Oscar", "Ukraine", "Kiev", 06, "10", 2010, 10, 10, 1);
	Cultural_institution *object3 = new Theater("Malyatko2", "Ukraine", "Kiev", 7, "35", 1991, 10, 0);
	Cultural_institution *object24 = new Cinema("Oscar", "Ukraine", "Kiev", 8, "8", 2010, 10, 10, 1);
	Cultural_institution *object4 = new Theater("Malyatko", "Ukraine", "Kiev", 9, "April", 1991, 10, 0);
	Cultural_institution *object28 = new Cinema("Oscar", "Ukraine", "Kiev", 10, "12", 2010, 10, 10, 1);
	Cultural_institution *object5 = new Theater("Malyatko", "Ukraine", "Kiev", 11, "December", 1991, 10, 0);
	Cultural_institution *object6 = new Theater("Malyatko", "Ukraine", "Kiev", 12, "May", 1991, 10, 0);
	Cultural_institution *object7 = new Cinema("Oscar", "Ukraine", "Kiev", 13, "03", 2009, 10, 10, 1);
	Cultural_institution *object8 = new Theater("Malyatko", "Ukraine", "Kiev", 14, "January", 1991, 10, 0);
	Cultural_institution *object25 = new Cinema("Oscar", "Ukraine", "Kiev", 15, "9", 2010, 10, 10, 1);
	Cultural_institution *object20 = new Cinema("Oscar", "Ukraine", "Kiev", 16, "04", 2010, 10, 10, 1);
	Cultural_institution *object23 = new Cinema("Oscar", "Ukraine", "Kiev", 17, "07", 2010, 10, 10, 1);
	Cultural_institution *object22 = new Cinema("Oscar", "Ukraine", "Kiev", 18, "06", 2010, 10, 10, 1);
	Cultural_institution *object9 = new Theater("Malyatko", "Ukraine", "Kiev", 19, "February", 1991, 10, 0);
	Cultural_institution *object10 = new Theater("Malyatko", "Ukraine", "Kiev", 20, "November", 1991, 10, 0);
	Cultural_institution *object11 = new Theater("Malyatko", "Ukraine", "Kiev", 21, "June", 1991, 10, 0);
	Cultural_institution *object12 = new Theater("Malyatko", "Ukraine", "Kiev", 22, "July", 1991, 10, 0);
	Cultural_institution *object21 = new Cinema("Oscar", "Ukraine", "Kiev", 23, "05", 2010, 10, 10, 1);
	Cultural_institution *object13 = new Theater("Malyatko", "Ukraine", "Kiev", 24, "August", 1991, 10, 0);
	Cultural_institution *object14 = new Theater("Malyatko", "Ukraine", "Kiev", 25, "March", 1991, 10, 0);
	Cultural_institution *object15 = new Theater("Malyatko", "Ukraine", "Kiev", 26, "September", 1991, 10, 0);
	Cultural_institution *object16 = new Theater("Malyatko", "Ukraine", "Kiev", 27, "October", 1991, 10, 0);
	Cultural_institution *object17 = new Cinema("Oscar", "Ukraine", "Kiev", 28, "01", 2010, 10, 10, 1);
	Cultural_institution *object27 = new Cinema("Oscar", "Ukraine", "Kiev", 29, "11", 2010, 10, 10, 1);
	Cultural_institution *object29 = new Cinema("Oscar", "Ukraine", "Kiev", 30, "11", 2010, 10, 10, 1);
	Cultural_institution *object30 = new Theater("Malyatko", "Ukraine", "Kiev", 31, "June", 1991, 10, 0);
	Cultural_institution *object32 = new Theater("Kiev", "Ukraine", "Kiev", 0, "June", 1991, 10, 0);
	Cultural_institution *object33 = new Cinema("Oscar", "Ukraine", "Kiev", 32, "11", 2010, 10, 10, 1);
	*/



	// Добавление Элементов в контейнер
	/*
	Cont->Add_elem(&head, object1);
	Cont->Add_elem(&head, object2);
	Cont->Add_elem(&head, object3);
	Cont->Add_elem(&head, object4);
	Cont->Add_elem(&head, object5);
	Cont->Add_elem(&head, object6);
	Cont->Add_elem(&head, object7);
	Cont->Add_elem(&head, object8);
	Cont->Add_elem(&head, object9);
	Cont->Add_elem(&head, object10);
	Cont->Add_elem(&head, object11);
	Cont->Add_elem(&head, object12);
	Cont->Add_elem(&head, object13);
	Cont->Add_elem(&head, object14);
	Cont->Add_elem(&head, object15);
	Cont->Add_elem(&head, object16);
	Cont->Add_elem(&head, object17);
	Cont->Add_elem(&head, object18);
	Cont->Add_elem(&head, object19);
	Cont->Add_elem(&head, object20);
	Cont->Add_elem(&head, object21);
	Cont->Add_elem(&head, object22);
	Cont->Add_elem(&head, object23);
	Cont->Add_elem(&head, object24);
	Cont->Add_elem(&head, object25);
	Cont->Add_elem(&head, object26);
	Cont->Add_elem(&head, object27);
	Cont->Add_elem(&head, object28);
	Cont->Add_elem(&head, object29);
	Cont->Add_elem(&head, object30);
	Cont->Add_elem(&head, object31);
	Cont->Add_elem(&head, object32);
	Cont->Add_elem(&head, object33);
	*/
	//Чтение с файла
	file->put_out_file(&head, Cont);

	// Печать контейнера
	Cont->Print_container(head);

	//Запись в файл
	//file->write_in_file(head);

	


	// Удаление Элемента контейнера
	/*
	Cont->Delete_elem(&head, object1);
	if(head == NULL)
		printf("\nContainer free\n");
	Cont->Print_container(head);
	*/

	// Показать созданые обьекты
	/*
	object1->show();
	object3->show();
	*/

	// Удаление Контейнера
	Cont->Delete_container(&head);
	if (head == NULL)
		printf("\nContainer free\n");

	// Уданение Обьектов
	/*
	delete Cont;
	delete Enter_data;

	*/

	_getch();
	return(0);
}