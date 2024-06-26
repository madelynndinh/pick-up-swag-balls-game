#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Game.h"
using namespace sf;

int main() {

    //Initialise random seed
    srand(static_cast<unsigned>(time(0)));


    //Initialise game object
    Game game;


    //Game loop
while (game.running())
{
    game.update();
    game.render();
}


    //End of application
    return 0;
}