#include "GSAmmo.h"



groundSupport::GSAmmo::GSAmmo() : _velocity(-100), _frameSize(334, 334), _frameCount(3, 3), _currentFrame(0, 0)
{	
	objectLoad("Assets/Textures/GSEffects.png");
	assert(GsIsLoaded());

	getSprite().setOrigin(getSprite().getScale().x / 2, getSprite().getScale().y / 2);


}


groundSupport::GSAmmo::~GSAmmo()
{
}

void groundSupport::GSAmmo::drawOrdnance(sf::RenderWindow & renderwindow)
{
	groundSupport::GSGameObject::objectDraw(renderwindow);
}

float groundSupport::GSAmmo::getObjectVelocity()const
{

	return _velocity;
}

void groundSupport::GSAmmo::updateObject(float elapsedTime)
{
	

	if (_currentFrame.y == 0)
	{
		groundSupport::GSPlayer* Player1 =
		dynamic_cast<groundSupport::GSPlayer*>(groundSupport::GSGameObjectManager().getObject("Player1"));
	
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			ammoDirection = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{
			ammoDirection = 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		{
			ammoDirection = 2;
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			_currentFrame.y = 1;
			_currentFrame.x = ammoDirection;
			getSprite().setPosition(getObjectPosition().x, Player1->getBoundingRect().top - getWidth() / 2 - 1);
		}
	}

		getSprite().setTextureRect(sf::IntRect(_currentFrame.x*_frameSize.x, _currentFrame.y*_frameSize.y, _frameSize.x, _frameSize.y));
		if (_currentFrame.y != 0)
		{

			if (ammoDirection = 0)
			{
				getSprite().move(0, _velocity);
			}

		/*	if (ammoDirection = 1)
			{
				getSprite().move(0.8660254038f*_velocity, 0.5f*_velocity);
			}

			else if (ammoDirection = 2)
			{
				getSprite().move(0.8660254038f*_velocity*-1,0.5f* _velocity);
			}*/
		}

		
	


}