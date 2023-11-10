#include "../include/game.hpp"

int main()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(1000, 850), "Fifteen-puzzle");
    
    int board[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};
    int idx = SIZE - 1;

    Sprite *sprites = fillSprites();

    shuffle(sprites, board);

    // Проверка расстановки на четность
    bool flag = false;
    while (flag) {
        if (!checkPuzzle(board)) {
            shuffle(sprites, board);
            flag = true;
        }
    }

    
    // Загрузка текстуры для бэкграунда и победного сообщения
    Texture backgroundTexture, winImageTexture;
    backgroundTexture.loadFromFile("textures/background.png");
    winImageTexture.loadFromFile("textures/win.png");

    // Установка тексутры на спрайт
    Sprite background, winImage;
    background.setTexture(backgroundTexture);
    background.setScale(7.0f,7.0f);
    background.setPosition(150.f, 145.f);    
    winImage.setTexture(winImageTexture);
    winImage.setPosition(200.f, 200.f);
    winImage.setScale(0.7f, 0.7f);

    // Загрузка шрифта
    Font font;
    font.loadFromFile("fonts/ds-pixel-cyr.ttf");

    // Работа с текстом
    Text gameName;
    gameName.setFont(font);
    gameName.setString("Fifteen - puzzle");
    gameName.setCharacterSize(98);
    gameName.setFillColor(Color(0,0,0));
    gameName.setPosition(110.f, 20.f);

    // Загрузка звука
    SoundBuffer gameSoundBuffer, gameWinBuffer;
    gameSoundBuffer.loadFromFile("sound/game-sound.wav");
    gameWinBuffer.loadFromFile("sound/win-sound.wav");

    // Работа со звуком
    Sound gameSound, gameWin;
    gameSound.setBuffer(gameSoundBuffer);
    gameSound.setVolume(15);
    gameWin.setBuffer(gameWinBuffer);
    gameWin.setVolume(30);
    
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }

            if(event.type == Event::KeyPressed && (!checkWin(board))) {

                if (event.key.code == Keyboard::Escape) {
                    window.close();
                }

                if (event.key.code == Keyboard::W) {
                    
                    // Движение вверх
                    moveUp(sprites, board, &idx);
                    gameSound.play();
                }

                if (event.key.code == Keyboard::S) {
                    
                    // Движение вниз
                    moveDown(sprites, board, &idx);
                    gameSound.play();
                }

                if (event.key.code == Keyboard::A) {
                    
                    // Движение влево
                    moveLeft(sprites, board, &idx);
                    gameSound.play();
                }

                if (event.key.code == Keyboard::D) {
                    // Движение вправо
                    moveRight(sprites, board, &idx);
                    gameSound.play();
                }
            }
        }

        if (checkWin(board)) {
            
            window.clear(Color(229, 205, 196));
            window.draw(winImage);
            gameWin.play();
            window.display();
            sleep(seconds(3));
            return 0;
        } else {
           
            window.clear(Color(229, 205, 196));
            window.draw(gameName);
            window.draw(background);
            draw(window, sprites);
            window.display();
        }
    }
    return 0;
}
