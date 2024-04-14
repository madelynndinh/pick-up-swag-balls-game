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

    //Accessors
    const sf::RectangleShape& getShape() const;
    const int& getHp() const;
    const int& getHpMax() const;


    //Functions
    void takeDamage(const int damage);
    void gainHealth(const int health);
    void updateInput();
    void updateWindowBoundsCollision(const sf::RenderTarget* target);
    void update(const sf::RenderTarget* target);
    void render(sf::RenderTarget* target);
};


#endif


