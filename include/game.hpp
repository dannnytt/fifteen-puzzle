#pragma once
#include <iostream>
#include "board.hpp"
#include "settings.hpp"

using namespace sf;

class Game : public Board {
    
    private:
        Settings settings;
        Texture *textures;
        std::vector<Sprite> sprites;
        
    private:
        void loadTextures();
        void setSprites ();
        void shuffle();
        void getSolvedPuzzle();

        bool checkWin(const std::vector<int>& board) override;
        bool checkPuzzle(const std::vector<int>& board) override;
        void moveUp (std::vector<Sprite> &sprites, std::vector<int> &board, int& idx) override;
        void moveDown (std::vector<Sprite> &sprites, std::vector<int> &board, int& idx) override;
        void moveLeft (std::vector<Sprite> &sprites, std::vector<int> &board, int& idx) override;
        void moveRight (std::vector<Sprite> &sprites, std::vector<int> &board, int& idx) override;
        void draw(RenderWindow &window, std::vector<Sprite>& sprites);

    public:
        Game ();
        ~Game();
        void play();
};