#ifndef __SPLASH_SCREEN_H__
#define __SPLASH_SCREEN_H__

#include "window.h"
#include "camera.h"
#include "screen.h"
#include "sprite_sheet.h"
#include "sound.h"
#include <iostream>
#include "engine.h"

class SplashScreen : public Screen {

	public:
	SplashScreen(): frame(0), fade(0) {
		WGDMotor::Engine::spriteManager.loadSpriteSheet("splash.tga");
		splash = WGDMotor::Engine::spriteManager.getSpriteSheet("splash.tga");
		camera = new Camera(Vector2D(0, 0), 1);
		Sound::playMusic(MUS3);
	}
	
	~SplashScreen() {
		delete camera;
	}
	
	// Fade the splash screen in and out.
	void update() {
		frame++;
		
		 if(frame < 25)
			fade+=0.04;
		else if(frame >= 55 && frame < 90)
			fade-=0.04;
		else if(frame >= 90)
			exit(0);
	}	
	
	// Draw the splash screen.
	void draw() const {
		glClear(GL_COLOR_BUFFER_BIT);

		camera->use();
	
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();		
		splash->draw(0, 0, 0 ,0 ,0 ,fade);
	}
	
	// No need to draw an overlay...
	void drawOverlay() const {}

	private:
	int frame;
	float fade;
	SpriteSheet* splash;

};

#endif
