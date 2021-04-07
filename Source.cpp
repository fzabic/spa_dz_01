#include <SFML/Graphics.hpp>
#include"Cvijet.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!");
	window.setFramerateLimit(60);
	Cvijet cvijet(&window);

	int brzina = 100.0f;
	int y= 100.0f;

	sf::Clock clock;

	while (window.isOpen())
	{
		auto Timer = clock.restart();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		y += brzina * Timer.asSeconds();

		if (y >= 700.0f || y <= 50.0f)
		{
			brzina *= -1.0f;
		}

		window.clear();
		cvijet.draw(y);
		window.display();
	}

	return 0;
}