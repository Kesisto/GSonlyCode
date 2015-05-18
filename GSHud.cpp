#include "GSHud.h"

groundSupport::GSHud::GSHud()
{
	std::ifstream inputFile("GSPoints.bin", std::ios::binary | std::ios::in);

	if (inputFile)
	{
		while (inputFile.peek() != EOF)
		{

		
			inputFile.read((char *)&_playerHealt, sizeof(int));
			inputFile.read((char *)&_score, sizeof(int));
		}

		inputFile.close();
		std::cout << _playerHealt << "\n";
	}
}

groundSupport::GSHud::~GSHud()
{
}
void groundSupport::GSHud::enemyHits()
{
	
	if (_playerHealt > 0)
	{
		_playerHealt -= 1;
	}
	std::ofstream outputFile("GSPoints.bin", std::ios::binary | std::ios::out);
	if (outputFile)
	{
		
		outputFile.write((char*)&_playerHealt, sizeof(int));
		outputFile.write((char*)&_score, sizeof(int));

		outputFile.close();
	}
		return;
}
void groundSupport::GSHud::enemyScore()
{
	if (_playerHealt > 0 && _score > 0)
	{
		_score -= 5;
	}
	std::ofstream outputFile("GSPoints.bin", std::ios::binary | std::ios::out);
	if (outputFile)
	{

		
		outputFile.write((char*)&_playerHealt, sizeof(int));
		outputFile.write((char*)&_score, sizeof(int));

		outputFile.close();
	}
	return;
}
void groundSupport::GSHud::enemyDestroyed()
{
	if (_playerHealt > 0)
	{
		_score += 10;
	}
	std::ofstream outputFile("GSPoints.bin", std::ios::binary | std::ios::out);
	if (outputFile)
	{

	
		outputFile.write((char*)&_playerHealt, sizeof(int));
		outputFile.write((char*)&_score, sizeof(int));

		outputFile.close();
	}
	return;
}


void groundSupport::GSHud::updateObject(float elapsedTime)
{
	
	std::ifstream inputFile("GSPoints.bin", std::ios::binary | std::ios::in);

	if (inputFile)
	{
		while (inputFile.peek() != EOF)
		{

	
			inputFile.read((char *)&_playerHealt, sizeof(int));
			inputFile.read((char *)&_score, sizeof(int));
		}

		inputFile.close();
		std::cout <<"Healt: "<< _playerHealt << "\n";
		std::cout <<"Score"<< _score << "\n";

	}	
}

void groundSupport::GSHud::setBinaries()
{

	_playerHealt = 5;
	_score = 0;
	std::ofstream outputFile("GSPoints.bin", std::ios::binary | std::ios::out);
	if (outputFile)
	{

	
		outputFile.write((char*)&_playerHealt, sizeof(int));
		outputFile.write((char*)&_score, sizeof(int));

		outputFile.close();
	}
	return;

}
//void groundSupport::GSHud::drawObject(sf::RenderWindow& renderwindow)
//{
//	if (!font.loadFromFile("batmfa_.ttf"))
//	{
//		std::cout << "Errof while loading font.\n";
//	}
//	Healt.setFont(font);
//	stream = std::to_string(_playerHealt);
//	Healt.setString("Healt ");
//	Healt.setCharacterSize(24);
//	Healt.setColor(sf::Color::Red);
//	Healt.setStyle(sf::Text::Bold | sf::Text::Underlined);
//	renderwindow.draw(Healt);
//
//	
//}