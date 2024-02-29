#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

using namespace sf;

class Settings {
    private:
        RenderWindow window;
        Texture backgroundTexture, winImageTexture;
        Sprite background, winImage;
        Font font;
        Text gameName;
        SoundBuffer gameSoundBuffer, gameWinBuffer;
        Sound gameSound, gameWin;
    
    public:
        Settings();
        Settings(int gameSoundVolume, int gameWinVolume);
        ~Settings(); 
        RenderWindow& getWindow();
        Sprite& getBackground();
        Sprite& getWinImage();
        Text& getGameName();
        Sound& getGameSound();
        Sound& getGameWin();
};