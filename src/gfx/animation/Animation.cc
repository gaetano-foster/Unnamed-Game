#include "Animation.hh"

Animation::Animation(std::vector<Sprite*> frames, float delay)
    : m_frames(frames)
    , m_delay(delay)
{ }

Animation::Animation()
{ }

Animation::~Animation()
{ }

bool Animation::update(float deltaTime) {
    static float shouldSwitch = 0.0f;
    shouldSwitch += deltaTime;
    if (shouldSwitch >= m_delay) {
        m_index++;
        shouldSwitch = 0;
    }
    if (m_index >= m_frames.size())
        m_index = 0;
    return true;
}

bool Animation::render(SDL_Renderer *renderer, int x, int y, int width, int height) {
    return m_frames[m_index]->render(renderer, x, y, width, height);
}
