/*
 *  Sprite.h
 *
 *  Created by Paolo Boschini on 12/9/10.
 *
 */

#ifndef SPRITE_H
#define SPRITE_H

#include "Rectangle.h"
#include "Image.h"

namespace enginespace {
  class Engine;
  class Sprite {
  public:
    virtual ~Sprite();
    Rectangle& getRect();
    virtual void draw() = 0; 
    virtual void moveLeft();
    virtual void moveRight();
    virtual void bounce();
    virtual void hasCollidedWith(Sprite *other, Engine *engine);
  protected:    
    Sprite(int x, int y, int w, int h, Image &im);
    Image &image;
  private:
    Rectangle rect;
    Sprite(const Sprite& other);
    const Sprite& operator=(const Sprite *other);
  };
}
#endif