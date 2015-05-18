#ifndef GSGAMEOBJET_H
#define GSGAMEOBJET_H
#include "GSIncludes.h"


namespace groundSupport
{
	class GSGameObject
	{
	public:
		GSGameObject();
		virtual ~GSGameObject();

		virtual void objectLoad(std::string filename);
		virtual void objectDraw(sf::RenderWindow& window);
		virtual void updateObject(float elapsedTime);

		virtual void setObjectPosition(float x, float y);
		virtual sf::Vector2f getObjectPosition()const;
		virtual bool GsIsLoaded()const;

		virtual float getWidth() const;
		virtual float getHeight() const;
		virtual sf::Vector2i getTurret() const;

		virtual sf::Rect<float> getBoundingRect() const;

	protected:
		sf::Sprite& getSprite();

	private:
		sf::Sprite _sprite;
		sf::Texture _image;
		std::string _filename;
		bool _isLoaded;
		const sf::Vector2i _frameSize;
		const sf::Vector2i _frameCount;
		sf::Vector2i _currentFrame;

	};
}

#endif