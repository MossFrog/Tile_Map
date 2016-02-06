#include "Main.h"

int main()
{
	//-- Create a simple SFML render window with a limited refresh rate. --//
	//-- The main window contains the whole map --//
	//-- The Second render window represents the player's viewpoint --//
	sf::RenderWindow window(sf::VideoMode(800, 600), "Tile Map Test", sf::Style::Close);
	sf::RenderWindow playerView(sf::VideoMode(400, 300), "Player View", sf::Style::Titlebar);

	window.setFramerateLimit(120);
	window.setKeyRepeatEnabled(false);

	playerView.setFramerateLimit(120);
	playerView.setKeyRepeatEnabled(false);

	//-- Below are the integers used to prevent the camera from leaving the boundaries of the map. --//
	int xpos = 0;
	int ypos = 0;

	//-- Give a simplified path to the Map folder. --//
	MapLoader ml("../TileTest/Maps");
	

	//-- Load the map and update the user through the console window. --//
	if (ml.Load("Testing.tmx"))
	{
		cout << "Loaded the map file 'Testing.tmx'" << endl << endl;
	}


	//-- Create the view for the player --//
	sf::View mainCamera(sf::FloatRect(0, 0, 400, 300));
	
	
	//-- Main Game Loop --//
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{ 
				window.close();
				playerView.close();
			}
				

			//-- Check for Key Events --//
			if (event.type == sf::Event::KeyPressed)
			{

			}
		}


		//-- Shift the camera depending on the input --//
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&& xpos < 600)
		{
			mainCamera.move(1, 0);
			xpos++;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && xpos > 0)
		{
			mainCamera.move(-1, 0);
			xpos--;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && ypos > 0)
		{
			mainCamera.move(0, -1);
			ypos--;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && ypos < 800)
		{
			mainCamera.move(0, 1);
			ypos++;
		}
		
		

		window.clear(sf::Color::Black);

		//-- Draw the map object --//
		window.draw(ml);

		window.display();

		playerView.clear(sf::Color::Black);

		//-- Set the player view to the main Camera --//
		playerView.setView(mainCamera);

		playerView.draw(ml);

		playerView.display();

		//-- Note that the second render window 'playerView' has completely seperate draw methods --//
		//-- This is solely for demonstration purposes --//

	}




	//-- Uncomment this section to remove the console pause after the render window closes --//
	cout << "Thank You for Testing" << endl << endl;
	system("PAUSE");
	return 0;
}