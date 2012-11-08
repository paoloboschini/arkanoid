/*
 *  Block.cpp
 *
 *  Created by Paolo Boschini on 12/9/10.
 *
 */

#ifdef __APPLE__
#include <SDL_image/SDL_image.h>
#else
#include <SDL/SDL_image.h>
#endif

#include "Block.h"
#include "Globals.h"

namespace enginespace {
  
  Block::Block(int x, int y, int w, int h, Image &im):Sprite(x, y, w, h, im) {
  }
  
  Block::~Block() {}
  
  Block* Block::getInstance(int x, int y, int w, int h, Image &im) {
    return new Block(x, y, w, h, im);
  }
  
  void Block::draw() {
    SDL_Rect tmp = getRect();
    SDL_Rect tmp2 = {0, 0, tmp.w, tmp.h};
    SDL_BlitSurface(image.getSurface(), &tmp2, sys.screen, &tmp);
  }
}