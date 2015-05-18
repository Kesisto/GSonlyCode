#include "GSEnemyFighter.h"

groundSupport::GSEnemyFighter::GSEnemyFighter() :_velocity(25), _frameSize(334, 334), _frameCount(3, 3), _currentFrame(0, 0), _armor(3), _distance(0.0f), _fallVelocity(1.0f), _magazine(0.0f), _burst(0.0f)
{
	objectLoad("Assets/Textures/GSFighter.png");
	assert(GsIsLoaded());

	getSprite().setOrigin(getSprite().getScale().x / 2, getSprite().getScale().y / 2);
}


groundSupport::GSEnemyFighter::~GSEnemyFighter()
{
}

void groundSupport::GSEnemyFighter::drawObject(sf::RenderWindow & renderwindow)
{
	groundSupport::GSGameObject::objectDraw(renderwindow);
}

float groundSupport::GSEnemyFighter::getObjectVelocity()const
{

	return _velocity;
}

void groundSupport::GSEnemyFighter::updateObject(float elapsedTime)
{

	if (_armor > 0)
	{
		_currentFrame.x = 0;
	}
	if (_armor <= 0)
	{
		if (_currentFrame.x == 0 && _currentFrame.y == 2){ _currentFrame.x = 1; }
		else if (_currentFrame.x == 2 && _currentFrame.y == 1){ _currentFrame.x = 0; _currentFrame.y = 2; }
		else if (_currentFrame.x == 1 && _currentFrame.y == 1){ _currentFrame.x = 2; }
		else if (_currentFrame.y == 1){ _currentFrame.x = 1; }
		else if (_currentFrame.x == 2 && _currentFrame.y == 0){ _currentFrame.x = 0; _currentFrame.y = 1; }
		else if (_currentFrame.x == 0){ _currentFrame.x = 2; }
		
	}
	groundSupport::GSHud _hud;
	const GSPlayer* pBound = static_cast<GSPlayer*>
		(groundSupport::GSRun::getGSGameObjectManager().getObject("Player1"));
	sf::Vector2f _playerPosition = pBound->getObjectPosition();
	sf::Vector2f pos = this->getObjectPosition();
	
	_distance = (pos.y / 100) * 0.3f;
	
	_magazine += elapsedTime;
	if (getObjectPosition().x + 200 * _distance > _playerPosition.x && getObjectPosition().x - 200 * _distance  < _playerPosition.x)
	{
		if (_magazine <= 1.0f)
		{
			_currentFrame.x = 1;
		}
	}
	if (_magazine >= 5.0f)
	{
		_magazine = 0.0f;
	}

	if (getObjectPosition().x + 100 * _distance > _playerPosition.x && getObjectPosition().x - 100 * _distance  < _playerPosition.x)
	{
		if (_currentFrame.x == 1)
		{
			if (int i = rand() % 2 + 1 == 1)
			{
			
				_hud.enemyHits();
			}
		}
		if (int i = rand() % 50 + 1 < 5)
		{
			_velocity *= -1.0f;
		}
		if (_armor > 0)
			{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			
				_armor--;
				_currentFrame.x = 2;
			} 
		}
	}

	if (_currentFrame.x == 1 && _currentFrame.y == 2||pos.y>786)
	{ 
		if (_currentFrame.x == 1 && _currentFrame.y == 2)
		{
			_hud.enemyDestroyed();
		}
		if (pos.y > 785)
		{
			_hud.enemyScore();
		}
		setObjectPosition(groundSupport::GSRun::Screen_Width / 2, -20/*0*/);
		_armor = 3;
		_currentFrame.x = 0;
		_currentFrame.y = 0;
		_velocity += 0.25f;
		if (_fallVelocity < 10.0f)
	{
		_fallVelocity += 0.5f;
	}
	}
	
			if (pos.x < (getSprite().getScale().x / 2))
			{
				_velocity *= -1.0f;
			}
			else if (pos.x > (1024-getSprite().getScale().x))
			{
				_velocity *= -1.0f;
			}

			_burst = 0.0f;
			if (pos.y > 300)
			{
				_burst = _fallVelocity*10;
			}
			


			getSprite().move(_velocity*elapsedTime,(_burst + _fallVelocity)*elapsedTime);
			getSprite().setScale(_distance,_distance);	
			getSprite().setTextureRect(sf::IntRect(_currentFrame.x*_frameSize.x, _currentFrame.y*_frameSize.y, _frameSize.x, _frameSize.y));
		
	

}