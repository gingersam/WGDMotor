#ifndef __ENGINE_H__
#define __ENGINE_H__

#include <SDL/SDL.h>
#include <GL/gl.h>
#include "screen.h"
#include "sprite_manager.h"
#include "window.h"
#include "screen.h"
#include "sound.h"
#include <ctime>
#include <cstdlib>
#include "timer.h"

namespace WGDMotor {

	class Engine {

		public:
		
		static void init();
		static void run();
		static void update();
		static void draw();
		static void checkEvents();

		static ScreenManager screenManager;
		static SpriteManager spriteManager;

		private:
//		static SoundManager soundManager;

		/* Some sort of model manager and shader manager later*/
	};
}

#endif
