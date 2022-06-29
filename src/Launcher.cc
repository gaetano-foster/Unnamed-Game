#include "Game.hh"

int main() {
    Game game("Hello World", 1280, 720, 72);
    game.start();
    return game.getExitCode();
}