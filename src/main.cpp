#include <SDL/SDL.h>
#include <GL/gl.h>
#include <ctime>
#include <cstdlib>

#include "../include/engine.h"


#include "../include/splash_screen.h"
#include "../include/input.h"
#include "../include/timer.h"

int main(int argc, char *argv[]) {
	
	WGDMotor::Engine::init();
	WGDMotor::Engine::screenManager.setScreen(new SplashScreen());
	WGDMotor::Engine::run();
	
	return (EXIT_SUCCESS);

}
