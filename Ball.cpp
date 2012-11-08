/*
 *  Ball.cpp
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
#include "Ball.h"
#include "Block.h"
#include "Globals.h"
#include "Sprite.h"
#include "Engine.h"
#include <vector>

namespace enginespace {

  Ball::Ball(int x, int y, int w, int h, Image &im):Sprite(x, y, w, h, im) {
    xx = yy = -4;
  }

  Ball::~Ball() {}

  Ball* Ball::getInstance(int x, int y, int w, int h, Image &im) {
    return new Ball(x, y, w, h, im);
  }

  void Ball::draw() {
    SDL_Rect tmp = getRect();
    SDL_Rect tmp2 = {0, 0, tmp.w, tmp.h};
    SDL_BlitSurface(image.getSurface(), &tmp2, sys.screen, &tmp);
  }

  void Ball::bounce() {
    if (getRect().x > 0 && getRect().x + getRect().w < sys.screen -> w)
      getRect().x += xx;
    else {
      xx = xx*-1;
      getRect().x += xx;
    }
    if (getRect().y > 0 && getRect().y+getRect().h < sys.screen -> h)
      getRect().y += yy;
    else {
      // cout << "Game over!!!" << endl;
      yy = yy*-1;
      getRect().y += yy;
    }
  }

  void Ball::hasCollidedWith(Sprite *o, Engine *engine) {
    // has collided with the spaceship
    Spaceship *spaceShip = dynamic_cast<Spaceship*>(o);
    if (spaceShip != 0) {
      int ballPosition = getRect().x + getRect().w / 2;
      int partShip = o -> getRect().w / 4;
      int left = o -> getRect().x;
      int step1 = left + partShip;
      int step2 = left + partShip * 2;
      int step3 = left + partShip * 3;

      // reset the velocity
      if (xx > 0) xx = 4; else xx = -4;
      yy = 4;

      if (ballPosition < step1) {
        if (xx > 0)
          xx = xx * -1;
      }
      if (ballPosition > step1 && ballPosition < step2) {
        yy *= 1.5;
        xx *= 0.5;
        if (xx > 0)
          xx = xx * -1;
      }
      if (ballPosition > step2 && ballPosition < step3) {
        yy *= 1.5;
        xx *= 0.5;
        if (xx < 0)
          xx = xx * -1;
      }
      if (ballPosition > step3) {
        if (xx < 0)
          xx = xx * -1;
      }
      yy = yy *- 1;
      getRect().y += yy;
      return;
    }

    // has collided with a block
    Block *block = dynamic_cast<Block*>(o);
    if (block != 0) {
      std::vector<Sprite*> &sprites = engine -> getSprites();
      for (int i = 0; i < sprites.size(); ++i) {
        if (sprites[i] == o) {
          sprites.erase(sprites.begin() + i);
          break;
        }
      }

      int top = getRect().y;
      int bottom = getRect().y + getRect().h;
      int o_top = o -> getRect().y;
      int o_bottom = o -> getRect().y + o->getRect().h;
      int top_bottom = top - o_bottom;
      int bottom_top = bottom - o_top;

      if ((top_bottom >= -4 && top_bottom <= 4) || (bottom_top >= -4 && bottom_top <= 4)) {
        yy = yy * -1;
        getRect().y += yy;
      } else {
        xx = xx * -1;
        getRect().x += xx;
      }
    }
  }
}