#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <SDL/SDL.h>

/**
 * Class for creating and interfacing with a window...
 */
class Window {

	public:
	static bool init(const int width, const int height, const char* title);
	static void resize(const int width, const int height);
	static SDL_Surface* getSurface() { return s_screen; };
	
	static int getWidth() { return s_width; }
	static int getHeight() { return s_height; }
	
	static bool isFullscreen() { return s_fullscreen; }
	static void setFullscreen(bool b);
	static void toggleFullscreen();
	
	private:
	
	static bool reset();
	
	static SDL_Surface* s_screen;
	
	static int s_width;
	static int s_height;
	
	static int s_fullscreen_width;
	static int s_fullscreen_height;
	
	static int s_old_width;
	static int s_old_height;
	
	static bool s_fullscreen;

};

#endif
