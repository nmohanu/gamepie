#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // Initialize
    float moveSpeed;
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1920/2, 1080/2), "Game", sf::Style::Default, settings);
    window.setFramerateLimit(60);
    float scaler = 4.f;



    // Fps count
    sf::Clock clock;
    sf::Clock timeFPS;

    // Player
    sf::Clock playerClock;
    bool justMoved= false;
    bool left = false;

    sf::Texture player_texture_right;
    player_texture_right.loadFromFile("../Assets/Player/Textures/player_r.png");

    sf::Texture player_texture_left;
    player_texture_left.loadFromFile("../Assets/Player/Textures/player_l.png");

    sf::Texture player_texture_mright;
    player_texture_mright.loadFromFile("../Assets/Player/Textures/player_mr.png");

    sf::Texture player_texture_mleft;
    player_texture_mleft.loadFromFile("../Assets/Player/Textures/player_ml.png");

    sf::Texture player_texture_front;
    player_texture_front.loadFromFile("../Assets/Player/Textures/player_f.png");

    sf::Sprite playerSprite;
    playerSprite.setTexture(player_texture_right);



    playerSprite.setScale(scaler, scaler);


    // Game loop
    while (window.isOpen())
    {

        // Compute frame rate
        float deltaTime = clock.restart().asSeconds();
        moveSpeed = 10.f * deltaTime * 60;
        sf::Time elapsedFPS = timeFPS.getElapsedTime();
        if(elapsedFPS.asSeconds() > 5){
            std::cout << 1.0 / deltaTime << std::endl;
            timeFPS.restart();
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(position + sf::Vector2f(moveSpeed, 0));
            playerSprite.setTexture(player_texture_mright);
            justMoved = true;
            playerClock.restart();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(position + sf::Vector2f(-moveSpeed, 0));
            playerSprite.setTexture(player_texture_mleft);
            left = true;
            justMoved = true;
            playerClock.restart();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(position + sf::Vector2f(0, -moveSpeed));
            playerClock.restart();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(position + sf::Vector2f(0, moveSpeed));
            playerSprite.setTexture(player_texture_front);
            playerClock.restart();
        }
        sf::Time elapsed = playerClock.getElapsedTime();
        if(elapsed.asMilliseconds() > 100 && justMoved){
            if(left){
                playerSprite.setTexture(player_texture_left);
            } else {
                playerSprite.setTexture(player_texture_right);
            }
            justMoved = false;
            left = false;
        }
        window.clear();
        window.draw(playerSprite);
        window.display();
    }

    return 0;
}
