#include "Parallax.hpp"

Parallax::Parallax(sf::Texture texture)
{
    this->texture = texture;
    sprite.setTexture(this->texture);
    sprite.setPosition(0, 0);

    coeffs[0] = 10;
    coeffs[1] = 15;
    coeffs[2] = 20;
}

void Parallax::draw(float x, float y, sf::RenderWindow *window)
{
    for(int k = 0 ; k < 3; k++)
    {
        int yy = -(int)(y / coeffs[k]) % (1024);
        int xx = -(int)(x / coeffs[k]) % (1024);
        this->view.reset(sf::FloatRect(0.0f, 0.0f,
                         window->getSize().x,
                         window->getSize().y));
        //this->sprite.setPosition(x, y);

        window->setView(this->view);
        for(int i = -1; i < 2; i++)
        {
            for(int j = -1; j < 2; j++)
            {
                this->sprite.setPosition(1024 * i, 1024 * j);
                this->sprite.move(xx, yy);

                window->draw(this->sprite);
            }
        }
    }
    this->sprite.setPosition(0, 0);


}

Parallax::~Parallax()
{
    //dtor
}
