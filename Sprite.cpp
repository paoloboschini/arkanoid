/*
 *  Sprite.cpp
 *
 *  Created by Paolo Boschini on 12/9/10.
 *
 */

// fix copy, assignment operator, default contructor

#include "Sprite.h"
#include "Engine.h"

namespace enginespace {
  Sprite::Sprite(int x, int y, int w, int h, Image &im):rect(x, y, w, h), image(im) {}
  Sprite::~Sprite() {}
  Rectangle& Sprite::getRect() {return rect;}
  void Sprite::moveLeft() {}
  void Sprite::moveRight() {}
  void Sprite::bounce() {}
  void Sprite::hasCollidedWith(Sprite* other, Engine *engine) {}
}