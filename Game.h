#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <ctime>
#include <sstream>
#include <vector>
#include "Player.h"
#include "SwagBall.h"


class Game
{
private:
sf::VideoMode videoMode;
sf::RenderWindow* window;
bool endGame;
sf::Event sfmlEvent;

Player player;

std::vector <SwagBall> swagBalls;
float spawnTimerMax;
float spawnTimer;
int maxSwagBall;

void initWindow();
void initVariables();
    
public:
//Constructors and Destructors2

    Game();
    ~Game();
//Accessors

//Modifiers


    //Functions
    const bool running() const;
    void pollEvents();
    void spawnSwagBalls();
    void updateCollision();
    void update();
    void render();
};

#endif