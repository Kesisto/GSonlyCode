#include "GSRun.h"


groundSupport::GSRun::GSRun()
{

}


groundSupport::GSRun::~GSRun()
{
}

void groundSupport::GSRun::start()
{

	if (_State != g_uninitialized)
	{
		return;
	}

	_mainWin.create(sf::VideoMode(Screen_Width, screen_Heihgt, 32), "-=GroundSupport=-");
	//Enemy
	groundSupport::GSEnemyFighter *_fighter = new groundSupport::GSEnemyFighter();
	_fighter->objectLoad("Assets/Textures/GSFighter.png");
	_fighter->setObjectPosition((Screen_Width / 2), screen_Heihgt/8);
	
	_gameObjectManager.GSAdd("EnemyFighter", _fighter);
	////Enemy 2
	//groundSupport::GSEnemyFighter *_fighter2 = new groundSupport::GSEnemyFighter();
	//_fighter->objectLoad("Assets/Textures/GSFighter.png");
	//_fighter->setObjectPosition((Screen_Width / 2), -100);

	//_gameObjectManager.GSAdd("EnemyFighter2", _fighter);
	////Enemy 3
	//groundSupport::GSEnemyFighter *_fighter3 = new groundSupport::GSEnemyFighter();
	//_fighter->objectLoad("Assets/Textures/GSFighter.png");
	//_fighter->setObjectPosition((Screen_Width / 2), -200);

	//_gameObjectManager.GSAdd("EnemyFighter3", _fighter);
	//Player
	groundSupport::GSPlayer *_player = new groundSupport::GSPlayer();
	_player->objectLoad("Assets/Textures/GSTank.png");
	_player->setObjectPosition((Screen_Width / 2), screen_Heihgt / 1.2);


	_gameObjectManager.GSAdd("Player1", _player);
	//Ammo

		//groundSupport::GSAmmo *_cannonShell = new groundSupport::GSAmmo();
		//_cannonShell->objectLoad("Assets/Textures/GSEffects.png");
		//_cannonShell->setObjectPosition((Screen_Width / 2), screen_Heihgt / 2);
		//
		//_gameObjectManager.GSAdd("PlayerAmmo", _cannonShell);

	
	_State = groundSupport::GSRun::g_showingBg;

	clock();


	while (!isQuiting())
	{
		GSLooping();
	}

	_mainWin.close();

}


bool groundSupport::GSRun::isQuiting()
{
	if (_State == groundSupport::GSRun::g_quit)
		return true;
	else
		return false;
}


sf::RenderWindow& groundSupport::GSRun::GetWindow()
{
	return _mainWin;
}
const groundSupport::GSGameObjectManager& groundSupport::GSRun::getGSGameObjectManager()
{
	return groundSupport::GSRun::_gameObjectManager;
}


void groundSupport::GSRun::GSLooping()
{


	sf::Event currentEvent;
	_mainWin.pollEvent(currentEvent);
	
		switch (_State)
		{
		case groundSupport::GSRun::g_showingBg:
		{
			showGSIntro();
			break;
		}
		case groundSupport::GSRun::g_menu:
		{
			showGSMenu();
			break;
		}
		case groundSupport::GSRun::g_play:
		{
		

			_mainWin.clear(sf::Color(0, 0, 0));

		
			sf::Texture image;
			image.loadFromFile("Assets/Textures/GSLevel.png");
			sf::Sprite sprite(image);
			_mainWin.draw(sprite);
			
		
			_gameObjectManager.GSUpdateAll();
			_gameObjectManager.GSDrawAll(_mainWin);

			_mainWin.display();

			if (currentEvent.type == sf::Event::Closed)
			{
				_State = groundSupport::GSRun::g_quit;
				
			}
			if (currentEvent.type == sf::Event::KeyPressed)
			{
				if (currentEvent.key.code == sf::Keyboard::Escape)
				{
					showGSMenu();
				}
			}
			break;
		}
		}

}

void groundSupport::GSRun::showGSIntro()
{
	GSIntro intro;
	intro.showIntro(_mainWin);
	_State = groundSupport::GSRun::g_menu;
}


void groundSupport::GSRun::showGSMenu()
{
	GSMenu menu;
	groundSupport::GSMenu::GsMenuState result = menu.show(_mainWin);

	switch (result)
	{
	case groundSupport::GSMenu::g_quit:
	{
		_State = groundSupport::GSRun::g_quit;
		break;
	}
	case groundSupport::GSMenu::g_play:
	{
		_State = groundSupport::GSRun::g_play;
		break;
	}
	case groundSupport::GSMenu::g_info:
	{
		break;
	}
	case groundSupport::GSMenu::g_options:
	{
		break;
	}
	default:
		break;
	}
}

groundSupport::GSRun::GsState groundSupport::GSRun::_State = g_uninitialized;
sf::RenderWindow groundSupport::GSRun::_mainWin;

groundSupport::GSGameObjectManager groundSupport::GSRun::_gameObjectManager;