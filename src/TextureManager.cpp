#include "../include/TextureManager.h"
#include <iostream>

void TextureManager::loadTexture(const string& name, const string& file)
{
    sf::Texture t;
    if(!t.loadFromFile(file))
    {
        //cout << "Texture "<<file<<" not found!"<<endl;
    }
    t.setSmooth(true);
    this->textures[name] = t;
}

sf::Texture& TextureManager::getRef(const string& name)
{
    return this->textures.at(name);
}
