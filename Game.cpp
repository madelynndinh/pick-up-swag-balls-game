#include "Game.h"
#include "Player.h"
#include "SwagBall.h"
#include <iostream>

void Game::initVariables() { 
  this->endGame = false;
  this->spawnTimerMax = 10.f;
  this->spawnTimer = this->spawnTimerMax;
  this->maxSwagBall = 10; 
  }

void Game::initWindow() {
  this->videoMode = sf::VideoMode(800, 600);
  this->window= new sf::RenderWindow(this->videoMode, "Game 2",
                                       sf::Style::Close | sf::Style::Titlebar);
  this->window->setFramerateLimit(60)  ;                                   
}

// Constructors and Destructors2
Game::Game() {
  this->initVariables();
  this->initWindow();

};

Game::~Game() { delete window; };



// Functions
const bool Game::running() const { return this->window->isOpen(); };
void Game::pollEvents() {
  // Event polling
  while (this->window->pollEvent(this->sfmlEvent)) {
    switch (this->sfmlEvent.type) {
      case sf::Event::Closed:
        this->window->close();
        break;

      case sf::Event::KeyPressed:
        if (this->sfmlEvent.key.code == sf::Keyboard::Escape) {
          this->window->close();
          break;
        };
    }
  }
}

void Game::spawnSwagBalls(){
  //Timer
  if(this->spawnTimer < this->spawnTimerMax)
  {
    this->spawnTimer += 1.f;
  }
  else
  {
    if (this->swagBalls.size()<this->maxSwagBall)
    {
      this->swagBalls.push_back(SwagBall(*this->window));
      this->spawnTimer = 0.f;

    }

    
  }
  
};

 void Game::updateCollision() //Check collision between players and the balls
 {

 };

void Game::update() 
{ 
  this->pollEvents(); 
  this->spawnSwagBalls();
  this->player.update(this->window);
  };

void Game::render() {
  this->window->clear();

  // Render stuff
  this->player.render(this->window);

for (auto i: this->swagBalls)
{
  i.render(*this->window);
}

  this->window->display();
};