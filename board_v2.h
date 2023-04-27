// New method for isGameOver

	static const int EMPTY = 0;
	static const int Player_X = 1; // 1st player
	static const int Player_O = 2; // 2nd player
	int board[3][3] = { {EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY} }; // 3x3 board
	
	bool isGameOverV2()
	{
		// Check for horizontal win
		for (int row = 0; row < 3; ++row) // Loop through rows of board to check for win
		{
			if (board[row][0] == board[row][1] && board[row][1] == board[row][2] && board[row][0] != EMPTY)
			{
				return true;
			}
		}

		// Check for vertical win
		for (int col = 0; col < 3; ++col) // Loop through columns of board to check for win
		{
			if (board[0][col] == board[1][col] && board[1][col] == board[2][col] && board[0][col] != EMPTY)
			{
				return true;
			}
		}

		// Check for diagonal win
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != EMPTY)
		{
			return true;
		}
		else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != EMPTY)
		{
			return true;
		}

		// Check for tie
		bool tie = true;
		for (int row = 0; row < 3; ++row) // Loop through rows of board to check for tie
		{
			for (int col = 0; col < 3; ++col) // Loop through columns of board to check for tie
			{
				if (board[row][col] == EMPTY)
				{
					tie = false;
				}
			}
		}
		if (tie)
		{
			return true;
		}
		
		// No winner or tie
		return false;
	}
