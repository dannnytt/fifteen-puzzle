all: main

.PHONY: main
main: main.cpp
    g++ -o $@ $^ -lsfml-graphics -lsfml-window -lsfml-system

clean:
    rm -rf main *.o