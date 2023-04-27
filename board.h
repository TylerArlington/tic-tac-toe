
#pragma once

#include "header.h"
#include "player.h"


class Board
{
public:



	//tests if game is over
	virtual bool isGameOver() = 0;

};


class TicTacBoard : public Board
{
public:
	//true = availible -- false = full
	int board[3][3] = { {0,0,0} , {0,0,0} , {0,0,0} };


	bool isGameOver()
	{
		////////////////check vertical///////////////
		if (board[0][0] == board[0][1] && board[0][2] != 0)
		{
			return true;
		}
		else if (board[1][0] == board[1][1] && board[1][2] != 0)
		{
			return true;
		}
		else if (board[2][0] == board[2][1] && board[2][2] != 0)
		{
			return true;
		}

		////////////////check horizontal///////////////
		else if (board[0][0] == board[1][0] && board[2][0] != 0)
		{
			return true;
		}
		else if (board[0][1] == board[1][1] && board[2][1] != 0)
		{
			return true;
		}
		else if (board[0][2] == board[1][1] && board[2][2] != 0)
		{
			return true;
		}

		////////////////check horizontal///////////////
		else if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[2][0] != 0)
		{
			return true;
		}
		else if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[2][1] != 0)
		{
			return true;
		}
		else if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[2][2] != 0)
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
	
		Sprite PlayerX1(X);
		PlayerX1.setPosition(1500, 1500);//set it offscreen
		Sprite PlayerX2(X);
		PlayerX2.setPosition(1500, 1500);//set it offscreen
		Sprite PlayerX3(X);
		PlayerX3.setPosition(1500, 1500);//set it offscreen
		Sprite PlayerX4(X);
		PlayerX4.setPosition(1500, 1500);//set it offscreen
		Sprite PlayerX5(X);
		PlayerX5.setPosition(1500, 1500);//set it offscreen
		Sprite PlayerX6(X);
		PlayerX6.setPosition(1500, 1500);//set it offscreen
		Sprite PlayerX7(X);
		PlayerX7.setPosition(1500, 1500);//set it offscreen
		Sprite PlayerX8(X);
		PlayerX8.setPosition(1500, 1500);//set it offscreen
		Sprite PlayerX9(X);
		PlayerX9.setPosition(1500, 1500);//set it offscreen
		
		Texture O;
		if (!O.loadFromFile("O.png"))
		{
			std::cout << "Failed to load image!" << std::endl;
		}

		Sprite PlayerO1(O);
		PlayerO1.setPosition(1500, 1500);//set it offscreen
		Sprite PlayerO2(O);
		PlayerO2.setPosition(1500, 1500);//set it offscreen
		Sprite PlayerO3(O);
		PlayerO3.setPosition(1500, 1500);//set it offscreen
		Sprite PlayerO4(O);
		PlayerO4.setPosition(1500, 1500);//set it offscreen
		Sprite PlayerO5(O);
		PlayerO5.setPosition(1500, 1500);//set it offscreen
		Sprite PlayerO6(O);
		PlayerO6.setPosition(1500, 1500);//set it offscreen
		Sprite PlayerO7(O);
		PlayerO7.setPosition(1500, 1500);//set it offscreen
		Sprite PlayerO8(O);
		PlayerO8.setPosition(1500, 1500);//set it offscreen
		Sprite PlayerO9(O);
		PlayerO9.setPosition(1500, 1500);//set it offscreen




		humanPlayer player1;
		computerPlayer player2;

		int xcoord = 0;
		int ycoord = 0;



		while (window.isOpen())
		{
			// Process events
			Event event;
			while (window.pollEvent(event))
			{

				while (isGameOver() == false)
				{

					// Check for user input
					if (event.type == Event::MouseButtonPressed)
					{

						///////////////////////////////////////top////////////////////////////////////////
						// Check if the mouse is over the top left
						if (topleft.getGlobalBounds().contains(Vector2f(event.mouseButton.x, event.mouseButton.y)))
						{
							cout << "click registered top left" << "\n";

							int Eventx = event.mouseButton.x;
							int Eventy = event.mouseButton.y;

							xcoord = 0;
							ycoord = 0;

							player1.makeMove(board, xcoord, ycoord, 1, window, PlayerX1, Eventx, Eventy);

							player2.makeMove(board, xcoord, ycoord, 2, window, PlayerO1, Eventx, Eventy);
						}

						// Check if the mouse is over the top middle
						if (topmid.getGlobalBounds().contains(Vector2f(event.mouseButton.x, event.mouseButton.y)))
						{
							cout << "click registered top mid" << "\n";

							int Eventx = event.mouseButton.x;
							int Eventy = event.mouseButton.y;

							xcoord = 0;
							ycoord = 1;

							player1.makeMove(board, xcoord, ycoord, 1, window, PlayerX2, Eventx, Eventy);

							player2.makeMove(board, xcoord, ycoord, 2, window, PlayerO2, Eventx, Eventy);


						}

						// Check if the mouse is over the top right
						if (topright.getGlobalBounds().contains(Vector2f(event.mouseButton.x, event.mouseButton.y)))
						{
							cout << "click registered top right" << "\n";

							int Eventx = event.mouseButton.x;
							int Eventy = event.mouseButton.y;

							xcoord = 0;
							ycoord = 2;

							player1.makeMove(board, xcoord, ycoord, 1, window, PlayerX3, Eventx, Eventy);

							player2.makeMove(board, xcoord, ycoord, 2, window, PlayerO3, Eventx, Eventy);
						}

						///////////////////////////////////////mid////////////////////////////////////////////

						// Check if the mouse is over the start button
						if (midleft.getGlobalBounds().contains(Vector2f(event.mouseButton.x, event.mouseButton.y)))
						{
							cout << "click registered mid left" << "\n";

							int Eventx = event.mouseButton.x;
							int Eventy = event.mouseButton.y;

							xcoord = 1;
							ycoord = 0;

							player1.makeMove(board, xcoord, ycoord, 1, window, PlayerX4, Eventx, Eventy);

							player2.makeMove(board, xcoord, ycoord, 2, window, PlayerO4, Eventx, Eventy);
						}

						// Check if the mouse is over the start button
						if (midmid.getGlobalBounds().contains(Vector2f(event.mouseButton.x, event.mouseButton.y)))
						{
							cout << "click registered mid middle" << "\n";

							int Eventx = event.mouseButton.x;
							int Eventy = event.mouseButton.y;

							xcoord = 1;
							ycoord = 1;

							player1.makeMove(board, xcoord, ycoord, 1, window, PlayerX5, Eventx, Eventy);

							player2.makeMove(board, xcoord, ycoord, 2, window, PlayerO5, Eventx, Eventy);
						}

						// Check if the mouse is over the start button
						if (midright.getGlobalBounds().contains(Vector2f(event.mouseButton.x, event.mouseButton.y)))
						{
							cout << "click registered mid right" << "\n";

							int Eventx = event.mouseButton.x;
							int Eventy = event.mouseButton.y;

							xcoord = 1;
							ycoord = 2;

							player1.makeMove(board, xcoord, ycoord, 1, window, PlayerX6, Eventx, Eventy);

							player2.makeMove(board, xcoord, ycoord, 2, window, PlayerO6, Eventx, Eventy);
						}

						////////////////////////////////////////bot///////////////////////////////////////////


						if (botleft.getGlobalBounds().contains(Vector2f(event.mouseButton.x, event.mouseButton.y)))
						{
							cout << "click registered bottom left" << "\n";

							int Eventx = event.mouseButton.x;
							int Eventy = event.mouseButton.y;

							xcoord = 2;
							ycoord = 0;

							player1.makeMove(board, xcoord, ycoord, 1, window, PlayerX7, Eventx, Eventy);

							player2.makeMove(board, xcoord, ycoord, 2, window, PlayerO7, Eventx, Eventy);
						}

						// Check if the mouse is over the start button
						if (botmid.getGlobalBounds().contains(Vector2f(event.mouseButton.x, event.mouseButton.y)))
						{
							cout << "click registered bot middle" << "\n";

							int Eventx = event.mouseButton.x;
							int Eventy = event.mouseButton.y;

							xcoord = 2;
							ycoord = 1;

							player1.makeMove(board, xcoord, ycoord, 1, window, PlayerX8, Eventx, Eventy);

							player2.makeMove(board, xcoord, ycoord, 2, window, PlayerO8, Eventx, Eventy);
						}

						// Check if the mouse is over the start button
						if (botright.getGlobalBounds().contains(Vector2f(event.mouseButton.x, event.mouseButton.y)))
						{
							cout << "click registered bottom right" << "\n";

							int Eventx = event.mouseButton.x;
							int Eventy = event.mouseButton.y;

							xcoord = 2;
							ycoord = 2;

							player1.makeMove(board, xcoord, ycoord, 1, window, PlayerX9, Eventx, Eventy);

							player2.makeMove(board, xcoord, ycoord, 2, window, PlayerO9, Eventx, Eventy);
						}

					}

					else if (event.type == Event::Closed)
					{
						// Close the window
						window.close();
					}
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

			window.draw(PlayerX1);
			window.draw(PlayerX2);
			window.draw(PlayerX3);
			window.draw(PlayerX4);
			window.draw(PlayerX5);
			window.draw(PlayerX6);
			window.draw(PlayerX7);
			window.draw(PlayerX8);
			window.draw(PlayerX9);

			window.draw(PlayerO1);
			window.draw(PlayerO2);
			window.draw(PlayerO3);
			window.draw(PlayerO4);
			window.draw(PlayerO5);
			window.draw(PlayerO6);
			window.draw(PlayerO7);
			window.draw(PlayerO8);
			window.draw(PlayerO9);

			window.display();
		}
	}
};
