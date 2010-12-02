#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "../include/window.h"
#include "../include/sprite_manager.h"

SDL_Surface* Window::s_screen = 0;

int Window::s_width = 800;
int Window::s_height = 600;

int Window::s_fullscreen_width;
int Window::s_fullscreen_height;

int Window::s_old_width;
int Window::s_old_height;

bool Window::s_fullscreen = false;

/**
 * Create a new Window with the specified dimensions and title.
 *
 * @param width The width of the window.
 * @param height The height of the window.
 * @param title The title of the window.
 */
bool Window::init(const int width, const int height, const char* title) {
	
	s_width = width;
	s_height = height;
	
	// Centre the window.
	putenv("SDL_VIDEO_WINDOW_POS");
	putenv("SDL_VIDEO_CENTERED=1");
	getenv("SDL_VIDEO_WINDOW_POS");
	getenv("SDL_VIDEO_CENTERED");

	// Check if we can initialise SDL video.
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
		fprintf(stderr, "Unable to initalise SDL: %s\n", SDL_GetError());
		return false;
	}    
	atexit(SDL_Quit);

	const SDL_VideoInfo* videoInfo = SDL_GetVideoInfo();
	
	s_fullscreen_width = videoInfo->current_w;
	s_fullscreen_height = videoInfo->current_h;
	
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);  

	SDL_WM_SetCaption(title, NULL);
	
	return reset();

}

/**
 * Resets the Window.
 */
bool Window::reset () {
	Uint32 flags = SDL_DOUBLEBUF | SDL_HWSURFACE | SDL_OPENGL | SDL_ANYFORMAT;
	
	if (s_fullscreen) {flags |= SDL_FULLSCREEN; }
	
	s_screen = SDL_SetVideoMode(s_width, s_height, 32, flags);
	
	if (s_screen == NULL) {
		fprintf(stderr, "Unable to set video mode: %s\n", SDL_GetError());
		return false;
	}
	
	// Reload all of the textures.
	//SpriteManager::init();
	
	glViewport(0, 0, s_width, s_height);
	
	return true;
}

/**
 * Sets whether the Window is full screen or not.
 *
 * @param b true if the Window should be full screen, false otherwise.
 */
void Window::setFullscreen (bool b) {
	s_fullscreen = b;
	
	if (s_fullscreen) {
		s_old_width = s_width;
		s_old_height = s_height;
		SDL_ShowCursor(false);
		
		if (true) {
			s_width = s_fullscreen_width;
			s_height = s_fullscreen_height;			
		}
	} else if (true) {
		s_width = s_old_width;
		s_height = s_old_height;
		SDL_ShowCursor(true);
	}
	
	reset();
}

/**
 * Toggle whether the Window is full screen.
 */
void Window::toggleFullscreen () {
	setFullscreen(! s_fullscreen);
}

