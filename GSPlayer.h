#ifndef GSPLAYER_H
#define GSPLAYER_H
#include "GSGameObject.h"




namespace groundSupport
{
	class GSPlayer : public GSGameObject
	{
	public:
		GSPlayer();
		~GSPlayer();
		//P‰ivitet‰‰n pelaajan sijainti ja tekstuuri.
		void updateObject(float elapsedTime);
		void drawObject(sf::RenderWindow& renderwindow);

		float getObjectVelocity()const;

		private:
			float _velocity;
			float _maxVelocity;
			const sf::Vector2i _frameSize;
			const sf::Vector2i _frameCount;
			sf::Vector2i _currentFrame;
	
	};
}
#endif