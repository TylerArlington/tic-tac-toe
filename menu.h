

#include "header.h"
#include "board.h"

//I put it all into its own header to keep it away from the actual game play stuff making organization easier
//if yall dont like it in its own feel free to move it over to the main header

//also im pretty much coding without focusing on making it actaully good so if you see anything thatll make for a better change please do fix


class menu 
{
public:
    void PlayMenu(RenderWindow& window)//choose between single player w/ ai or multiplayer(if time allows)
    {
        TicTacBoard game;


        // Buttons for single player and multiplayer modes
        Font font; // font for text

        if (!font.loadFromFile("ARIAL.ttf"))
        {
            cout << "Failed to load font!" << endl;
        }

        // Single Player Button
        RectangleShape single_button(Vector2f(300, 100));
        single_button.setPosition(450, 150);
        single_button.setFillColor(Color::Transparent);
        single_button.setOutlineThickness(2);
        single_button.setOutlineColor(Color::White);

        Text singlePlayerText("Single Player", font, 50);
        singlePlayerText.setPosition(450, 150);
        singlePlayerText.setFillColor(Color::White);

        // Multiplayer Button
        RectangleShape multi_button(Vector2f(300, 100));
        multi_button.setPosition(450, 350);
        multi_button.setFillColor(Color::Transparent);
        multi_button.setOutlineThickness(2);
        multi_button.setOutlineColor(Color::White);

        Text multiPlayerText("Multiplayer", font, 50);
        multiPlayerText.setPosition(450, 350);
        multiPlayerText.setFillColor(Color::White);

        while (window.isOpen()) // Checks for user input until window is closed
        {
            // Process events
            Event event;
            while (window.pollEvent(event))
            {
                // Check for user input
                if (event.type == Event::MouseButtonPressed)
                {
                    // if mouse is over the single player button
                    if (single_button.getGlobalBounds().contains(Vector2f(event.mouseButton.x, event.mouseButton.y)))
                    {
                        cout << "Singleplayer" << "\n";
                        game.runGame(window);
                    }

                    // Check if mouse is over the multiplayer button
                    if (multi_button.getGlobalBounds().contains(Vector2f(event.mouseButton.x, event.mouseButton.y)))
                    {
                        cout << "Multiplayer--not yet implemented" << "\n";
                        // START MULTIPLAYER GAME (NOT IMPLEMENTED)
                    }
                }
                else if (event.type == Event::Closed)
                {
                    // Close the window
                    window.close();
                }
            }

            window.clear(Color::Black);
            window.draw(single_button);
            window.draw(multi_button);
            window.draw(singlePlayerText);
            window.draw(multiPlayerText);
            window.display();
        }

    }

    //load main menu
    void MainMenu(RenderWindow& window)//make main menu
    {
        Font font;
        if (!font.loadFromFile("ARIAL.ttf"))
        {
            cout << "Failed to load font!" << endl;
        }

        //buttons--split by button and text overlay

        //play button
        RectangleShape play_button(Vector2f(300, 100));
        play_button.setPosition(450, 150);
        play_button.setFillColor(Color::Transparent);
        play_button.setOutlineThickness(2);
        play_button.setOutlineColor(Color::White);

        Text playText("Start Game", font, 50);
        playText.setPosition(450, 150);
        playText.setFillColor(Color::White);


        //tutorial\rules\info button button
        RectangleShape info_button(Vector2f(300, 100));
        info_button.setPosition(450, 350);
        info_button.setFillColor(Color::Transparent);
        info_button.setOutlineThickness(2);
        info_button.setOutlineColor(Color::White);

        Text infoText("Info", font, 50);
        infoText.setPosition(450, 350);
        infoText.setFillColor(Color::White);


        //exit game button
        RectangleShape exit_button(Vector2f(300, 100));
        exit_button.setPosition(450, 550);
        exit_button.setFillColor(Color::Transparent);
        exit_button.setOutlineThickness(2);
        exit_button.setOutlineColor(Color::White);

        Text exitText("Exit Game", font, 50);
        exitText.setPosition(450, 550);
        exitText.setFillColor(Color::White);


        //makes menu background --  replace test.png with final background whenever ready
        Texture wallpaper;
        if (!wallpaper.loadFromFile("menu1.1.png"))
        {
            std::cout << "Failed to load image!" << std::endl;
        }

        Sprite background(wallpaper);
        background.setPosition(0, 0);

        while (window.isOpen())
        {
            // Process events
            Event event;
            while (window.pollEvent(event))
            {
                // Check for user input
                if (event.type == Event::MouseButtonPressed)
                {
                    // Check if the mouse is over the start button
                    if (play_button.getGlobalBounds().contains(Vector2f(event.mouseButton.x, event.mouseButton.y)))
                    {
                        cout << "play" << "\n";
                        PlayMenu(window);
                    }

                    // Check if the mouse is over the info
                    if (info_button.getGlobalBounds().contains(Vector2f(event.mouseButton.x, event.mouseButton.y)))
                    {
                        infoMenu(window);
                    }

                    // Check if the mouse is over the exit
                    if (exit_button.getGlobalBounds().contains(Vector2f(event.mouseButton.x, event.mouseButton.y)))
                    {
                        window.close();//close game
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
            window.draw(play_button);
            window.draw(info_button);
            window.draw(exit_button);
            window.draw(playText);
            window.draw(infoText);
            window.draw(exitText);
            window.display();
        }
    }

    void infoMenu(RenderWindow& window)
    {
        //TicTacBoard game;


        Font font; // font for text

        if (!font.loadFromFile("ARIAL.ttf"))
        {
            cout << "Failed to load font!" << endl;
        }
        Text instructionText("The rules of tic tac toe are quite simple\nThe aim of the Game is to get 3 in a row before your opponent does\n One player will be represented be X and the other O\nTo play simply click where you want to place your X\nEnjoy!", font, 30);
        instructionText.setPosition(225, 150);
        instructionText.setFillColor(Color::White);


        // return Button
        RectangleShape return_button(Vector2f(300, 100));
        return_button.setPosition(450, 550);
        return_button.setFillColor(Color::Transparent);
        return_button.setOutlineThickness(2);
        return_button.setOutlineColor(Color::White);

        Text returnText("return", font, 50);
        returnText.setPosition(450, 550);
        returnText.setFillColor(Color::White);

        while (window.isOpen()) // Checks for user input until window is closed
        {
            // Process events
            Event event;
            while (window.pollEvent(event))
            {
                // Check for user input
                if (event.type == Event::MouseButtonPressed)
                {
                    // if mouse is over the single player button
                    if (return_button.getGlobalBounds().contains(Vector2f(event.mouseButton.x, event.mouseButton.y)))
                    {
                        cout << "return" << "\n";
                        MainMenu(window);
                    }
                }
                else if (event.type == Event::Closed)
                {
                    // Close the window
                    window.close();
                }
            }

            window.clear(Color::Black);
            window.draw(instructionText);
            window.draw(return_button);
            window.draw(returnText);
            window.display();
        }
    }

 };


 

