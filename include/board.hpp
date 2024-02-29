#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

using namespace sf;

class Board {
    
    protected:
        std::vector<int> board = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};

    protected:
        virtual bool checkWin (const std::vector<int>& board) = 0;
        virtual bool checkPuzzle(const std::vector<int>& board) = 0;
        virtual void moveUp (std::vector<Sprite>&, std::vector<int>&, int& idx) = 0;
        virtual void moveDown (std::vector<Sprite>&, std::vector<int>&, int& idx) = 0;
        virtual void moveLeft (std::vector<Sprite>&, std::vector<int>&, int& idx) = 0;
        virtual void moveRight (std::vector<Sprite>&, std::vector<int>&, int& idx) = 0;
};