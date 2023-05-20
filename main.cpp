#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <conio.h>
  
#define SIZE 16

using namespace std;

enum KEYS{
    UP = 72,
    DOWN = 80,
    LEFT = 75,
    RIGHT = 77,
    ESC = 27
};

void shuffle(int* arr, int size) {
    
    for (int i = size - 1; i >= 1; i--) {
        int j = rand() % (i + 1);
        int tmp = arr[j];
        arr[j] = arr[i];
        arr[i] = tmp;
    }
}

void fillBoard(int board[SIZE]) {
    
    int idx = 0;
    int len = SIZE - 1;
    int fillBoard[len] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    shuffle(fillBoard, len);
    for (int i = 0; i < SIZE; i++) {
        board[i] = fillBoard[idx++];
    }
    board[len] = 0;
}

void displayBoard(int board[SIZE]) {

    system("CLS");
    cout << setw(3) << "+";
    for (int i = 0; i < SIZE/4; i++) {
        cout << "----+";
    }
    cout << endl;

    int idx = 0;
    for (int i = 0; i < SIZE/4; i++) {
        cout << setw(3) << "|";
        for (int j = 0; j < SIZE/4; j++) {
            if (board[idx] == 0) {
                cout << setw(2) << " " << "  |";
                idx++;
            }
            else {
                cout << setw(2) << board[idx++] << "  |";
            }
        }
        cout << endl;

        cout << setw(3) << "+";
        for (int i = 0; i < SIZE/4; i++) {
            cout << "----+";
        }
        cout << endl;
    }
}

bool checkWin (int board[SIZE]) {

    for (int i = 1; i < SIZE - 1; i++) {
        if (board[i - 1] != i) {
            return false;
        }
    }
    return true;
}

bool checkPuzzle(int board[SIZE]) {

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

int moveUp (int board[SIZE], int* idx) {

    if ((*idx / 4) >= 3) {
        return 1;
    }
    int temp = board[*idx];
    board[*idx] = board[(*idx + 4)];
    board[(*idx + 4)] = temp;
    *idx = (*idx + 4);
    return 0;
}

int moveDown (int board[SIZE], int* idx) {

    if ((*idx / 4) < 1) {
        return 1;
    }
    int temp = board[*idx];
    board[*idx] = board[(*idx - 4)];
    board[(*idx - 4)] = temp;
    *idx = (*idx - 4);
    return 0;
}

int moveLeft (int board[SIZE], int* idx) {
  
    if (*idx % 4 == 3) {
        return 1;
    }
    int temp = board[*idx];
    board[*idx] = board[(*idx + 1)];
    board[(*idx + 1)] = temp;
    *idx = (*idx + 1); 
    return 0;
}

int moveRight (int board[SIZE], int* idx) {

    if (*idx % 4 == 0) {
        return 1;
    }
    int temp = board[*idx];
    board[*idx] = board[(*idx - 1)];
    board[(*idx - 1)] = temp;
    *idx = (*idx - 1);
    if (*idx % 4 == 0) {
        idx -= 1;
        return 1;
    }
    return 0;
}

int main()
{
    srand(time(NULL));
    int board[SIZE];
    fillBoard(board);
    displayBoard(board);
    int idx = SIZE - 1;

    bool flag = false;
    while (flag) {
        if (!checkPuzzle(board)) {
            fillBoard(board);
            flag = true;
        }
    }

    char key;
    while ((key = getch()) != ESC) {

        if (checkWin(board)) {
            return 0;
        }

        switch(key) {
            case UP:
                moveUp(board, &idx);
                break;

            case DOWN:
                moveDown(board, &idx);
                break;
            
            case LEFT:
                moveLeft(board, &idx);
                break;
            
            case RIGHT:
                moveRight(board, &idx);
                break;
        }
        displayBoard(board);
    }
    return 0;
}