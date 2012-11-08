/*
 *  Globals.h
 *
 *  Created by Paolo Boschini on 12/8/10.
 *
 */

#ifndef GLOBALS_H
#define GLOBALS_H

#include <SDL.h>

namespace enginespace {
  
  struct Globals {
    void Globals_Init();
    ~Globals();
    SDL_Surface* screen;
  };
  
  extern Globals sys;
  
}
#endif