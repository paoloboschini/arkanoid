/*
 *  Image.cpp
 *
 *  Created by Paolo Boschini on 12/2/10.
 *
 */

#ifdef __APPLE__
#include <SDL_image/SDL_image.h>
#else
#include <SDL/SDL_image.h>
#endif

#include <SDL.h>
#include <string>
#include <iostream>
#include "Image.h"

using namespace std;

Image::Image() {
  pictureSurface = NULL;
}

Image::Image(string fileName, bool t) {
  SDL_Surface *tempPictureSurface = IMG_Load(fileName.c_str());
  
  if (!tempPictureSurface) {
    cout << "Picture file not found!\n";
    exit(0);
  }

  pictureSurface = SDL_DisplayFormatAlpha(tempPictureSurface);
  SDL_FreeSurface(tempPictureSurface);

  if (t) {
    Uint32 transp = *(Uint16*)(pictureSurface) -> pixels;
    SDL_SetColorKey(pictureSurface, SDL_SRCCOLORKEY | SDL_RLEACCEL, transp);
  }
}

Image::Image(const Image& other) {
  other.pictureSurface -> refcount++;
  pictureSurface = other.pictureSurface;
}

const Image& Image::operator=(const Image& other) {
  if (&other != this) {
    SDL_FreeSurface(pictureSurface);
    other.pictureSurface -> refcount++;
    pictureSurface = other.pictureSurface;
  }
  return *this;
}

Image::~Image() {
  SDL_FreeSurface(pictureSurface);
}

SDL_Surface* Image::getSurface() const {
  return pictureSurface;
}