#include "header.h"


//I put it all into its own header to keep it away from the actual game play stuff making organization easier
//if yall dont like it in its own feel free to move it over to the main header


class menu {
public:
    //load main menu
    void MainMenu(RenderWindow& window)//make main menu
    {
        //play button
        RectangleShape play_button(sf::Vector2f(300, 100));
        play_button.setPosition(450, 350);


        //tutorial\rules\info button button
        RectangleShape info_button(sf::Vector2f(300, 100));
        info_button.setPosition(450, 250);

        //exit game button
        RectangleShape exit_button(sf::Vector2f(300, 100));
        info_button.setPosition(450, 450);

        //makes menu background --  replace test.png with final background whenever ready
        Texture wallpaper;
        if (!wallpaper.loadFromFile("test.png"))
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
                if (event.type == sf::Event::MouseButtonPressed)
                {
                    // Check if the mouse is over the start button
                    if (play_button.getGlobalBounds().contains(Vector2f(event.mouseButton.x, event.mouseButton.y)))
                    {
                        //show info
                    }

                    // Check if the mouse is over the info
                    if (play_button.getGlobalBounds().contains(Vector2f(event.mouseButton.x, event.mouseButton.y)))
                    {
                        //show info
                    }

                    // Check if the mouse is over the exit
                    if (play_button.getGlobalBounds().contains(Vector2f(event.mouseButton.x, event.mouseButton.y)))
                    {
                        //close game
                    }
                }
                else if (event.type == Event::Closed)
                {
                    // Close the window
                    window.close();
                }
            }
            window.clear(sf::Color::Black);
            window.draw(background);
            window.draw(play_button);
            window.draw(info_button);
            window.draw(exit_button);
            window.display();
        }
    }

    void PlayMenu()//choose between single player w/ ai, two player, multiplayer(if time allows)
    {

    }

};