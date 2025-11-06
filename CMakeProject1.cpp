// CMakeProject1.cpp : définit le point d'entrée de l'application.

#include <iostream>
#include "SFML/Graphics.hpp"
#include <optional>
#include "CMakeProject1.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "Cmake Project"/*,sf::State::Fullscreen*/);
	
	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}
			if (event->is<sf::Event::Resized>())
			{
			}
		}
		// UPDATE HERE
		window.clear(sf::Color::Black);
		// DRAW HERE
		window.display();
	}
	return 0;
}