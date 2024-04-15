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

int points;

sf::Font font;
sf::Text guiText;
sf::Text endGameText;

std::vector <SwagBall> swagBalls;
float spawnTimerMax;
float spawnTimer;
int maxSwagBall;


void initWindow();
void initVariables();
void initFont();
void initText();
    
public:
//Constructors and Destructors2

    Game();
    ~Game();

//Accessors
const bool& getEndGame() const;


//Modifiers


    //Functions
    const bool running() const;
    void pollEvents();
    void spawnSwagBalls();
    const int randBallType() const;

    void updatePlayer();
    void updateCollision();
    void updateGui();
    void update();
    void renderGui(sf::RenderTarget* target);

    void render();
};

#endif