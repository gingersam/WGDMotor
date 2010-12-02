#include "../include/input.h"
#include "../include/window.h"
#include "../include/vector.h"
#include "../include/screen.h"

// Static members.
Uint8* Input::keystate = 0;
Uint8 Input::mousestate = 0;
int Input::mouseX = 0;
int Input::mouseY = 0;
int Input::changeX = 0;
int Input::changeY = 0;

/**
 * Update the values of keystate, mousestate, mouseX and mouseY
 * based on current keyboard and mouse state.
 */
void Input::checkEvents () {

	SDL_Event event;

	while (SDL_PollEvent(&event)) {

		switch (event.type) {

			case SDL_QUIT:
				exit(1);
				break;

			case SDL_KEYDOWN:
				
				switch (event.key.keysym.sym) {

					case SDLK_f:
						Window::toggleFullscreen();
						break;
					
					case SDLK_ESCAPE:
						exit(1);
						break;

					default:
						//ScreenManager::handleInput(event);
						break;
				}
				
			default:
				break;

		}
		
	}
	
	keystate = SDL_GetKeyState(NULL);
	mousestate = SDL_GetMouseState(&mouseX, &mouseY);

}
