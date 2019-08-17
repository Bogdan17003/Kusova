/* ************************************************************************** */
/*                                                                            */
/*   Menu.cpp                                       :::::::::::     :::       */
/*                                                          :+:   :+:+:       */
/*                                                          +:+     +:+       */
/*   By: bdeomin <Bogdan Deomin>                          +#+       +#+       */
/*                                                      +#+         +#+       */
/*   Created: 2018/11/15 14:03:21 by bdeomin           #+#          #+#       */
/*   Updated: 2018/05/12 20:45:11 by bdeomin           #+#       ########.BS  */
/*                                                                            */
/* ************************************************************************** */

#include "Menu.h"

Menu* Menu::_self(0);

Menu* Menu::Create_menu()
{
	if (!_self)
		_self = new Menu();
	return _self;
}

// ----------------------------------------------------------------------------
// Фукція дозволяє не підтверджувати обраний пункт меню клавішею ENTER
int Read_one_symb(char *ch)
{
	*ch = _getch();
	return (EXIT_SUCCESS);
}

// ----------------------------------------------------------------------------
// Меню користувача
void Menu::Run()
{
	int i;
	char ch;
	char s[1];

	do
	{
		system("cls");
		cout << "--------------- MENU ---------------" << endl;
		cout << "<1>.Create Theater`s object" << endl;
		cout << "<2>.Create Cinema`s object" << endl;
		cout << "<3>.Show all Cultural institution" << endl;
		cout << "<4>.Remove all Cultural institution" << endl;
		cout << "<5>.Save to the file" << endl;
		cout << "<6>.Load from the file" << endl;
		cout << "<7>.Do request" << endl;
		cout << "<8>.Leav the program" << endl << endl;

		Read_one_symb(&ch);
		s[0] = ch;
		i = atoi(s);
		switch (i)
		{
		case 1:
		{
			system("cls");
			Cont.Input(Cont, i);
			system("pause");
			break;
		}
		case 2:
		{
			system("cls");
			Cont.Input(Cont, i);
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			Cont.Print_container();
			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			Cont.Delete_container();
			system("pause");
			break;
		}
		case 5:
		{
			system("cls");
			Cont.write_in_file();
			system("pause");
			break;
		}
		case 6:
		{
			system("cls");
			if (int count = Cont.put_out_file(Cont))
				cout << AC_GREEN << "Found and recorded " << count << (count == 1 ?
					" item." : " items.") << AC_RESET << endl;
			else
				cout << AC_YELLOW "Could not find anything in the file" << AC_RESET << endl;
			system("pause");
			break;
		}
		case 7:
		{
			system("cls");
			Cont.Show_oldest_theater();
			system("pause");
			break;
		}
		case 8:
		{
			system("cls");
			cout  << "Completion of the program..." << endl;
			Cont.Delete_container();
			break;
		}
		default:
			if (i > 8 || i < 1)
			{
				cout << AC_YELLOW << "Your choise is not correct..." << AC_RESET << endl;
				system("pause");
			}
			break;
		}
	} while (i != 8);
}

bool Menu::Delete_menu()
{
	if (_self)
	{
		delete _self;
		_self = 0;
		return true;
	}
	return false;
}