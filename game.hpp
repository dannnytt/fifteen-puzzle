#pragma once

#include <cstdlib>

#include "SFML/include/SFML/Graphics.hpp"
#include "SFML/include/SFML/Audio.hpp"

const int SIZE = 16;
const int BUTTON_DISTANCE = 160;

using namespace sf;

Sprite* fillSprites ();
void draw(RenderWindow&, Sprite*);
void shuffle(Sprite*, int*);
bool checkWin (int*);
bool checkPuzzle(int*);
int moveUp (Sprite*, int* , int*);
int moveDown (Sprite*, int*, int*);
int moveLeft (Sprite*, int*, int*);
int moveRight (Sprite*, int*, int*);







