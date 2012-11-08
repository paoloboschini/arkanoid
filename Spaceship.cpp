/*
 *  Spaceship.cpp
 *
 *  Created by Paolo Boschini on 12/9/10.
 *
 */

#ifdef __APPLE__
#include <SDL_image/SDL_image.h>
#else
#include <SDL/SDL_image.h>
#endif

#include "Spaceship.h"
#include "Globals.h"

namespace enginespace {
  
  Spaceship::Spaceship(int x, int y, int w, int h, Image &im):Sprite(x, y, w, h, im) {}
  Spaceship::~Spaceship() {}
  Spaceship* Spaceship::getInstance(int x, int y, int w, int h, Image &im) {
    return new Spaceship(x, y, w, h, im);
  }
  
  void Spaceship::draw() {
    SDL_Rect tmp = getRect();
    SDL_Rect tmp2 = {0, 0, tmp.w, tmp.h};
    SDL_BlitSurface(image.getSurface(), &tmp2, sys.screen, &tmp);
  }
  
  void Spaceship::moveLeft() {
    if (getRect().x > 0)
      getRect().x -= 5;
  }
  
  void Spaceship::moveRight() {
    if (getRect().x + getRect().w < sys.screen -> w)
      getRect().x += 5;
  }
}