/*
 *  main.cpp
 *
 *  Created by Paolo Boschini on 12/2/10.
 *
 */

#include "Block.h"
#include "Ball.h"
#include "Spaceship.h"
#include "Globals.h"
#include "Engine.h"

using namespace enginespace;
using namespace std;

int main(int argc, char *argv[]) {

  sys.Globals_Init();
  
  Engine engine;
  
  Image spaceshipImage("SpaceShip.png", 0);
  Spaceship *spaceship = Spaceship::getInstance(sys.screen -> w / 2 - spaceshipImage.getSurface() -> w / 2,
                          sys.screen -> h - spaceshipImage.getSurface() -> h * 2,
                          spaceshipImage.getSurface() -> w,
                          spaceshipImage.getSurface() -> h,
                          spaceshipImage);
  engine.add(spaceship);
  
  Image ballImage("sphere.png", 1);
  Ball *ball = Ball::getInstance(spaceship -> getRect().x + spaceship -> getRect().w/2 - ballImage.getSurface() -> w/2,
                   spaceship -> getRect().y - ballImage.getSurface() -> h,
                   ballImage.getSurface() -> w,
                   ballImage.getSurface() -> h,
                   ballImage);
  engine.add(ball);
  
  Image blockImage("Block.png", 0);
  for (int x = 0; x < sys.screen -> w / 100; x++) {
    for (int y = 1; y < 6; y++) {
      Block *block = Block::getInstance(x * 100,
                        y * 40,
                        blockImage.getSurface() -> w,
                        blockImage.getSurface() -> h,
                        blockImage);
      engine.add(block);
    }
  }
  
  engine.run();
  return 0;
}