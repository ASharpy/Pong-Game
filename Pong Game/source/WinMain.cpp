#include <Windows.h>
#include <SFML/Graphics.hpp>

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow)
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Top of Window Text");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
   
		//Draw Shit in this
		sf::Texture texture;
		if (!texture.loadFromFile("Fireball.png"))
		{
			throw;
		}

		sf::Sprite sprite;
		sprite.setTexture(texture);

		window.draw(sprite);

		sprite.setScale(sf::Vector2f(400.0f, 1.0f));
		sprite.scale(sf::Vector2f(0.1f, 0.1f));
        window.display();
    }

    return 0;
}