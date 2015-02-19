#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <GameState.hpp>

class Player
{
    public:
        Player(GameState *state, b2World *world);
        Entity *entity;
        GameState *state;

        virtual ~Player();

    private:

};

#endif // PLAYER_H
