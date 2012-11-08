/*
 *  Image.h
 *
 *  Created by Paolo Boschini on 12/2/10.
 *
 */

#ifndef IMAGE_H
#define IMAGE_H

#include <string>

class Image {
public:
  Image();
  Image(std::string fileName, bool transparent);
  Image(const Image& other);
  const Image& operator=(const Image& other);
  ~Image();
  SDL_Surface* getSurface() const;
private:
  bool transparent;
  SDL_Surface* pictureSurface;
};
#endif