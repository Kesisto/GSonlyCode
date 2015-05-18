#include "GSGameObject.h"


groundSupport::GSGameObject::GSGameObject() :_isLoaded(false), _frameSize(334, 334), _frameCount(3, 9), _currentFrame(0, 0)
{
	
}


groundSupport::GSGameObject::~GSGameObject()
{
}

void groundSupport::GSGameObject::objectLoad(std::string filename)
{
	if (_image.loadFromFile(filename) == false)
	{
		_filename = "";
		_isLoaded = false;
	}
	else
	{
		_filename = filename;
		_sprite.setTexture(_image);
		_isLoaded = true;
		_sprite.setTexture(_image);
		_sprite.setOrigin(0.5f*_frameSize.x, 0.5f*_frameSize.y);
		_sprite.setTexture(_image);
		_sprite.setTextureRect(sf::IntRect(_currentFrame.x*_frameSize.x, _currentFrame.y*_frameSize.y, _frameSize.x, _frameSize.y));

	}
}


void groundSupport::GSGameObject::objectDraw(sf::RenderWindow & renderwindow)
{
	if (_isLoaded)
	{
		renderwindow.draw(_sprite);
	}
}

void groundSupport::GSGameObject::updateObject(float elapsedTime)
{

}

void groundSupport::GSGameObject::setObjectPosition(float x, float y)
{
	if (_isLoaded)
	{
		_sprite.setPosition(x, y);
	}
}

sf::Vector2f groundSupport::GSGameObject::getObjectPosition()const
{
	if (_isLoaded)
	{
		return _sprite.getPosition();
	}
	return sf::Vector2f();
}

sf::Sprite& groundSupport::GSGameObject::getSprite()
{
	return _sprite;
}

bool groundSupport::GSGameObject::GsIsLoaded()const
{
	return _isLoaded;
}

float groundSupport::GSGameObject::getHeight() const
{
	return _sprite.getLocalBounds().height;
}

float groundSupport::GSGameObject::getWidth() const
{
	return _sprite.getLocalBounds().width;;
}

sf::Rect<float> groundSupport::GSGameObject::getBoundingRect() const
{
	return _sprite.getGlobalBounds();
}
sf::Vector2i groundSupport::GSGameObject::getTurret() const
{
	return _currentFrame;
}
