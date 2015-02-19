#ifndef GAME_STATE_MAIN_H
#define GAME_STATE_MAIN_H

#include <Box2D/Box2D.h>
#include <vector>

#include <GameState.hpp>
#include <Entity.hpp>
#include <Player.hpp>
#include <Parallax.hpp>

class GameStateMain : public GameState
{
    public:
        Parallax parallax;
        b2World* world;
        vector<Entity> entities;

        GameStateMain(Game *game);

        virtual void draw(const float dt);
        virtual void update(const float dt);
        virtual void handleInput();

        void CreateBox(b2World* World, int MouseX, int MouseY);

        virtual ~GameStateMain();

    private:
        sf::View gameView;
        sf::View playerView;

        Player *player;


};

#endif // GAME_STATE_MAIN_H
