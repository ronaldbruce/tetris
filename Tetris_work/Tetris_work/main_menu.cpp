#include "main_menu.h"
#include <SFML/Graphics.hpp>

void MainMenu::main_menu()
{
	GameWrapper game;

	sf::RenderWindow window(sf::VideoMode(300, 450), "MAIN MENU");

	sf::Font font;
	sf::Font arial_font;
	font.loadFromFile("ARDESTINE.ttf");
	arial_font.loadFromFile("arial.ttf");

	sf::Text header; // code for header 
	header.setFont(font);
	header.setFillColor(sf::Color::White);
	header.setString("Tetris Main Menu");
	header.setCharacterSize(25);
	header.setPosition(45, 5);

	sf::Text start; // code for "startgame string"
	start.setFont(arial_font);
	start.setFillColor(sf::Color::White);
	start.setString("Start Game\n(press spacebar)");
	start.setCharacterSize(15);
	start.setPosition(110, 315);

	sf::Text exit; // code for "exit game string"
	exit.setFont(arial_font);
	exit.setFillColor(sf::Color::White);
	exit.setString("exit Game\n(press esc)");
	exit.setCharacterSize(15);
	exit.setPosition(110, 350);

	sf::Texture tetris_img;
	tetris_img.loadFromFile("tetris_background.jpg");
	sf::Sprite background(tetris_img);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Space)
				{
					// run game
					game.runGame();
				}
				else if (event.key.code == sf::Keyboard::Escape)
				{
					// exit game
					window.close();
				}
			}
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

		}

		window.clear();
		window.draw(background);
		window.draw(header);
		window.draw(start);
		window.draw(exit);
		window.display();
	}
}

void MainMenu::game_over_window(int finalScore)
{

	sf::RenderWindow window(sf::VideoMode(1280, 720), "GAME OVER");
	sf::Font arial_font;
	arial_font.loadFromFile("arial.ttf");

	sf::Text final_score; // code for "final score"
	final_score.setFont(arial_font);
	final_score.setFillColor(sf::Color::White);
	final_score.setString("Final Score: " + std::to_string(finalScore));
	final_score.setCharacterSize(15);
	final_score.setPosition(110, 315);


	sf::Texture tetris_img;
	tetris_img.loadFromFile("game-over.png");
	sf::Sprite background(tetris_img);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

		}

		window.clear();
		window.draw(background);
		window.draw(final_score);
		window.display();
	}
}