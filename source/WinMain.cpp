#include <Windows.h>
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Ball.h"
#include "Paddle.h"
std::string getExecutableFolder()
{
	char buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	char *pos;
	if (pos = strrchr(buffer, '\\'))
	{
		*pos = 0;
	}

	return buffer;
}

void update(float deltaTime)
{

}


int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow)
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Top of Window Text");
	sf::Clock deltaClock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

		sf::Time deltaTime = deltaClock.restart();
		deltaTime.asSeconds();
        window.clear();
   
		//Draw Shit in this
		sf::Texture fireball;
		if (!fireball.loadFromFile(getExecutableFolder() + "\\resources\\Textures\\Fireball.png"))
		{
			std::cout<<"dadad";
		}

		sf::Sprite sprite;
		sprite.setTexture(fireball);

		window.draw(sprite);
        window.display();
    }

    return 0;
}