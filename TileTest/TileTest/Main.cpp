#include "Main.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Tile Map Test", sf::Style::Close);
	window.setFramerateLimit(120);
	window.setKeyRepeatEnabled(false);

	MapLoader ml("../TileTest/Maps");
	
	if (ml.Load("Testing.tmx"))
	{
		cout << "Loaded the map file Testing" << endl << endl;
	}
	

	
	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
			{

			}
		}

		window.clear(sf::Color::Black);

		window.draw(ml);

		window.display();


	}




	//-- Uncomment this section to remove the console pause after the render window closes --//
	cout << "Thank You for Testing" << endl << endl;
	system("PAUSE");
	return 0;
}