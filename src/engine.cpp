#include "../include/engine.h"

namespace WGDMotor {


	class PointlessScreen : public Screen {
		void update() {}
		void draw() const {}	
		void drawOverlay() const {}

	};

	ScreenManager Engine::screenManager =0;
	SpriteManager Engine::spriteManager;

	void Engine::init(){
		Window::init(800, 600, "Game") ;
		spriteManager = SpriteManager();
		screenManager = ScreenManager(new PointlessScreen());
		srand((unsigned)time(0));

	}

	void Engine::run(){

		Timer timer;
		double previousTime = timer.getTime();
		double step = timer.getStep();
		double diff = 0.0;

		// Update/render loop.
		while (true) {
		
			update();
			draw();
		
			// Wait only if we have drawn quicker than the timer step.
			diff = timer.getTime() - previousTime;
			if (diff < step) {
				SDL_Delay( (int) ((step - diff) * 1000) );
			}
			previousTime = timer.getTime();
	
		}
	
	}

	void Engine::update(){
		checkEvents();
		screenManager.getScreen()->update();
	}

	void Engine::draw(){
		screenManager.getScreen()->draw();
		screenManager.getScreen()->drawOverlay();
		SDL_GL_SwapBuffers();
	}

	void Engine::checkEvents(){
	}
}
