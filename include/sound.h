#ifndef _SOUND_H_
#define _SOUND_H_

#include "cstdio"
#include <SDL/SDL_mixer.h>

typedef enum { PICKUP, SHUR, DIE, FANFARE, SEEN, INVIS, HIT, GHOSTDEATH } sound_t;
typedef enum { MUS1, MUS2, MUS3, MUS4 } music_t;

class Sound {
	
	public:
	static void init();
	static void cleanup();
	static void checkLoad(Mix_Music*, char*);
	static void checkLoad(Mix_Chunk*, char*);
	static Mix_Chunk *getChunk(sound_t);
	static void play(sound_t);
	static void play(sound_t, int);
	static void playMusic(music_t);
	static Mix_Music* getMusic (music_t which);
	static void haltMusic();


};

#endif
