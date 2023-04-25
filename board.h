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
	virtual bool isLegal(int row, int col) = 0;

	//tests if game is over
	virtual void isGameOver() = 0;

};


class TicTacBoard : public Board
{
	//3d array acts as board
private:
	//true = availible -- false = full
	int board[3][3];

public:

	bool isLegal(int row, int col)
	{
		if (board[row][col] == empty)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

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

	void runGame()
	{
		window.clear(Color::Black);

		////////////////////////////////////BUTTONS////////////////////////////////

		/////////top row/////////
		RectangleShape play_button(sf::Vector2f(300, 100));
		play_button.setPosition(450, 150);
		//.setFillColor(sf::Color::Transparent);




		//////////middle row//////
		//RectangleShape info_button(sf::Vector2f(300, 100));
		//info_button.setPosition(450, 350);
		//info_button.setFillColor(sf::Color::Transparent);


		//Text infoText("Info", font, 50);
		//infoText.setPosition(450, 350);
		//infoText.setFillColor(sf::Color::White);


		///////////bottom row/////////
		//RectangleShape exit_button(sf::Vector2f(300, 100));
		//exit_button.setPosition(450, 550);
		//exit_button.setFillColor(sf::Color::Transparent);


		//Text exitText("Exit Game", font, 50);
		//exitText.setPosition(450, 550);
		//exitText.setFillColor(sf::Color::White);
	}

};