/*
 *  Engine.h
 *
 *  Created by Paolo Boschini on 12/8/10.
 *
 */

#ifndef ENGINE_H
#define ENGINE_H

#include <SDL.h>
#include <vector>
#include "Sprite.h"

namespace enginespace {

  class Engine {
  public:
    Engine();
    ~Engine();
    void add(Sprite* sprite);
    void run();
    void checkCollisions();
    std::vector<Sprite*> &getSprites();
  private:
    std::vector<Sprite*> sprites;
    Uint32 bgColor;
    void forAll( void (Sprite::*mf)());
  };
}
#endif