#include "../include/Game.hpp"
#include "../include/GameState.hpp"
#include <iostream>

using namespace std;

Game::Game()
{
    this->loadTextures();

    this->window.create(sf::VideoMode(800, 600), "Mercury");
    this->window.setFramerateLimit(60);

    this->background.setTexture(textureManager.getRef("background"));
}
void Game::loadTextures()
{
    this->textureManager.loadTexture("background", "media/parallax1.png");
    this->textureManager.loadTexture("ship", "media/ship.png");
    this->textureManager.loadTexture("box", "box.jpg");
}

void Game::popState()
{
    delete this->states.top();
    this->states.pop();

    return;
}

void Game::pushState(GameState* state)
{
    this->states.push(state);
}

void Game::changeState(GameState* state)
{
    if(!this->states.empty())
    {
        popState();
    }

    pushState(state);
}
GameState* Game::peekState()
{
    if(this->states.empty())
    {
        return nullptr;
    }

    return this->states.top();

}

void Game::gameLoop()
{
    sf::Clock clock;

    while(this->window.isOpen())
    {
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();

        if(peekState() == nullptr)
        {
            cout<<"Game states stack is empty!"<<endl;
            return;
        }

        peekState()->handleInput();
        peekState()->update(dt);

        this->window.clear(sf::Color::Black);

        peekState()->draw(dt);
        this->window.display();

    }

}

Game::~Game()
{
    while(!this->states.empty())
    {
        popState();
    }
}
