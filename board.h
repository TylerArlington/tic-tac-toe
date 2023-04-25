#pragma once

#include "header.h"
#include "player.h"

#define player1 == 1;
#define player2 == 2;
#define empty == 0;

class Board 
{
public:
	//tests if the move is legal, if legal procede with move
	//virtual bool isLegal(int row, int col) = 0;

	//tests if game is over
	virtual bool isGameOver() = 0;

};


class TicTacBoard : public Board
{
	//3d array acts as board
private:
	//true = availible -- false = full
	int board[3][3];

public:

	/*bool isLegal(int row, int col)
	{
		if (board[row][col] == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}*/

	bool isGameOver()
	{
		////////////////check vertical///////////////
		if (board[1][1] == board[1][2] && board[1][3])
		{
			return true;
		}
		else if (board[2][1] == board[2][2] && board[2][3])
		{
			return true;
		}
		else if (board[3][1] == board[3][2] && board[3][3])
		{
			return true;
		}

		////////////////check horizontal///////////////
		else if (board[1][1] == board[2][1] && board[3][1])
		{
			return true;
		}
		else if (board[1][2] == board[2][2] && board[3][2])
		{
			return true;
		}
		else if (board[1][3] == board[2][2] && board[3][3])
		{
			return true;
		}

		////////////////check horizontal///////////////
		else if (board[1][1] == board[2][2] && board[3][3])
		{
			return true;
		}
		else if (board[3][1] == board[2][2] && board[1][3])
		{
			return true;
		}

		////////////////////Nothing////////////////////
		else
		{
			return false;
		}

	}

	void runGame(RenderWindow& window)
	{

		////////////////////////////////////BUTTONS////////////////////////////////

		/////////top row/////////
		RectangleShape topleft(Vector2f(150, 150));
		topleft.setPosition(255, 120);
		topleft.setFillColor(Color::Transparent);

		RectangleShape topmid(Vector2f(170, 150));
		topmid.setPosition(420, 120);
		topmid.setFillColor(Color::Transparent);

		RectangleShape topright(Vector2f(150, 150));
		topright.setPosition(600, 120);
		topright.setFillColor(Color::Transparent);


		//////////middle row//////
		RectangleShape midleft(Vector2f(155, 180));
		midleft.setPosition(255, 280);
		midleft.setFillColor(Color::Transparent);

		RectangleShape midmid(Vector2f(175, 180));
		midmid.setPosition(420, 280);
		midmid.setFillColor(Color::Transparent);

		RectangleShape midright(Vector2f(155, 180));
		midright.setPosition(600, 280);
		midright.setFillColor(Color::Transparent);


		///////////bottom row/////////
		RectangleShape botleft(Vector2f(155, 150));
		botleft.setPosition(255, 475);
		botleft.setFillColor(Color::Transparent);

		RectangleShape botmid(Vector2f(175, 150));
		botmid.setPosition(420, 475);
		botmid.setFillColor(Color::Transparent);

		RectangleShape botright(Vector2f(155, 150));
		botright.setPosition(607, 472);
		botright.setFillColor(Color::Transparent);



		Texture gameBackground;
		if (!gameBackground.loadFromFile("game1.1.png"))
		{
			std::cout << "Failed to load image!" << std::endl;
		}

		Sprite background(gameBackground);
		background.setPosition(0, 0);


		Texture X;
		if (!X.loadFromFile("X.png"))
		{
			std::cout << "Failed to load image!" << std::endl;
		}

		Sprite PlayerX(X);

		while (window.isOpen())
		{
			// Process events
			Event event;
			while (window.pollEvent(event))
			{
				// Check for user input
				if (event.type == Event::MouseButtonPressed)
				{

					///////////////////////////////////////top////////////////////////////////////////
					// Check if the mouse is over the top left
					if (topleft.getGlobalBounds().contains(Vector2f(event.mouseButton.x, event.mouseButton.y)))
					{
						cout << "click registered top left" << "\n";

					}

					// Check if the mouse is over the top middle
					if (topmid.getGlobalBounds().contains(Vector2f(event.mouseButton.x, event.mouseButton.y)))
					{
						cout << "click registered top mid" << "\n";

					}

					// Check if the mouse is over the top right
					if (topright.getGlobalBounds().contains(Vector2f(event.mouseButton.x, event.mouseButton.y)))
					{
						cout << "click registered top right" << "\n";

					}

					///////////////////////////////////////mid////////////////////////////////////////////

					// Check if the mouse is over the start button
					if (midleft.getGlobalBounds().contains(Vector2f(event.mouseButton.x, event.mouseButton.y)))
					{
						cout << "click registered mid left" << "\n";

					}

					// Check if the mouse is over the start button
					if (midmid.getGlobalBounds().contains(Vector2f(event.mouseButton.x, event.mouseButton.y)))
					{
						cout << "click registered mid middle" << "\n";

					}

					// Check if the mouse is over the start button
					if (midright.getGlobalBounds().contains(Vector2f(event.mouseButton.x, event.mouseButton.y)))
					{
						cout << "click registered mid right" << "\n";

					}

					////////////////////////////////////////bot///////////////////////////////////////////


					if (botleft.getGlobalBounds().contains(Vector2f(event.mouseButton.x, event.mouseButton.y)))
					{
						cout << "click registered bottom left" << "\n";

					}

					// Check if the mouse is over the start button
					if (botmid.getGlobalBounds().contains(Vector2f(event.mouseButton.x, event.mouseButton.y)))
					{
						cout << "click registered bot middle" << "\n";

					}

					// Check if the mouse is over the start button
					if (botright.getGlobalBounds().contains(Vector2f(event.mouseButton.x, event.mouseButton.y)))
					{
						cout << "click registered bottom right" << "\n";

					}

				}
				else if (event.type == Event::Closed)
				{
					// Close the window
					window.close();
				}
			}
			window.clear(Color::Black);

			window.draw(background);

			window.draw(topleft);
			window.draw(topmid);
			window.draw(topright);

			window.draw(midleft);
			window.draw(midmid);
			window.draw(midright);

			window.draw(botleft);
			window.draw(botmid);
			window.draw(botright);

			window.display();
		}
	}
};
