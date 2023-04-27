
#include "header.h"


class player {
protected:
    // Add any protected member variables and functions here

public:
    virtual void makeMove(int(&board)[3][3], int x, int y, int player, RenderWindow& window, Sprite& sprite) = 0;  // Define an abstract function to make a move
};

class humanPlayer : public player {
protected:
    // Add any protected member variables and functions here

public:
    void makeMove(int(&board)[3][3], int x, int y, int player, RenderWindow& window, Sprite& sprite) override
    {
        // Check if move is valid
        
        if (board[x][y] != 0 || x < 0 || x >= 3 || y < 0 || y >= 3) 
        {
            // Invalid move, do nothing
            return;
        }

        board[x][y] = player;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                std::cout << board[i][j] << " ";
            }
            std::cout << std::endl;
        }
      
    }
};

class computerPlayer : public player {
protected:
    // Add any protected member variables and functions here

public:
    void makeMove(int(&board)[3][3], int x, int y, int player, RenderWindow& window, Sprite& sprite)override
    {
        srand(time(0));

        // Check if move is valid
        do
        {
            // Generate a random row and column
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != 0); // Repeat until a valid move is found


        // Place the number on the grid
        board[x][y] = player;

        int xcoord = 0;
        int ycoord = 0;

        if (x == 0)
        {
            xcoord = 255;
        }
        else if (x == 1)
        {
            xcoord = 420;
        }
        else if (x == 2)
        {
            xcoord = 600;
        }

        if (y == 0)
        {
            ycoord = 120;
        }
        else if (y == 1)
        {
            ycoord = 280;
        }
        else if (y == 2)
        {
            ycoord = 475;
        }


        sprite.setPosition(xcoord, ycoord);


        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                std::cout << board[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};
