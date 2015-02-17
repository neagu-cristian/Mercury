#include "Player.hpp"

Player::Player(Game* game)
{
    this->game = game;
    this->position = sf::Vector2f(-300, -300);
}

Player::~Player()
{
    //dtor
}
