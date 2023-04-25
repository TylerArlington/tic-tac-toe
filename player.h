
#include "header.h"


class player {
protected:
    // Add any protected member variables and functions here

public:
    virtual void makeMove() = 0;  // Define an abstract function to make a move
};

class humanPlayer : public player {
protected:
    // Add any protected member variables and functions here

public:
    void makeMove() override {
        // Add code to prompt the human player to make a move and handle the input
    }
};

class computerPlayer : public player {
protected:
    // Add any protected member variables and functions here

public:
    void makeMove() override {
        // Add code to make a move for the computer player
    }
};
