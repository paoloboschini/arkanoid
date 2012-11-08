/*
 *  Engine.cpp
 *
 *  Created by Paolo Boschini on 12/8/10.
 *
 */

#include "Sprite.h"
#include "Engine.h"
#include "Globals.h"
#include "ErrorException.h"
#include <vector>

#define FPS 60

namespace enginespace {
  
  Engine::Engine() {
    bgColor = SDL_MapRGB(sys.screen -> format, 100, 100, 100);
  }
  
  Engine::~Engine() {
    for(unsigned int i = 0; i < sprites.size(); i++)
      delete sprites[i];
  }
  
  void Engine::add(Sprite* ny) {
    sprites.push_back(ny);
  }

  void Engine::run() {
    SDL_EnableKeyRepeat(10, 10);
    bool quit = false;
    int tickInterval = 1000 / FPS;
    Uint32 nextTick;
    
    while (!quit) {
      nextTick = SDL_GetTicks() + tickInterval;
      SDL_Event eve;
      while (SDL_PollEvent(&eve)) {
        switch(eve.type) {
          case SDL_KEYDOWN:
            if (eve.key.keysym.sym == SDLK_ESCAPE)
              quit = true;
            else {
              switch(eve.key.keysym.sym) {
                case SDLK_UP:
                  break;
                case SDLK_DOWN:
                  break;
                case SDLK_LEFT:
                  forAll(&Sprite::moveLeft);
                  break;
                case SDLK_RIGHT:
                  forAll(&Sprite::moveRight);
                  break;
              } // switch
            } // else
            break;
          case SDL_QUIT:
            quit = true;
            break;
          case SDL_MOUSEBUTTONDOWN:
            break;
          case SDL_MOUSEBUTTONUP:
            break;
        } // switch
      } // while poll
      
      SDL_FillRect(sys.screen, NULL, bgColor);

      forAll(&Sprite::draw);
      forAll(&Sprite::bounce);
      checkCollisions();
      
      SDL_Flip(sys.screen);

      int delay = nextTick - SDL_GetTicks();
      if (delay > 0)
        SDL_Delay(delay);
    } // while
  } // run
  
  void Engine::forAll(void (Sprite::*mf)()) {
    for(unsigned int i = 0; i < sprites.size(); i++)
      (sprites[i] ->* mf)();
  }

  void Engine::checkCollisions() {
    for(unsigned int i = 0; i < sprites.size(); i++)
      for(unsigned int j = 0; j < sprites.size(); j++)
        if (sprites[j] != sprites[i] && (sprites[j]->getRect()).overlaps(sprites[i]->getRect())) {
          sprites[i] -> hasCollidedWith(sprites[j], this);
          sprites[j] -> hasCollidedWith(sprites[i], this);
        }
  }

  std::vector<Sprite*> &Engine::getSprites() {
    return sprites;
  } 
}