#include "Container.h"

Container::Container() : element(NULL) {}

void	Container::Add_elem(List **element, Cultural_institution *data)
{
	if (data->give_mounth() < 1 || data->give_mounth() > 12 || data->getDof() < 1 || data->getDof() > 31 || data->getYof() < 1)
	{
		data->setYof(200000);
		data->setDof(-1);
	}
	List *copy = *element;
	List *temp = new List;
	temp->data = data;
	temp->next = NULL;
	if (*element == NULL)
		*element = temp;
	else
	{
		if (typeid(*data) == typeid(Cinema))
		{
			if ((typeid(*(*element)->data) == typeid(Cinema)) && !check(data, (*element)->data))
			{
				*element = temp;
				temp->next = copy;
				return;
			}
			while (*element && typeid(*(*element)->data) == typeid(Theater))
			{
				if (((*element)->next) && (typeid(*(*element)->next->data) == typeid(Cinema)) && !check(data, (*element)->next->data))
				{
					List *next = (*element)->next;
					(*element)->next = temp;
					temp->next = next;
					*element = copy;
					return;
				}
				else if (!(*element)->next)
				{
					(*element)->next = temp;
					*element = copy;
					return;
				}
				*element = (*element)->next;
			}
			while ((*element)->next && check(data, (*element)->next->data))
				*element = (*element)->next;
			List *next = (*element)->next;
			(*element)->next = temp;
			temp->next = next;
			*element = copy;
		}
		else 
		{
			if (typeid(*(*element)->data) == typeid(Cinema) || ((typeid(*(*element)->data) == typeid(Theater)) && !check(data, (*element)->data)))
			{
				*element = temp;
				temp->next = copy;
			}
			else
			{
				while ((*element)->next && check(data, (*element)->next->data) &&  typeid(*(*element)->next->data) == typeid(Theater))
					*element = (*element)->next;
				List *next = (*element)->next;
				(*element)->next = temp;
				temp->next = next;
				*element = copy;
			}
		}
	}
}

void	print_symb(int n, const char *str)
{
	while (n-- > 0)
		printf("\xC4");
	printf("%s", str);
}

void	print_spase(int n, const char *str)
{
	while (n-- > 0)
		printf(" ");
	printf("%s", str);
}

void	print_header(void)
{
	printf("\xDA");
	print_symb(12, "\xC2");
	print_symb(40, "\xC2");
	print_symb(30, "\xC2");
	print_symb(25, "\xC2");
	print_symb(21, "\xC2");
	print_symb(32, "\xBF\n");
	printf("\xB3   Object   \xB3                                        \xB3                              \xB3                         \xB3                     \xB3        Object parametrs        \xB3\n");
	printf("\xC3");
	print_symb(12, "\xB4");
	print_spase(40, "\xB3");
	print_spase(30, "\xB3");
	print_spase(25, "\xB3");
	print_spase(21, "\xC3");
	print_symb(15, "\xC2");
	print_symb(16, "\xB4\n");
	printf("\xB3   Theater  \xB3                  Name                  \xB3           Country            \xB3          City           \xB3        Date         \xB3 Actors number \xB3 Balcons number \xB3\n");
	printf("\xC3");
	print_symb(12, "\xB4");
	print_spase(40, "\xB3");
	print_spase(30, "\xB3");
	print_spase(25, "\xB3");
	print_spase(21, "\xC3");
	print_symb(7, "\xC2");
	print_symb(7, "\xC1");
	print_symb(2, "\xC2");
	print_symb(13, "\xB4\n");
	printf("\xB3   Cinema   \xB3                                        \xB3                              \xB3                         \xB3                     \xB3 Halls \xB3 3D Halls \xB3 D-BOX Halls \xB3\n");
}

void	print_for_Object(const char *s1, const char *s2, const char *s3, const char *s4)
{
	print_symb(7, s1);
	print_symb(7, s2);
	print_symb(2, s3);
	print_symb(13, s4);
}

void	print_bottom(List *previos)
{
	printf("\xC0");
	print_symb(12, "\xC1");
	print_symb(40, "\xC1");
	print_symb(30, "\xC1");
	print_symb(25, "\xC1");
	print_symb(21, "\xC1");
	typeid(*(previos->data)) == typeid(Theater) ? print_for_Object("\xC4", "\xC1", "\xC4", "\xD9\n") : print_for_Object("\xC1", "\xC4", "\xC1", "\xD9\n");
}

void	print_all_string(List **element, List *previous)
{
	printf("\xC3");
	print_symb(12, "\xC5");
	print_symb(40, "\xC5");
	print_symb(30, "\xC5");
	print_symb(25, "\xC5");
	print_symb(21, "\xC5");
	if (*element == previous)
		typeid(*((*element)->data)) == typeid(Theater) ? print_for_Object("\xC1", "\xC2", "\xC1", "\xB4\n") : print_for_Object("\xC5", "\xC4", "\xC5", "\xB4\n");
	else
	{
		if (typeid(*((*element)->data)) == typeid(Theater) && typeid(*((previous)->data)) == typeid(Theater))
			print_for_Object("\xC4", "\xC5", "\xC4", "\xB4\n");
		else if (typeid(*((*element)->data)) == typeid(Cinema) && typeid(*((previous)->data)) == typeid(Cinema))
			print_for_Object("\xC5", "\xC4", "\xC5", "\xB4\n");
		else if (typeid(*((*element)->data)) == typeid(Cinema) && typeid(*((previous)->data)) == typeid(Theater))
			print_for_Object("\xC2", "\xC1", "\xC2", "\xB4\n");
	}
	(*element)->data->show();
	*element = (*element)->next;
}

void	Container::Print_container(List *element)
{
	if (element)
	{
		print_header();
		List *previous = element;
		print_all_string(&element, previous);
		while (element)
		{
			List *temp = element;
			print_all_string(&element, previous);
			previous = temp;
		}
		print_bottom(previous);
	}
}

void	Container::Delete_elem(List **element, Cultural_institution *data)
{
	if (*element)
	{
		List *temp = new List;
		temp = NULL;
		List *copy = *element;
		while (copy)
		{
			List *next = copy->next;
			if (copy->data == data)
			{
				if (temp)
					temp->next = next;
				else
					*element = next;
				delete copy;
			}
			else
				temp = copy;
			copy = next;
		}
	}
}

void	Container::Delete_container(List **element)
{
	while (*element)
	{
		List *temp;
		temp = (*element)->next;
		(*element)->next = NULL;
		delete *element;
		*element = temp;
	}
}

Container::~Container() {};


int		check(Cultural_institution *data1, Cultural_institution *data2)
{
	if (data1->getYof() < data2->getYof())
		return (0);
	else if (data1->getYof() > data2->getYof())
		return (1);
	else
	{
		if (data1->give_mounth() < data2->give_mounth())
			return (0);
		else if (data1->give_mounth() > data2->give_mounth())
			return (1);
		else
		{
			if (data1->getDof() < data2->getDof())
				return (0);
			else
				return (1);
		}
	}
	return (1);
}