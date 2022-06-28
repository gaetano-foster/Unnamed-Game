#include "Mineclone.hh"

int main() {
    Mineclone game("Hello World", 1280, 720, 72);
    game.start();
    return game.getExitCode();
}