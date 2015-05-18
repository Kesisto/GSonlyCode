#pragma once
#include "GSIncludes.h"
namespace groundSupport
{
	class GSClock
	{
	public:
		GSClock(float fp5, float cT, float lT) :fps(fp5), lastTime(lT){};
		GSClock() :fps(0.0f), lastTime(0.0f){};
		~GSClock(){};
		void clock()
		{
			sf::Clock clock;
			float currentTime = clock.restart().asSeconds();
			fps = 1.f / (currentTime - lastTime);
			lastTime = currentTime;
			std::cout << "fps: " << fps << "\n";
		};
	private:
		float fps;
		float lastTime;
	};
}
