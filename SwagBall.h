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

    void initShape(const sf::RenderWindow& window);
    
public:
    SwagBall(const sf::RenderWindow& window);
    ~SwagBall();

const sf::CircleShape getShape() const;

//Functions

void update();
void render(sf::RenderTarget& target);

};




#endif