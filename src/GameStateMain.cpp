#include "GameStateMain.hpp"
#include <cmath>
#include <iostream>

using namespace std;

GameStateMain::GameStateMain(Game *game) : parallax(game->textureManager.getRef("background"))
{
    b2Vec2 Gravity(0.f, 0.f);

    this->world = new b2World(Gravity);
    this->game =  game;

    sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
    this->gameView.setSize(pos);
    this->playerView.setSize(pos);

    pos *= 0.5f;

    this->gameView.setCenter(pos);
    this->playerView.setCenter(pos);

    player = new Player(this, this->world);
    this->entities.push_back(*(player->entity));
}

void GameStateMain::draw(const float dt)
{
    this->game->window.clear(sf::Color::Black);

    int x = (int)(SCALE * player->entity->Body->GetPosition().x);
    int y = (int)(SCALE * player->entity->Body->GetPosition().y);

    this->parallax.draw(x, y, &this->game->window);
    this->game->window.setView(gameView);

    this->gameView.reset(sf::FloatRect((SCALE * player->entity->Body->GetPosition().x) - this->game->window.getSize().x / 2,
                                       (SCALE * player->entity->Body->GetPosition().y) - this->game->window.getSize().y / 2,
                                           this->game->window.getSize().x,
                                           this->game->window.getSize().y));

    for(int i = 0; i < entities.size(); i++)
    {
        entities[i].draw();
    }

}

void GameStateMain::update(const float dt)
{
    world->Step(1/60.f, 8, 3);
}

void GameStateMain::handleInput()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
    {
        int MouseX = sf::Mouse::getPosition(this->game->window).x;
        int MouseY = sf::Mouse::getPosition(this->game->window).y;

        sf::Vector2f worldPos = this->game->window.mapPixelToCoords(sf::Vector2i(MouseX, MouseY));
        cout<<worldPos.x<<' '<<worldPos.y<<endl;
        entities.push_back(Entity(this->world, worldPos.x, worldPos.y, "box", this->game));
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {

        float32 angle = player->entity->Body->GetAngle() - b2_pi / 2;

        b2Vec2 v;
        v.y = 20 * sin(angle);  // To be replaced with actual values
        v.x = 20 * cos(angle);

        player->entity->Body->ApplyForceToCenter(v, true);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::V))
    {
        float32 angle = player->entity->Body->GetAngle()- b2_pi / 2;

        b2Vec2 v;
        v.y = 2000 * sin(angle); // To be replaced with actual values
        v.x = 2000 * cos(angle);

        player->entity->Body->ApplyForceToCenter(v, true);

    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        float32 angle = player->entity->Body->GetAngle() - b2_pi / 2;

        b2Vec2 v;
        v.y = 20 * -sin(angle); // To be replaced with actual values
        v.x = 20 * -cos(angle);

        player->entity->Body->ApplyForceToCenter(v, true);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        player->entity->Body->ApplyAngularImpulse(-0.05, true); // To be replaced with actual values
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        player->entity->Body->ApplyAngularImpulse(+0.05, true); // To be replaced with actual values
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        player->entity->Body->SetLinearDamping(10); // To be replaced with actual values
        player->entity->Body->SetAngularDamping(10);
    }
    else
    {
        player->entity->Body->SetLinearDamping(0.1); // To be replaced with actual values
        player->entity->Body->SetAngularDamping(0.1); // or not?!
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        this->game->window.close();
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
                // handle low-fi input
            }
            case sf::Event::KeyPressed:
            {
                // handle low-fi input
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

