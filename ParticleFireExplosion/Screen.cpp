#include "stdafx.h"
#include "Screen.h"

namespace sdlScreen {

  bool Screen::init() {

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
      return false;
    }

    m_window = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (m_window == NULL) {
      exit();
      return false;
    }
  
     m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
    if (m_renderer == NULL) {
      exit();
      return false;
    }

    m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
    if (m_texture == NULL) {
      exit();
      return false;
    }

    m_buffer = new uint32_t[SCREEN_WIDTH*SCREEN_HEIGHT];
    memset(m_buffer, 0x00, sizeof(uint32_t)*SCREEN_WIDTH*SCREEN_HEIGHT);
    for (int i=0; i < SCREEN_WIDTH*SCREEN_HEIGHT; i++) {
      m_buffer[i] = 0xFF0000FF;
    }

    SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH*sizeof(uint32_t));
    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
    SDL_RenderPresent(m_renderer);
    return true;

  }

  bool Screen::processEvents() {
  SDL_Event event;

  //Update particles
  //Draw particles
  //Check for messages/events
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      return false;
    }
  }
    return true;
  }

  void Screen::exit(void) {
    delete[] m_buffer;
    if (m_texture != NULL)
      SDL_DestroyTexture(m_texture);
    if (m_renderer != NULL)
      SDL_DestroyRenderer(m_renderer);
    if (m_window != NULL)
      SDL_DestroyWindow(m_window);
    SDL_Quit();
 }

  Screen::Screen() : 
    m_window(NULL),
    m_renderer(NULL),
    m_texture(NULL),
    m_buffer(NULL) {
  }
  


  Screen::~Screen()
  {
  }
} /* end of sdlScreen namespace */
