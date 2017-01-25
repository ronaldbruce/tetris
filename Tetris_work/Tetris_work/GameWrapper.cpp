#include "GameWrapper.h"

GameWrapper::~GameWrapper()
{
	delete newPiece;
}

void GameWrapper::runGame()
{
	Display display;

	GameBoard gameBoard;

	bool placed = false;
	sf::RenderWindow window(sf::VideoMode(520, 900), "Tetris_2.1");
	sf::Event myEvent;
	sf::Music theme;

	theme.openFromFile("Tetris.ogg");
	theme.setVolume(30);
	theme.setLoop(true);
	theme.play();

	sf::SoundBuffer buffer;
	sf::Sound gameOverSound;

	buffer.loadFromFile("GameOver.wav");
	gameOverSound.setBuffer(buffer);

	sf::Font font;
	font.loadFromFile("ARDESTINE.ttf");
	
	newPiece = generatePiece();
	newPiece->spawnPiece(gameBoard);

	sf::Clock clock;
	clock.getElapsedTime();
	int stage = 1;

	sf::Color coolBlue(5, 234, 250);

	sf::Text final_score;
	final_score.setFont(font);
	final_score.setFillColor(coolBlue);
	final_score.setString(std::to_string(gameBoard.score));
	final_score.setCharacterSize(300);
	final_score.setPosition(105, -50);

	sf::Text gameOver;
	gameOver.setFont(font);
	gameOver.setFillColor(sf::Color::Black);
	gameOver.setString("Game\nOver");
	gameOver.setCharacterSize(100);
	gameOver.setPosition(150, 400);

	sf::Text warning;
	warning.setFont(font);
	warning.setFillColor(sf::Color::White);
	warning.setString("Avoid rotating while against left or right boundry.\nWeird shit will happen.");
	warning.setCharacterSize(20);
	warning.setPosition(10, 850);
	

	while (window.isOpen())
	{
		//creates gameTick
		sf::Time tick;
		tick = clock.getElapsedTime();
		float sec = tick.asSeconds();

		if (placed == true)
		{
			//sets the block at the coordinates where a "place" happened and sets its active to false
			gameBoard.gameArray[newPiece->block1.cordX][newPiece->block1.cordY].active = false;
			gameBoard.gameArray[newPiece->block2.cordX][newPiece->block2.cordY].active = false;
			gameBoard.gameArray[newPiece->block3.cordX][newPiece->block3.cordY].active = false;
			gameBoard.gameArray[newPiece->block4.cordX][newPiece->block4.cordY].active = false;
			checkline(gameBoard);

			if (gameBoard.isGameOver())
			{
				window.draw(gameOver);
				window.display();
				gameOverSound.play();
				theme.stop();
				Sleep(5000);
				window.close();
			}
			Sleep(100);
			newPiece = generatePiece();
			newPiece->spawnPiece(gameBoard);
			placed = false;
			stage = 1;
		}

		window.clear();
		display.displayBackground(window);

		//updates score on screen
		final_score.setString(std::to_string(gameBoard.score));
		window.draw(final_score);

		window.draw(warning);

		display.translateArray(window, gameBoard.gameArray);
		window.display();

		//resets the clock after 1 second. used for the constant falling
		//put anything in here you want to happen every second
		if ((int)sec == 1)
		{
			newPiece->move(gameBoard, DOWN, placed, stage);
			clock.restart();
		}
		while (window.pollEvent(myEvent))
		{
			if (myEvent.type == sf::Event::KeyPressed)
			{
				if (myEvent.key.code == sf::Keyboard::Left)
				{
					newPiece->move(gameBoard, LEFT, placed, stage);
				}
				else if (myEvent.key.code == sf::Keyboard::Right)
				{
					newPiece->move(gameBoard, RIGHT, placed, stage);
				}
				else if (myEvent.key.code == sf::Keyboard::Down)
				{
					newPiece->move(gameBoard, DOWN, placed, stage);
				}
				else if (myEvent.key.code == sf::Keyboard::Space && stage == 1)
				{
					stage = 2;
					newPiece->rotate(gameBoard, stage, placed);
				}
				else if (myEvent.key.code == sf::Keyboard::Space && stage == 2)
				{
					stage = 3;
					newPiece->rotate(gameBoard, stage, placed);
				}
				else if (myEvent.key.code == sf::Keyboard::Space && stage == 3)
				{
					stage = 4;
					newPiece->rotate(gameBoard, stage, placed);
				}
				else if (myEvent.key.code == sf::Keyboard::Space && stage == 4)
				{
					stage = 1;
					newPiece->rotate(gameBoard, stage, placed);
				}
				else if (myEvent.key.code == sf::Keyboard::Escape)
				{
					window.close();
				}
			}
		}
	}

}

Piece *& GameWrapper::generatePiece()
{
	int colorSelect = 0, pieceSelect = 0;
	char color;

	colorSelect = rand() % 3 + 1;
	pieceSelect = rand() % 7 + 1;

	switch (colorSelect) {
	case 1:
	{
		color = 'r';
		break;
	}
	case 2:
	{
		color = 'b';
		break;
	}
	case 3:
	{
		color = 'g';
		break;
	}
	}

	switch (pieceSelect) {
	//Square
	case 1:
	{
		Piece *newPiece = new SquarePiece(color);
		return newPiece;
		break;
	}
	//line
	case 2:
	{
		Piece *newPiece = new IPiece(color);
		return newPiece;
		break;
	}
	//J-block
	case 3:
	{
		Piece *newPiece = new JPiece(color);
		return newPiece;
		break;
	}
	//L-block
	case 4:
	{
		Piece *newPiece = new LPiece(color);
		return newPiece;
		break;
	}
	//S-block
	case 5:
	{
		Piece *newPiece = new SPiece(color);
		return newPiece;
		break;
	}
	//T-block
	case 6:
	{
		Piece *newPiece = new TPiece(color);
		return newPiece;
		break;
	}
	//Z-block
	case 7:
	{
		Piece *newPiece = new ZPiece(color);
		return newPiece;
		break;
	}
	}
}