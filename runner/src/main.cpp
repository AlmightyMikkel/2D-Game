#include <SFML/Graphics.hpp>
#include "player.h"

int main(int argc, char **argv)
{

	Player player;

	sf::RenderWindow screen(sf::VideoMode(500, 500), "My game");


	while (screen.isOpen())
	{

		player.update();
		player.Move();


		sf::Event event;
		while (screen.pollEvent(event)) {

			if (event.type == sf::Event::Closed) screen.close();

		}

		screen.clear(sf::Color::Black);
		
		player.render(screen);
		
		screen.display();
	}



   return 0;
}
