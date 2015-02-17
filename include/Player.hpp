#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <Game.hpp>

class Player
{
    public:
        Player(Game *game);
        void moveBy(float x, float y);
        sf::Vector2f getPosition();

        virtual ~Player();

    private:
        Game* game;
        sf::Vector2f position;
        sf::Sprite sprite;
};

#endif // PLAYER_H
