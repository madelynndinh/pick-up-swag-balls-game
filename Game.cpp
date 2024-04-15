#include "Game.h"
#include "Player.h"
#include "SwagBall.h"
#include <iostream>

void Game::initVariables() { 
  this->endGame = false;
  this->spawnTimerMax = 10.f;
  this->spawnTimer = this->spawnTimerMax;
  this->maxSwagBall = 10; 
  this-> points =0;
  }

void Game::initWindow() {
  this->videoMode = sf::VideoMode(800, 600);
  this->window= new sf::RenderWindow(this->videoMode, "Game 2",
                                       sf::Style::Close | sf::Style::Titlebar);
  this->window->setFramerateLimit(60)  ;                                   
}


void Game::initFont()
{
if(this->font.loadFromFile("/Users/minhtamdinh/Documents/OOP/project/demo/pick-up-swag-balls-game/Bungee_Spice/BungeeSpice-Regular.ttf"))
{
  std::cout << "ERROR::GAME::INITFONTS::"<<std::endl;
};

};


void Game::initText()
{
  //init guitext
this->guiText.setFont(this->font);
this->guiText.setFillColor(sf::Color::White);
this->guiText.setCharacterSize(32);


//End game text
this->endGameText.setFont(this->font);
this->endGameText.setFillColor(sf::Color::Red);
this->endGameText.setCharacterSize(60);
this->endGameText.setPosition(sf::Vector2f(20,300));
this->endGameText.setString("YOU ARE DEAD!");
};

// Constructors and Destructors2
Game::Game() {
  this->initVariables();
  this->initWindow();
  this->initFont();
  this->initText();
};

Game::~Game() { delete window; };

//Accessors
const bool& Game::getEndGame() const
{
return false;
};


// Functions
const bool Game::running() const { 
   return this->window->isOpen();
    //&&this->endGame ==false; 
  };
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
      this->swagBalls.push_back(SwagBall(*this->window,this->randBallType())); //randomize the type
      this->spawnTimer = 0.f;

    }

    
  }
  
}
    const int Game::randBallType() const
 { 
  int type = SwagBallTypes::DEFAULT;
  int randValue = rand() %100 +1;
if(randValue > 60 && randValue <=80)
{
  type = SwagBallTypes::DAMAGING;
}

else if (randValue>80 && randValue <=100)
{
  type = SwagBallTypes::HEALING;
}

  return type;
   };

void Game::updatePlayer()
{
  this->player.update(this->window);
  if (this->player.getHp()<= 0 )
  {
    this->endGame=true;
  }
  

};
void Game::updateCollision()

// Check collision between players and the balls
{
  for (size_t i = 0; i < this->swagBalls.size(); i++)
  {
    if (this->player.getShape().getGlobalBounds().intersects(this->swagBalls[i].getShape().getGlobalBounds()))
{
  switch (this->swagBalls[i].getType())
  {
  case SwagBallTypes::DEFAULT:
    this->points++;
    break;
  
  case SwagBallTypes::DAMAGING:
    this->player.takeDamage(10);
    break;
    case SwagBallTypes::HEALING:
    this->player.gainHealth(1);
    break;

  }
  //Add points
    this-> points+=1;

    //Remove the ball
  this->swagBalls.erase(this->swagBalls.begin()+i);


}
  }
  


 };

void Game::updateGui()
{
  std::stringstream ss;

ss << "- Points: " << this-> points<< "\n"
<< " - Health: " <<this->player.getHp()<<"/"<<this->player.getHpMax()<<"\n";

  this->guiText.setString(ss.str());
};


void Game::update() 
{ 
  this->pollEvents(); 

  if (this->endGame == false)
  {
  this->spawnSwagBalls();
  this->updatePlayer();
  this->updateCollision();
  this->updateGui();

  }
  
  

  };

   void Game::renderGui(sf::RenderTarget* target){
  target->draw(this->guiText);

 };

void Game::render() {
  this->window->clear();

  // Render stuff
  this->player.render(this->window);

for (auto i: this->swagBalls)
{
  i.render(*this->window);
}
//RENDER GUI
this->renderGui(this->window);

//Render end text
if (this->endGame == true)
{
  this->window->draw(this->endGameText);
}

  this->window->display();
};

