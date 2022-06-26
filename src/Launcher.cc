#include "Mineclone.hh"

int main() {
    Mineclone game("Hello World", 1280, 720, 10000);
    game.start();
    return game.getExitCode();
}