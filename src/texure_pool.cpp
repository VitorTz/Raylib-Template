#include "../include/texture_pool.h"



TexturePool::TexturePool() {
    textureMap.reserve(128 / textureMap.max_load_factor());
}


TexturePool::~TexturePool() {
    for (auto& pair : textureMap) {
        UnloadTexture(pair.second);
    }
}


Texture2D TexturePool::get(const char* fileName) {
    const std::size_t h = hash_func(*fileName);
    if (textureMap.find(h) == textureMap.end()) {
        textureMap.insert({h, LoadTexture(fileName)});
    }
    return textureMap[h];
}


void TexturePool::erase(const char* fileName) {
    const std::size_t h = hash_func(*fileName);
    textureMap.erase(h);
}


void TexturePool::clear() {
    for (auto& pair : textureMap) {
        UnloadTexture(pair.second);
    }
    textureMap.clear();
}