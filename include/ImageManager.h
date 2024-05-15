#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <unordered_map>
#include <string>

class ImageManager {
public:

    static ImageManager& getInstance();
    ImageManager(const ImageManager&) = delete;
    ImageManager& operator=(const ImageManager&) = delete;
    const sf::Texture& getImage(const std::string& name) const;

private:

    ImageManager();
    std::unordered_map<std::string, sf::Texture> textures;

    void loadImage(const std::string& name, const std::string& filename);

};


