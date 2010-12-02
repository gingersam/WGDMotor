#include "../include/screen.h"


void ScreenManager::setScreen (Screen* newScreen) {
	if (activeScreen == newScreen) {
		return;
	}
	
	if (activeScreen) {
		activeScreen->finalise();
		
		if (activeScreen->deletable()) {
			delete activeScreen;
		}
	}
	
	activeScreen = newScreen;
	
	if (newScreen) {
		newScreen->init();
	}
}

