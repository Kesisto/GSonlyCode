#ifndef GSGAMEOBJECTMANAGER_H
#define GSGAMEOBJECTMANAGER_H
#include "GSIncludes.h"
#include "GSGameObject.h"



namespace groundSupport
{
	class GSGameObjectManager
	{
	public:
		GSGameObjectManager();
		~GSGameObjectManager();

		void GSAdd(std::string name,groundSupport::GSGameObject* gameObject);
		void GSRemove(std::string name);

		int getObjectCount() const;
		groundSupport::GSGameObject* getObject(std::string name)const;

		void GSDrawAll(sf::RenderWindow& renderwindow);
		void GSUpdateAll();

	private:
		std::map<std::string, groundSupport::GSGameObject*> _gameObjects;

		struct GameObjectDeallocator
		{
			void operator()(const std::pair<std::string, groundSupport::GSGameObject*> _gO)const
			{
				delete _gO.second;
			}
		};

	};
}

#endif