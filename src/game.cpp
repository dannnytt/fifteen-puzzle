#include <cstdlib>

#include "../include/SFML/Graphics.hpp"

using namespace sf;

const int SIZE = 16;
const int BUTTON_DISTANCE = 160;

Sprite* fillSprites () {
    
    Texture *textures = new Texture[16];
    textures[0].loadFromFile("textures/1.png");
    textures[1].loadFromFile("textures/2.png");
    textures[2].loadFromFile("textures/3.png");
    textures[3].loadFromFile("textures/4.png");
    textures[4].loadFromFile("textures/5.png");
    textures[5].loadFromFile("textures/6.png");
    textures[6].loadFromFile("textures/7.png");
    textures[7].loadFromFile("textures/8.png");
    textures[8].loadFromFile("textures/9.png");
    textures[9].loadFromFile("textures/10.png");
    textures[10].loadFromFile("textures/11.png");
    textures[11].loadFromFile("textures/12.png");
    textures[12].loadFromFile("textures/13.png");
    textures[13].loadFromFile("textures/14.png");
    textures[14].loadFromFile("textures/15.png");
    textures[15].loadFromFile("textures/0.png");

    Sprite *sprites = new Sprite[16];
    sprites[0].setTexture(textures[0]);
    sprites[1].setTexture(textures[1]);
    sprites[2].setTexture(textures[2]);
    sprites[3].setTexture(textures[3]);
    sprites[4].setTexture(textures[4]);
    sprites[5].setTexture(textures[5]);
    sprites[6].setTexture(textures[6]);
    sprites[7].setTexture(textures[7]);
    sprites[8].setTexture(textures[8]);
    sprites[9].setTexture(textures[9]);
    sprites[10].setTexture(textures[10]);
    sprites[11].setTexture(textures[11]);
    sprites[12].setTexture(textures[12]);
    sprites[13].setTexture(textures[13]);
    sprites[14].setTexture(textures[14]);
    sprites[15].setTexture(textures[15]);

    for (int i = 0; i < SIZE; i++) {
        sprites[i].setScale(sf::Vector2f(5.f, 5.f));
    }

    return sprites;
}

void draw(RenderWindow &window, Sprite *sprites) {

    for (int i = 0; i < SIZE; i++)
    {
        int row = i / 4; 
        int col = i % 4; 
        sprites[i].setPosition(col * BUTTON_DISTANCE, row * BUTTON_DISTANCE);
        window.draw(sprites[i]);
    }
}


void shuffle(Sprite *sprites, int *board) {
    
    for (int i = SIZE - 2; i >= 0; i--) {
        int j = rand() % (i + 1);
        Sprite tmp = sprites[j];
        int tmp1 = board[j];

        sprites[j] = sprites[i];
        board[j] = board[i];

        sprites[i] = tmp;
        board[i] = tmp1;
    }
}

bool checkWin (int *board) {

    for (int i = 1; i < SIZE - 1; i++) {
        if (board[i - 1] != i) {
            return false;
        }
    }
    return true;
}

bool checkPuzzle(int *board) {

    int check = 0;
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            if (board[i] != 0 && board[j] != 0 && board[i] > board[j]) {
                check++;
            }
        }
    }

    if (check % 2 == 0) {
        return true;
    } else {
        return false;
    }
}

int moveUp (Sprite *sprites, int *board , int* idx) {

    if ((*idx / 4) >= 3) {
        return 1;
    }
    
    int temp = board[*idx];
    Sprite temp1 = sprites[*idx];

    board[*idx] = board[(*idx + 4)];
    sprites[*idx] = sprites[(*idx + 4)];

    board[(*idx + 4)] = temp;
    sprites[(*idx + 4)] = temp1;

    *idx = (*idx + 4);
    return 0;
}

int moveDown (Sprite *sprites, int *board, int* idx) {

    if ((*idx / 4) < 1) {
        return 1;
    }

    int temp = board[*idx];
    Sprite temp1 = sprites[*idx];

    board[*idx] = board[(*idx - 4)];
    sprites[*idx] = sprites[(*idx - 4)];

    board[(*idx - 4)] = temp;
    sprites[(*idx - 4)] = temp1;

    *idx = (*idx - 4);
    return 0;
}

int moveLeft (Sprite *sprites, int *board, int* idx) {
  
    if (*idx % 4 == 3) {
        return 1;
    }

    int temp = board[*idx];
    Sprite temp1 = sprites[*idx];

    board[*idx] = board[(*idx + 1)];
    sprites[*idx] = sprites[(*idx + 1)];

    board[(*idx + 1)] = temp;
    sprites[(*idx + 1)] = temp1;

    *idx = (*idx + 1); 
    return 0;
}

int moveRight (Sprite *sprites, int *board, int* idx) {

    if (*idx % 4 == 0) {
        return 1;
    }

    int temp = board[*idx];
    Sprite temp1 = sprites[*idx];

    board[*idx] = board[(*idx - 1)];
    sprites[*idx] = sprites[(*idx - 1)];

    board[(*idx - 1)] = temp;
    sprites[(*idx - 1)] = temp1;

    *idx = (*idx - 1);
    return 0;
}
