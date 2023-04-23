#include "header.h"


//I put it all into its own header to keep it away from the actual game play stuff making organization easier
//if yall dont like it in its own feel free to move it over to the main header

//also im pretty much coding without focusing on making it actaully good so if you see anything thatll make for a better change please do fix


class menu {
public:
    //load main menu
    void MainMenu(RenderWindow& window)//make main menu
    {
        Font font;
        if (!font.loadFromFile("ARIAL.ttf"))
        {
            std::cout << "Failed to load image!" << std::endl;
        }

        //buttons--split by button and text overlay

        //play button
        RectangleShape play_button(sf::Vector2f(300, 100));
        play_button.setPosition(450, 150);
        play_button.setFillColor(sf::Color::Transparent);
        play_button.setOutlineThickness(2);
        play_button.setOutlineColor(sf::Color::White);

        Text playText("Start Game", font, 50);
        playText.setPosition(450, 150);
        playText.setFillColor(sf::Color::White);
        

        //tutorial\rules\info button button
        RectangleShape info_button(sf::Vector2f(300, 100));
        info_button.setPosition(450, 350);
        info_button.setFillColor(sf::Color::Transparent);
        info_button.setOutlineThickness(2);
        info_button.setOutlineColor(sf::Color::White);

        Text infoText("Info", font, 50);
        infoText.setPosition(450, 350);
        infoText.setFillColor(sf::Color::White);


        //exit game button
        RectangleShape exit_button(sf::Vector2f(300, 100));
        exit_button.setPosition(450, 550);
        exit_button.setFillColor(sf::Color::Transparent);
        exit_button.setOutlineThickness(2);
        exit_button.setOutlineColor(sf::Color::White);

        Text exitText("Exit Game", font, 50);
        exitText.setPosition(450, 550);
        exitText.setFillColor(sf::Color::White);


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
                if (event.type == sf::Event::MouseButtonPressed)
                {
                    // Check if the mouse is over the start button
                    if (play_button.getGlobalBounds().contains(Vector2f(event.mouseButton.x, event.mouseButton.y)))
                    {
                        // play game
                    }

                    // Check if the mouse is over the info
                    if (info_button.getGlobalBounds().contains(Vector2f(event.mouseButton.x, event.mouseButton.y)))
                    {
                        //show info
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
            window.clear(sf::Color::Black);
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

    void PlayMenu()//choose between single player w/ ai, two player, multiplayer(if time allows)
    {

    }

};
