#include "Display.h".

//traverses the array and displays the blocks according to their position and color value
//if no color value is given, no block will be drawn and the background will remain
void Display::translateArray(sf::RenderWindow &newWindow, Block gameArray[10][18])
{
	for (int y = 0; y < 18; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			if (gameArray[x][y].color == 'r')
			{
				newWindow.draw(this->createBlock(sf::Color::Red, x, y));
			}
			else if (gameArray[x][y].color == 'g')
			{
				newWindow.draw(this->createBlock(sf::Color::Green, x, y));
			}
			else if (gameArray[x][y].color == 'b')
			{
				newWindow.draw(this->createBlock(sf::Color::Blue, x, y));
			}
		}
	}

}

//displays a black screen as the background and draws the background white blocks
void Display::displayBackground(sf::RenderWindow &newWindow)
{
	sf::Color lightGrey(170, 170, 170);
	sf::Color lightWhite(255, 250, 240);
	sf::RectangleShape background;
	sf::RectangleShape block;

	background.setFillColor(Color::Black);
	background.setSize(sf::Vector2f(600, 900));
	newWindow.draw(background);
	
	for (int x = 0; x < 18; x++)
	{
		for (int i = 0; i < 10; i++)
		{
			block.setFillColor(lightWhite);
			block.setSize(sf::Vector2f(29, 29));
			block.setPosition(sf::Vector2f(110 + (i * 31), 812 -(x * 31)));
			block.setOutlineColor(lightGrey);
			block.setOutlineThickness(2.0);
			newWindow.draw(block);
		}
	}
}

////creates a block with the position specefied (converts from int to pixels) with the color given
sf::RectangleShape Display::createBlock(sf::Color newColor, int x, int y)
{
	sf::RectangleShape block;
	sf::Color lightGrey(170, 170, 170);
	block.setFillColor(newColor);
	block.setSize(sf::Vector2f(29, 29));
	block.setPosition(sf::Vector2f(110 + (x * 31), 812 - (y * 31)));
	block.setOutlineColor(lightGrey);
	block.setOutlineThickness(2.0);

	return block;
}
