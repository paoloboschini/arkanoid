Arkanoid
========

A rudimentary implementation of the game Arkanoid.
Much like the game Breakout, the player controls the "Vaus", a space vessel that acts as the game's "paddle" which prevents a ball from falling from the playing field, attempting to bounce it against a number of bricks. The ball striking a brick causes the brick to disappear. When all the bricks are gone, the player goes to the next level. This functionality has not been implemented, instead the game has to be restarted. Furthermore, the ball can also bounce on the bottom of the window. The space vessel is controlled by pressing the left and right arrow keys.

OSX
========

To build on OSX you need to install these libraries and copy them in /Library/Frameworks:

- SDL\_image-1.2.12.dmg from [here](http://www.libsdl.org/projects/SDL_image)
- SDL-1.2.15.dmg from [here](http://www.libsdl.org/download-1.2.php)

Run with **make && ./arkanoid**

Ubuntu Linux
========

To build on Ubuntu you need to install these libraries from software centre:

- libsdl-image1.2
- libsdl-image1.2-dev
- libsdl1.2debian
- libsdl1.2-dev

Run with **make && ./arkanoid**

![alt tag](https://raw.github.com/paoloboschini/arkanoid/master/screen.png)