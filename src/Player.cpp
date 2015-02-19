#include "Player.hpp"

Player::Player(GameState* state, b2World *world)
{
    this->state = state;

    this->entity = new Entity(world, 0, 0, "ship", state->game);
}

Player::~Player()
{
    //dtor
}
