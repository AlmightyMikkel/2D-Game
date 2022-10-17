#include <SFML/Graphics.hpp>
#include "player.h"

int main(int argc, char **argv)
{

	float delta_time = 0.0f;
	sf::Clock clock;

	Player player;

	sf::RenderWindow screen(sf::VideoMode(500, 500), "My game");


	while (screen.isOpen())
	{
		clock.restart().asSeconds();
		player.update(delta_time);


		sf::Event event;
		while (screen.pollEvent(event)) {

			if (event.type == sf::Event::Closed) screen.close();
			if (event.type == sf::Event::KeyPressed) player.input(event.key.code);
		}

		screen.clear(sf::Color::Black);
		
		player.render(screen);
		
		screen.display();

		delta_time = clock.getElapsedTime().asSeconds();
	}



   return 0;
}
