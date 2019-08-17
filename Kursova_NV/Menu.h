/* ************************************************************************** */
/*                                                                            */
/*   Menu.h                                         :::::::::::     :::       */
/*                                                          :+:   :+:+:       */
/*                                                          +:+     +:+       */
/*   By: bdeomin <Bogdan Deomin>                          +#+       +#+       */
/*                                                      +#+         +#+       */
/*   Created: 2018/11/15 14:03:21 by bdeomin           #+#          #+#       */
/*   Updated: 2018/05/12 20:47:55 by bdeomin           #+#       ########.BS  */
/*                                                                            */
/* ************************************************************************** */

#include "Container.h"
#include <conio.h>
using namespace std;

class Menu
{
protected:
	Container Cont;
	static Menu* _self;
	Menu() {}
	virtual ~Menu() {}
public:
	static Menu*	Create_menu();
	void			Run();
	static bool		Delete_menu();
};