#ifndef _INPUT_H_
#define _INPUT_H_

#include <SDL/SDL.h>

/**
 * Mouse and keyboard input.
 */
class Input {

	public:
	static void checkEvents();
	
	static bool isPressed(SDLKey key) {
		return (keystate[key] != 0);
	}
	
	static int getMouseX() { return mouseX; }
	static int getMouseY() { return mouseY; }
	
	static bool isMousePressed(int button) {
		return (mousestate & SDL_BUTTON(button)) != 0;
	}
	
	private:
	static Uint8* keystate;
	static Uint8 mousestate;
	static int mouseX;
	static int mouseY;
	static int changeX;
	static int changeY;

};

#endif
