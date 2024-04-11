#include "Game.h"

#include <iostream>

void Game:: initVariables(){
this->endGame=false;
}

void Game:: initWindow(){
    this->videoMode = sf::VideoMode(800,600);
    this->endGame = new sf::RenderWindow(this->videoMode,"Game 2",sf::Style::Close | sf::Style::Titlebar);
    }


//Constructors and Destructors2
 Game::Game(){
this->initVariables();
this->initWindow();
 };



    Game::~Game(){
delete window;
    };


    //Functions
        void Game::update()
        {

        };

        
    void Game::render(){

    };