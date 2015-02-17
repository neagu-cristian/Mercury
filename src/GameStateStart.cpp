#include "GameStateStart.hpp"

void GameStateStart::draw(const float dt)
{

    this->game->window.setView(this->view);

    this->game->window.clear(sf::Color::Black);
    //this->game->window.draw(this->game->background);
    this->game->window.draw(this->text);
}

void GameStateStart::update(const float dt)
{

}

void GameStateStart::handleInput()
{
    sf::Event event;

while(this->game->window.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed:
            {
                this->game->window.close();
                break;
            }
            case sf::Event::Resized:
            {
                view.setSize(event.size.width, event.size.height);

                break;
            }
            case sf::Event::KeyPressed:
            {
                if(event.key.code == sf::Keyboard::Escape)
                {
                    this->game->window.close();
                }
                if(event.key.code == sf::Keyboard::Space)
                {
                    this->game->pushState(new GameStateMain(this->game));
                }
            }
            default:
            {
                break;
            }
        }
    }
}

GameStateStart::GameStateStart(Game *game)
{
    this->font.loadFromFile("terminus.ttf");
    this->text.setCharacterSize(12);

    this->text.setString("Press space to continue!");
    this->text.setColor(sf::Color::White);
    this->text.setFont(this->font);

    this->game =  game;
    sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
    this->view.setSize(pos);
    pos *= 0.5f;
    this->view.setCenter(pos);
}

GameStateStart::~GameStateStart()
{
    //dtor
}
