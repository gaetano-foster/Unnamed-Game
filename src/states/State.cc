#include "State.hh"
#include "Mineclone.hh"

State::State(Mineclone *game) 
    : m_game(game)
    , m_name(std::string("null"))
{ }

State::~State() 
{ }

std::string State::getName() {
    return m_name;
}

Mineclone* State::getGame() {
    return m_game;
}
