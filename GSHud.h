#ifndef GSHUD_H
#define GSHUD_H
#include "GSIncludes.h"
#include "GSGameObject.h"
#include "GSEnemyFighter.h"
#include "GSRun.h"
#include <fstream>

namespace groundSupport
{
	class GSHud :public GSGameObject
	{
	public:
		GSHud();
		~GSHud();
		//Pidet‰‰n pisteit‰ bin‰‰ritiedostolla kirjalla.
		void updateObject(float elapsedTime);
		void enemyScore();
		void enemyHits();
		void enemyDestroyed();
		//Metodi jossa menuun siirrytt‰ess‰ pistearvot nollaantuvat.
		void setBinaries();
	


	private:
	int _playerHealt;
	int _score;

	//Tekstit joilla oli tarkoitus kirjoittaa pisteet.
	sf::Font font;
	sf::Text Healt;
	sf::Text _healPoints;
	sf::Text Score;
	sf::Text _scorePoints;
	std::string stream;
	};
}
#endif

