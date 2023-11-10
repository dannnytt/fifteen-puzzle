# Fifteen-puzzle (Пятнашки)
## Инструкциия по примению
1. Сколонируйте репозиторий:
    ```
    $ git clone git@github.com:DanielTernovskiy/fifteen-puzzle.git
    ```
2. Сборка и запуск проекта:
    ```
   > g++ -o bin/app src/main.cpp src/game.cpp -Iinclude -Llib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
   > ./bin/app.exe
    ```