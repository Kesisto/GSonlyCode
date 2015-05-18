#include "GSMenu.h"


groundSupport::GSMenu::GSMenu()
{
	groundSupport::GSHud _hud;
	_hud.setBinaries();
}


groundSupport::GSMenu::~GSMenu()
{
}

groundSupport::GSMenu::GsMenuState groundSupport::GSMenu::show(sf::RenderWindow& window)
{
	sf::Texture image;
	image.loadFromFile("Assets/Textures/GSMenu.png");
	sf::Sprite sprite(image);

	MenuItem startGame;
	startGame.rect.top = 170;
	startGame.rect.height = 100;
	startGame.rect.left = 327;
	startGame.rect.width = 370;
	startGame.action = g_play;

	MenuItem infoGame;
	infoGame.rect.top = 271;
	infoGame.rect.height = 86;
	infoGame.rect.left = 327;
	infoGame.rect.width = 370;
	infoGame.action = g_info;

	MenuItem optionsGame;
	optionsGame.rect.top = 358;
	optionsGame.rect.height = 88;
	optionsGame.rect.left = 327;
	optionsGame.rect.width = 370;
	optionsGame.action = g_options;

	MenuItem quitGame;
	quitGame.rect.top = 446;
	quitGame.rect.height = 98;
	quitGame.rect.left = 327;
	quitGame.rect.width = 370;
	quitGame.action = g_quit;

	_menuItems.push_back(startGame);
	_menuItems.push_back(infoGame);
	_menuItems.push_back(optionsGame);
	_menuItems.push_back(quitGame);

	window.draw(sprite);
	window.display();

	return getGSMenuResponse(window);
}

groundSupport::GSMenu::GsMenuState groundSupport::GSMenu::mouseTracker(int x, int y)
{
	std::list<MenuItem>::iterator MiIt;
	for (MiIt = _menuItems.begin(); MiIt != _menuItems.end(); MiIt++)
	{
		sf::Rect<int>MI = (*MiIt).rect;
		if (MI.top < y && MI.height+MI.top > y && MI.left < x && MI.width+MI.left > x)
		{
			return (*MiIt).action;
		}
	}
	return g_idle;
}

groundSupport::GSMenu::GsMenuState groundSupport::GSMenu::getGSMenuResponse(sf::RenderWindow& window)
{
	sf::Event menuEvent;
	while (true)
	{
		while (window.pollEvent(menuEvent))
		{
			if (menuEvent.type == sf::Event::MouseButtonPressed)
			{
				return mouseTracker(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
			}
			if (menuEvent.type == sf::Event::Closed)
			{
				return g_quit;
			}
		}
	}
}