#include "settings.hpp"

Settings::Settings() : window(sf::VideoMode(1000, 850), "Fifteen-puzzle") {
    
    backgroundTexture.loadFromFile("textures/background.png");
    background.setTexture(backgroundTexture);
    background.setScale(7.0f,7.0f);
    background.setPosition(150.f, 145.f);
    
    winImageTexture.loadFromFile("textures/win.png");            
    winImage.setTexture(winImageTexture);
    winImage.setPosition(200.f, 200.f);
    winImage.setScale(0.7f, 0.7f);

    font.loadFromFile("fonts/ds-pixel-cyr.ttf");
    gameName.setFont(font);
    gameName.setString("Fifteen - puzzle");
    gameName.setCharacterSize(98);
    gameName.setFillColor(Color(0,0,0));
    gameName.setPosition(110.f, 20.f);

    gameSoundBuffer.loadFromFile("sound/game-sound.wav");
    gameSound.setBuffer(gameSoundBuffer);
    gameSound.setVolume(15);
    
    gameWinBuffer.loadFromFile("sound/win-sound.wav");
    gameWin.setBuffer(gameWinBuffer);
    gameWin.setVolume(30);
}

Settings::Settings(int gameSoundVolume, int gameWinVolume) : window(sf::VideoMode(1000, 850), "Fifteen-puzzle") { 
    backgroundTexture.loadFromFile("textures/background.png");
    background.setTexture(backgroundTexture);
    background.setScale(7.0f,7.0f);
    background.setPosition(150.f, 145.f);
    
    winImageTexture.loadFromFile("textures/win.png");            
    winImage.setTexture(winImageTexture);
    winImage.setPosition(200.f, 200.f);
    winImage.setScale(0.7f, 0.7f);

    font.loadFromFile("fonts/ds-pixel-cyr.ttf");
    gameName.setFont(font);
    gameName.setString("Fifteen - puzzle");
    gameName.setCharacterSize(98);
    gameName.setFillColor(Color(0,0,0));
    gameName.setPosition(110.f, 20.f);

    gameSoundBuffer.loadFromFile("sound/game-sound.wav");
    gameSound.setBuffer(gameSoundBuffer);
    gameSound.setVolume(gameSoundVolume);
    
    gameWinBuffer.loadFromFile("sound/win-sound.wav");
    gameWin.setBuffer(gameWinBuffer);
    gameWin.setVolume(gameWinVolume);
}

Settings::~Settings() {}

RenderWindow& Settings::getWindow() {
    return window;
}

Sprite& Settings::getBackground() {
    return background;
}

Sprite& Settings::getWinImage() {
    return winImage;
}

Text& Settings::getGameName() {
    return gameName;
}

Sound& Settings::getGameSound() {
    return gameSound;
}

Sound& Settings::getGameWin() {
    return gameWin;
}