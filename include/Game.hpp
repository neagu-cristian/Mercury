#ifndef GAME_H
#define GAME_H

#include<TextureManager.h>
#include<stack>
#include<SFML/Graphics.hpp>

using namespace std;

class GameState;

class Game
{
    public:
        stack<GameState*> states;
        sf::RenderWindow window;
        sf::Sprite background;

        TextureManager textureManager;


        void popState();
        void pushState(GameState* state);
        void changeState(GameState* state);

        void loadTextures();

        GameState *peekState();

        void gameLoop();

        Game();
        ~Game();
    protected:
    private:
};

#endif // GAME_H
