#pragma once
#include <raylib.h>
#include <bitset>
#include <memory>
#include <unordered_map>


class TexturePool {

    private:
        std::unordered_map<int, Texture2D> textureMap{};
        std::hash<char> hash_func;

    public:
        TexturePool();
        ~TexturePool();
        Texture2D get(const char* fileName);
        void erase(const char* fileName);
        void clear();

};


inline std::unique_ptr<TexturePool> gTexurePool = std::make_unique<TexturePool>();