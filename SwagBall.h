#ifndef SWAGBALL_H
#define SWAGBALL_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <ctime>
#include <sstream>
#include <vector>
#include "Player.h"

class SwagBall
{
private:
    sf::CircleShape shape;

    void initShape();
    
public:
    SwagBall(/* args */);
    ~SwagBall();

//Functions
void update();
void render(sf::RenderTarget& target);

};




#endif