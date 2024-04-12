#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <ctime>
#include <sstream>
#include <vector>


class Player
{
private:
    sf::RectangleShape shape;
    float movementSpeed;
    int hpMax;
    int hp;
    void initVariables();
    void initShape();

public:
    Player(float x=0.1f, float y=0.1f);
    virtual ~Player();

    void updateInput();
    void updateWindowBoundsCollision(const sf::RenderTarget* target);
    void update(const sf::RenderTarget* target);
    void render(sf::RenderTarget* target);
};


#endif


