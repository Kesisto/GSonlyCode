#include "GSPlayer.h"


groundSupport::GSPlayer::GSPlayer() :_velocity(0), _maxVelocity(300.0f), _frameSize(334, 334), _frameCount(3, 9), _currentFrame(0, 0)
{
	objectLoad("Assets/Textures/GSTank.png");
	assert(GsIsLoaded());

	getSprite().setOrigin(getSprite().getScale().x / 2, getSprite().getScale().y / 2);
}


groundSupport::GSPlayer::~GSPlayer()
{
}

void groundSupport::GSPlayer::drawObject(sf::RenderWindow & renderwindow)
{
	groundSupport::GSGameObject::objectDraw(renderwindow);
}

float groundSupport::GSPlayer::getObjectVelocity()const
{

	return _velocity;
}

void groundSupport::GSPlayer::updateObject(float elapsedTime)
{

	if (_currentFrame.x == 2)
	{
		_currentFrame.x = 0;
	}	
	if (_currentFrame.x == 1)
	{
		++_currentFrame.x;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		_velocity -= 3.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		_velocity += 3.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		_velocity = 0.0f;
	}
	if (_velocity > _maxVelocity)
	{
		_velocity = _maxVelocity;
	}
	if (_velocity < -_maxVelocity)
	{
		_velocity = -_maxVelocity;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		_currentFrame.y = 0;
	}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	//{
	//	_currentFrame.y = 1;
	//}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	//{
	//	_currentFrame.y = 2;
	//}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (_currentFrame.x == 0)
		{
			_currentFrame.x = ++_currentFrame.x%_frameCount.x;
		
		}
	}

	sf::Vector2f pos = this->getObjectPosition();

	if (pos.x<getSprite().getScale().x / 2)
	{
		_velocity = 1.0f;
	}
	else if (pos.x > (800 - getSprite().getScale().x/2))
	{
		_velocity = -1.0f;
	}


	getSprite().setTextureRect(sf::IntRect(_currentFrame.x*_frameSize.x, _currentFrame.y*_frameSize.y, _frameSize.x, _frameSize.y));
	getSprite().move(_velocity*elapsedTime, 0);

}