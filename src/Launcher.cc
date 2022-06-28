#include "Mineclone.hh"

int main() {
    Mineclone game("Hello World", 1280, 720, 1000);
    game.start();
    return game.getExitCode();
}