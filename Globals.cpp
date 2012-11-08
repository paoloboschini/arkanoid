/*
 *  Globals.cpp
 *
 *  Created by Paolo Boschini on 12/8/10.
 *
 */

#include <SDL.h>
#include "Globals.h"
#include "ErrorException.h"

using namespace std;

namespace enginespace {
  
  Globals sys;

  void Globals::Globals_Init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
      throw ErrorException(SDL_GetError());
    }
    screen = SDL_SetVideoMode(800, 600, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
  }
  
  Globals::~Globals() {
    SDL_Quit();
  }
}