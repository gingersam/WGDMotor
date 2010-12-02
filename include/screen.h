#ifndef _SCREEN_H_
#define _SCREEN_H_

union SDL_Event;

#include "camera.h"

class Screen {
	
	public:
	Screen () {}
	virtual ~Screen () { delete camera; }
	
	/** Called when the screen is made active (could be multiple times). */
	virtual void init () {}
	
	/** Input has been received. */
	virtual void handleInput (SDL_Event& e) {}
	
	/** Called once per frame while the screen is active. */
	virtual void update () = 0;
	
	/** Called once per frame while the screen is active. */
	virtual void draw () const = 0;

	/** Called once per frame while the screen is active. */
	virtual void drawOverlay () const = 0;
	
	/** Called when the screen is replaced (could be multiple times). */
	virtual void finalise () {}
	
	/** Returns true if after the screen has been replaced it should be deleted. */
	virtual bool deletable () const { return false; }
	

	
	protected:
	Camera* camera;	// Camera!
};

class ScreenManager {
	public: 
	ScreenManager(Screen*s) : activeScreen(s) {}
	/** Get the active screen. */
	Screen* getScreen () { return activeScreen; }
	
	/** Set the active screen. */
	void setScreen (Screen* s);
	
	/** Send input to the active screen, checking for null-ness. */
	void handleInput (SDL_Event& e) {
		if (activeScreen) {
			activeScreen->handleInput(e);
		}
	}
	
	/** Updates the active screen, checking for null-ness. */
	void update () {
		if (activeScreen) {
			activeScreen->update();
		}
	}
	
	/** Draws the active screen, checking for null-ness. */
	void draw () {
		if (activeScreen) {
			activeScreen->draw();
		}
	}

	/** Draws the active screen's overlays, checking for null-ness. */
	void drawOverlay () {
		if (activeScreen) {
			activeScreen->drawOverlay();
		}
	}
	
	private:
	
	Screen* activeScreen;
};


#endif

