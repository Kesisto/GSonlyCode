#include "GSGameObjectManager.h"


groundSupport::GSGameObjectManager::GSGameObjectManager()
{
}


groundSupport::GSGameObjectManager::~GSGameObjectManager()
{
	std::for_each(_gameObjects.begin(), _gameObjects.end(), GameObjectDeallocator());
}

void groundSupport::GSGameObjectManager::GSAdd(std::string name, groundSupport::GSGameObject* gameObject)
{
	_gameObjects.insert(std::pair<std::string, groundSupport::GSGameObject*>(name, gameObject));
}

void groundSupport::GSGameObjectManager::GSRemove(std::string name)
{
	std::map<std::string, groundSupport::GSGameObject*>::iterator results = _gameObjects.find(name);
	if (results != _gameObjects.end())
	{
		delete results->second;
		_gameObjects.erase(results);
	}
}

groundSupport::GSGameObject* groundSupport::GSGameObjectManager::getObject(std::string name)const
{
	std::map<std::string, groundSupport::GSGameObject*>::const_iterator results = _gameObjects.find(name);
	if (results == _gameObjects.end())
	{
		return NULL;
	}
	return results->second;
}

int groundSupport::GSGameObjectManager::getObjectCount()const
{
	return _gameObjects.size();
}

void groundSupport::GSGameObjectManager::GSDrawAll(sf::RenderWindow& renderwindow)
{
	std::map<std::string, groundSupport::GSGameObject*>::const_iterator renderIt = _gameObjects.begin();
	while (renderIt != _gameObjects.end())
	{
		renderIt->second->objectDraw(renderwindow);
		renderIt++;
	}
}

void groundSupport::GSGameObjectManager::GSUpdateAll()
{
	std::map<std::string, groundSupport::GSGameObject*>::const_iterator renderIt = _gameObjects.begin();
	sf::Clock clock;
	float lastTime = 0;
	float currentTime = clock.restart().asSeconds();
	float fps = 1.f / (currentTime - lastTime);
	lastTime = currentTime;
	while (renderIt!=_gameObjects.end())
	{
		renderIt->second->updateObject(fps/fps);
		renderIt++;
		
	}
}