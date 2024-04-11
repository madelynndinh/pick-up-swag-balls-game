// pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <ctime>
#include <sstream>
#include <vector>


class Game
{
private:
sf::VideoMode videoMode;
sf::RenderWindow* window;
bool endGame;

void initWindow();
void initVariables();
    
public:
//Constructors and Destructors2

    Game();
    ~Game();
//Accessors

//Modifiers


    //Functions
    void update();
    void render();
};

