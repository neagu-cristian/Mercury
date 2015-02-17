#ifndef ENTITY_H
#define ENTITY_H

#include<SFML/Graphics.hpp>
#include<Box2D/Box2D.h>
#include<Game.hpp>
#include<string>

using namespace std;

static const float SCALE = 30.f;

class Entity
{
    public:
        sf::Sprite sprite;
        b2Body* Body;
        Game *game;

        Entity(b2World *world, int x, int y, string texture, Game *game);
        void draw();

        virtual ~Entity();
    private:

};

#endif // ENTITY_H
