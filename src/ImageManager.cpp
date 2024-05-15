#include "ImageManager.h"

ImageManager& ImageManager::getInstance()
{
	static ImageManager instance;
	return instance;
   
}

// Method to load an image from file
void ImageManager::loadImage(const std::string& name, const std::string& filename)
{
    sf::Texture texture;
    
    texture.loadFromFile(filename);   // Exception handling needed
    textures[name] = std::move(texture);

    
}

// Method to get a reference to a loaded image
const sf::Texture& ImageManager::getImage(const std::string& name) const
{
    return textures.at(name);
}
