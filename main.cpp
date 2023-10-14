#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // Initialize
    float moveSpeed = 0.1;
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Game");

        sf::Texture playerTexture;
        sf::Sprite playerSprite;

        if (playerTexture.loadFromFile("../Assets/Player/Textures/player.gif"))
        {
            playerSprite.setTexture(playerTexture);
            std::cout << "texture loaded \n";
        }
        else
        {
            std::cout << "texture failed to load \n";
        }

        int XIndex = 0;
        int YIndex = 0;

        //playerSprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
        //playerSprite.scale(sf::Vector2f(3, 3));


    // Game loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(position + sf::Vector2f(moveSpeed, 0));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(position + sf::Vector2f(-moveSpeed, 0));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(position + sf::Vector2f(0, -moveSpeed));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(position + sf::Vector2f(0, moveSpeed));
        }


        window.clear();
        window.draw(playerSprite);
        window.display();
    }

    return 0;
}
