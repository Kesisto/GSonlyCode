#ifndef GSAMMO_H
#define GSAMMO_H
#include "GSGameObject.h"
#include "GSRun.h"
//Tämä luokka ei ole käytössä, mutta on tarkoitus myöhemmin ottaa käyttöön.
namespace groundSupport
{
	class GSAmmo : public GSGameObject
	{
	public:
		GSAmmo();
		~GSAmmo();
		void updateObject(float elapsedTime);
		void drawOrdnance(sf::RenderWindow& renderwindow);

		float getObjectVelocity()const;

	private:
		float _velocity;
		int ammoDirection;
		
		const sf::Vector2i _frameSize;
		const sf::Vector2i _frameCount;
		sf::Vector2i _currentFrame;
	


		
		

		
	};
}
#endif
