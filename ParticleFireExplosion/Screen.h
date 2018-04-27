#pragma once
#ifndef SCREEN_H_
#define SCREEN_H_

#include <iostream>
#include <SDL.h>

using namespace std;

namespace sdlScreen {
  class Screen
  {
  private:
    SDL_Window * m_window;
    SDL_Renderer * m_renderer;
    SDL_Texture * m_texture;
    uint32_t *m_buffer;
  public:
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;
    bool init();
    bool processEvents();
    void exit(void);
    Screen();
    ~Screen();
  };
}

#endif /* SCREEN_H_ */
