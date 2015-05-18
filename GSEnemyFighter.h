#ifndef GSENEMYFIGHTER_H
#define GSENEMYFIGHTER_H
#include "GSGameObject.h"
#include "GSGameObjectManager.h"
#include "GSPlayer.h"
#include "GSRun.h"
#include "GSHud.h"

namespace groundSupport
{
	class GSEnemyFighter:public GSGameObject
	{
	public:
		GSEnemyFighter();
		~GSEnemyFighter();
		//P‰ivitet‰‰n sijainti, pidet‰‰n kirjaa osumista ja pisteist‰.
		void updateObject(float elapsedTime);
		void drawObject(sf::RenderWindow& renderwindow);

		float getObjectVelocity()const;

	private:
		float _velocity;
		float _fallVelocity;
		float _distance;
		float _magazine;
		float _burst;


		int _armor;
		const sf::Vector2i _frameSize;
		const sf::Vector2i _frameCount;
		sf::Vector2i _currentFrame;
	};
}

#endif