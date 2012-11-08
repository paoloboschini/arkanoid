/*
 *  Block.h
 *  SDL
 *
 *  Created by Paolo Boschini on 12/9/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef BLOCK_H
#define BLOCK_H

#include "Sprite.h"

namespace enginespace {
  
  class Block : public Sprite {
  public:
    ~Block();
    static Block* getInstance(int x, int y, int w, int h, Image &im);
    void draw();
  private:
    Block(int x, int y, int w, int h, Image &im);
  };
}
#endif