#ifndef PARALLAX_H
#define PARALLAX_H

#include<string>
#include<SFML/Graphics.hpp>

using namespace std;

class Parallax
{
    public:
        Parallax(sf::Texture texture);
        virtual ~Parallax();

        void draw(float x, float y, sf::RenderWindow *window);

        float coeffs[3];

        sf::Texture texture;
        sf::Sprite sprite;
        sf::View view;
};

#endif // PARALLAX_H
