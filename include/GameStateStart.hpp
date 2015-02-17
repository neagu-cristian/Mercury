#ifndef GAMESTATESTART_HPP
#define GAMESTATESTART_HPP

#include <GameState.hpp>
#include <GameStateMain.hpp>
#include <SFML/Graphics.hpp>

class GameStateStart : public GameState
{
    public:
        GameStateStart(Game *game);

        virtual void draw(const float dt);
        virtual void update(const float dt);
        virtual void handleInput();

        virtual ~GameStateStart();

    private:
        sf::View view;
        sf::Text text;
        sf::Font font;
};

#endif // GAMESTATESTART_HPP
