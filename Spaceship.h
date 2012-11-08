/*
 *  Spaceship.h
 *
 *  Created by Paolo Boschini on 12/9/10.
 *
 */

#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "Sprite.h"
#include <string>

namespace enginespace {
  
  class Spaceship : public Sprite {
  public:
    ~Spaceship();
    static Spaceship* getInstance(int x, int y, int w, int h, Image &im);
    void draw();
    void moveLeft();
    void moveRight();
  private:
    Spaceship(int x, int y, int w, int h, Image &im);
  };
}
#endif