#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Game.hpp"
#include <Entity.hpp>
#include <vector>

class GameState
{
    public:
        Game* game;

        virtual void draw(const float dt) = 0;
        virtual void update(const float dt) = 0;
        virtual void handleInput() = 0;
};

#endif // GAMESTATE_H
