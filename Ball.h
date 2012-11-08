/*
 *  Ball.h
 *
 *  Created by Paolo Boschini on 12/9/10.
 *
 */

#ifndef BALL_H
#define BALL_H

#include "Sprite.h"

namespace enginespace {

  class Ball : public Sprite {
  public:
    ~Ball();
    static Ball* getInstance(int x, int y, int w, int h, Image &im);
    void draw();
    void bounce();
    void hasCollidedWith(Sprite *other, Engine *engine);
  private:
    int xx, yy;
    Ball(int x, int y, int w, int h, Image &im);
  };
}
#endif