#include "game.hpp"

void Game::loadTextures() {
    textures = new Texture[board.size()];
    for (int i = 0; i < board.size(); i++) {
        textures[i].loadFromFile("textures/"+ std::to_string(i + 1) + ".png");
    } 
}

void Game::setSprites () {
    for (int i = 0; i < board.size(); i++) {
        sprites[i].setTexture(textures[i]);
        sprites[i].setScale(sf::Vector2f(5.f, 5.f));sprites[i].setScale(sf::Vector2f(5.f, 5.f));
    }
}

void Game::shuffle() {
    for (int i = board.size() - 2; i >= 0; i--) {
        int j = rand() % (i + 1);
        std::swap(board[i], board[j]);
        std::swap(sprites[i], sprites[j]);
    }
}

void Game::getSolvedPuzzle() {
    bool flag = true;
    while (flag) {
        shuffle();
        if (checkPuzzle(board)) {
            shuffle();
            flag = false;
        }
    }
}
        
bool Game::checkWin(const std::vector<int>& board) {
    for (int i = 1; i < board.size(); i++) {
        if (board[i - 1] != i) {
            return false;
        }
    }
    return true;
}

bool Game::checkPuzzle(const std::vector<int>& board) {
    int inversions = 0;
    int emptyRow = 0;
    for (int i = 0; i < board.size(); ++i) {
        if (board[i] == 0) {
            emptyRow = i / 4;
            continue;
        }

        for (int j = i + 1; j < board.size(); ++j) {
            if (board[j] != 0 && board[i] > board[j]) {
                ++inversions;
            }
        }
    }

    return (board.size() % 2 == 0) ? ((emptyRow % 2 == 0) == (inversions % 2 == 0))
                                : (inversions % 2 == 0);
}

void Game::moveUp (std::vector<Sprite> &sprites, std::vector<int> &board, int& idx) {

    if ((idx / 4) >= 3) {
        return;
    }
    
    std::swap(board[idx], board[idx + 4]);
    std::swap(sprites[idx], sprites[idx + 4]);

    idx = idx + 4;
}

void Game::moveDown (std::vector<Sprite> &sprites, std::vector<int> &board, int& idx) {

    if ((idx / 4) < 1) {
        return; 
    }

    std::swap(board[idx], board[idx - 4]);
    std::swap(sprites[idx], sprites[idx - 4]);

    idx = idx - 4;
}

void Game::moveLeft (std::vector<Sprite> &sprites, std::vector<int> &board, int& idx) {

    if (idx % 4 == 3) {
        return;
    }

    std::swap(board[idx], board[idx + 1]);
    std::swap(sprites[idx], sprites[idx + 1]);
    
    idx = idx + 1; 
}

void Game::moveRight (std::vector<Sprite> &sprites, std::vector<int> &board, int& idx) {

    if (idx % 4 == 0) {
        return;
    }

    std::swap(board[idx], board[idx - 1]);
    std::swap(sprites[idx], sprites[idx - 1]);

    idx = idx - 1;
}

void Game::draw(RenderWindow &window, std::vector<Sprite>& sprites) {
    for (int i = 0; i < sprites.size(); i++){
        int row = i / 4; 
        int col = i % 4; 
        sprites[i].setPosition(col * 160, row * 160);
        window.draw(sprites[i]);
    }
}

Game::Game () {
    sprites.resize(board.size());
    loadTextures();
    setSprites();
    getSolvedPuzzle();
}

Game::~Game() {
    delete [] textures;
}

void Game::play() {
    int idx = board.size() - 1;
    while (settings.getWindow().isOpen()) {
        Event event;
        while (settings.getWindow().pollEvent(event)) {
            if (event.type == Event::Closed) {
                settings.getWindow().close();
            }

            if(event.type == Event::KeyPressed) {

                if (event.key.code == Keyboard::Escape) {
                    settings.getWindow().close();
                }

                if (event.key.code == Keyboard::W) {
                    moveUp(sprites, board, idx);
                    settings.getGameSound().play();
                }

                if (event.key.code == Keyboard::S) {
                    moveDown(sprites, board, idx);
                    settings.getGameSound().play();
                }

                if (event.key.code == Keyboard::A) {
                    moveLeft(sprites, board, idx);
                    settings.getGameSound().play();
                }

                if (event.key.code == Keyboard::D) {
                    moveRight(sprites, board, idx);
                    settings.getGameSound().play();
                }
            }
        }

        if (checkWin(board)) {
            settings.getWindow().clear(Color(229, 205, 196));
            settings.getWindow().draw(settings.getWinImage());
            settings.getGameWin().play();
            settings.getWindow().display();
            sleep(seconds(3));
            return;
        } else {
            settings.getWindow().clear(Color(229, 205, 196));
            settings.getWindow().draw(settings.getGameName());
            settings.getWindow().draw(settings.getBackground());
            draw(settings.getWindow(), sprites);
            settings.getWindow().display();
        }
    }
}