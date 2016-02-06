#include "Main.h"

int main()
{
	//-- Create a simple SFML render window with a limited refresh rate. --//
	sf::RenderWindow window(sf::VideoMode(800, 600), "Tile Map Test", sf::Style::Close);
	window.setFramerateLimit(120);
	window.setKeyRepeatEnabled(false);


	//-- Give a simplified path to the Map folder. --//
	MapLoader ml("../TileTest/Maps");
	

	//-- Load the map and update the user through the console window. --//
	if (ml.Load("Testing.tmx"))
	{
		cout << "Loaded the map file Testing" << endl << endl;
	}


	//-- Create the view for the player --//

	//-- Camera Position --//
	float camX = 0;
	float camY = 0;
	
	sf::View mainCamera(sf::FloatRect(camX, camY, 400, 300));
	
	
	//-- Main Game Loop --//
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			//-- Check for Key Events --//
			if (event.type == sf::Event::KeyPressed)
			{

			}
		}


		
		

		window.clear(sf::Color::Black);

		//-- Set the view to the main Camera --//
		window.setView(mainCamera);

		//-- Draw the map object --//
		window.draw(ml);

		window.display();


	}




	//-- Uncomment this section to remove the console pause after the render window closes --//
	cout << "Thank You for Testing" << endl << endl;
	system("PAUSE");
	return 0;
}