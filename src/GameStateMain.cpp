#include "GameStateMain.hpp"
#include <cmath>

GameStateMain::GameStateMain(Game *game)
{
    b2Vec2 Gravity(0.f, 0.f);
    this->world = new b2World(Gravity);

    this->game =  game;
    this->player.setTexture(this->game->textureManager.getRef("ship"));
    sf::Vector2f origin = sf::Vector2f(this->game->textureManager.getRef("ship").getSize());
    this->player.setOrigin(origin * 0.5f);

    sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
    this->gameView.setSize(pos);
    this->playerView.setSize(pos);
    pos *= 0.5f;
    this->player.move(pos);
    this->gameView.setCenter(pos);
    this->playerView.setCenter(pos);

    //this->world->
}

void GameStateMain::draw(const float dt)
{

    this->game->window.setView(gameView);

    this->game->window.clear(sf::Color::Black);
    this->game->window.draw(this->game->background);

    for(int i = 0; i < entities.size(); i++)
    {
        entities[i].draw();
    }

    this->game->window.setView(playerView);
    //this->game->window.draw(this->player);
}

void GameStateMain::update(const float dt)
{
    world->Step(1/60.f, 8, 3);
}

void GameStateMain::handleInput()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        int MouseX = sf::Mouse::getPosition(this->game->window).x;
        int MouseY = sf::Mouse::getPosition(this->game->window).y;

        entities.push_back(Entity(this->world, MouseX, MouseY, "ship", this->game));
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
    {
        int MouseX = sf::Mouse::getPosition(this->game->window).x;
        int MouseY = sf::Mouse::getPosition(this->game->window).y;

        entities.push_back(Entity(this->world, MouseX, MouseY, "box", this->game));
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        float32 angle = entities[0].Body->GetAngle() - b2_pi / 2;

        b2Vec2 v;
        v.y = 20 * sin(angle);
        v.x = 20 * cos(angle);

        entities[0].Body->ApplyForceToCenter(v, true);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::V))
    {
        float32 angle = entities[0].Body->GetAngle()- b2_pi / 2;

        b2Vec2 v;
        v.y = 2000 * sin(angle);
        v.x = 2000 * cos(angle);

        entities[0].Body->ApplyForceToCenter(v, true);

    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
    //b2Body b;
        float32 angle = entities[0].Body->GetAngle() - b2_pi / 2;

        b2Vec2 v;
        v.y = 20 * -sin(angle);
        v.x = 20 * -cos(angle);

        entities[0].Body->ApplyForceToCenter(v, true);

    //    this->gameView.move(0, 10);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        entities[0].Body->ApplyAngularImpulse(-0.05, true);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        entities[0].Body->ApplyAngularImpulse(+0.05, true);

        //b2Body b;
        entities[0].Body->SetLinearDamping(0.1);
        entities[0].Body->SetAngularDamping(0.1);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        entities[0].Body->SetLinearDamping(10);
        entities[0].Body->SetAngularDamping(10);
    }
    else
    {
        if(entities.size())
        {
            entities[0].Body->SetLinearDamping(0.1);
            entities[0].Body->SetAngularDamping(0.1);
        }
    }

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
                gameView.setSize(event.size.width, event.size.height);
                playerView.setSize(event.size.width, event.size.height);

                break;
            }
            case sf::Event::MouseButtonPressed:
            {

            }
            case sf::Event::KeyPressed:
            {

            }
            default:
            {
                break;
            }
        }
    }
}


GameStateMain::~GameStateMain()
{
    //dtor
}

