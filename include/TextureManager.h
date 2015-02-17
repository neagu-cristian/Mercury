#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

using namespace std;

class TextureManager
{
    public:
        TextureManager()
        {

        }

        void loadTexture(const string& name, const string& file);

        sf::Texture& getRef(const string& texture);

    private:
        map<string, sf::Texture> textures;
};

#endif // TEXTURE_MANAGER_H
