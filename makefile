UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
  all:	main.cpp
		g++ *.cpp -o arkanoid `pkg-config --cflags --libs sdl` -lSDL_image
endif
ifeq ($(UNAME), Darwin)
  all:	main.cpp
		g++ -I /Library/Frameworks/SDL.framework/Headers *.cpp SDLmain.m -o arkanoid -framework SDL -framework Cocoa -framework SDL_image
endif