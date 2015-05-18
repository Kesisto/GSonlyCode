#ifndef GSMENU_H
#define GSMENU_H
#include "GSIncludes.h"
#include "GSHud.h"

namespace groundSupport
{
	class GSMenu
	{
	public:
		GSMenu();
		~GSMenu();
		enum GsMenuState
		{
			g_idle,
			g_quit,
			g_play,
			g_info,
			g_options
		};

		struct MenuItem
		{
		public:
			sf::Rect<int> rect;
			GsMenuState action;
		};

		GsMenuState show(sf::RenderWindow& window);
	private:
		GsMenuState getGSMenuResponse(sf::RenderWindow& window);
		GsMenuState mouseTracker(int x, int y);
		std::list<MenuItem> _menuItems;

	};
}

#endif