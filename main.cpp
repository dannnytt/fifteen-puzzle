#include <iostream>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <conio.h>

#include "src/include/SFML/Graphics.hpp"

const int SIZE = 16;
const int BUTTON_SIZE = 64;
const int HEIGHT = BUTTON_SIZE * (SIZE / 4);
const int WIDTH = BUTTON_SIZE * (SIZE / 4);


using namespace std;
using namespace sf;


void displayBoard(RenderWindow &window, vector <int> &board, Sprite *sprite, Texture &texture) {
  
    
    // int idx = 0;
    for (int i = 0; i < SIZE / 4; i++) {
        for (int j = 0; j < SIZE / 4; j++) {
            int value = board[i * (SIZE / 4) + j];
            int row = value / 4;  // Вычисляем номер строки в текстуре
            int col = value % 4;  // Вычисляем номер столбца в текстуре

            sprite[i * (SIZE / 4) + j].setTexture(texture);
            sprite[i * (SIZE / 4) + j].setTextureRect(IntRect(col * BUTTON_SIZE, row * BUTTON_SIZE, BUTTON_SIZE, BUTTON_SIZE));
            sprite[i * (SIZE / 4) + j].setPosition(i * BUTTON_SIZE, j * BUTTON_SIZE);
            window.draw(sprite[i * (SIZE / 4) + j]);
        }
    }
}


void shuffleBoard (vector <int> &board) {
    int size = board.size(); 
    for (size_t i = size - 1; i >= 1; i--) {
        int j = rand() % (i + 1);
        int tmp = board[j];
        board[j] = board[i];
        board[i] = tmp;
    }
}


void fillBoard(vector <int> &board) {
    int idx = 0;
    vector <int> fillBoard = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int len = fillBoard.size();
    shuffleBoard(fillBoard);
    for (size_t i = 0; i < len; i++) {
        board[i] = fillBoard[idx++];
    }
    board[len - 1] = 0;
}



// bool isWin () {

// }

// bool checkWin() {

// }

// bool checkPuzzle () {

// }



int main()
{
    srand(time(NULL));
    Texture texture;
    texture.loadFromFile("assets/15.png");
    Sprite sprite[20];
    sf::RenderWindow window(sf::VideoMode(256, 256), "Fifteen-puzzle");    
    vector <int> board(SIZE);
    fillBoard(board);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        displayBoard(window, board, sprite, texture);
        window.display();
    }
    return 0;
}