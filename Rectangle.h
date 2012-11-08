/*
 *  Rectangle.h
 *
 *  Created by Paolo Boschini on 12/9/10.
 *
 */

#ifndef RECTANGLE_H
#include <SDL.h>

namespace enginespace {
  
  struct Rectangle : public SDL_Rect {
    Rectangle();
    Rectangle(int xx, int yy, int ww, int hh);
    bool contains(int xx, int yy) const;
    Rectangle centeredRect(int width, int height) const;
    bool overlaps(const Rectangle& other) const;
  };
}
#endif