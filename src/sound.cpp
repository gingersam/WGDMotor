#include "../include/sound.h"



void Sound::init () {
	int rate = 22050;
	Uint16 format = AUDIO_S16;
	int channels = 2;
	int chunksize = 1024;
	if (Mix_OpenAudio(rate, format, channels, chunksize) != 0) {
		fprintf(stderr, "Unable to initialize audio: %s\n",
		        Mix_GetError());
		return;
	}

	atexit(Mix_CloseAudio);


	
}

void Sound::cleanup () {
	Mix_CloseAudio();
}

void Sound::checkLoad (Mix_Chunk *chunk, char *file) {
	if (chunk == NULL)
		fprintf(stderr, "Unable to load %s: %s\n",
		        file, Mix_GetError());
}

void Sound::checkLoad (Mix_Music *music, char *file) {
	if (music == NULL)
		fprintf(stderr, "Unable to load %s: %s\n",
		        file, Mix_GetError());
}

Mix_Chunk *Sound::getChunk (sound_t which) {
	switch(which) {
	default:      return NULL;
	}
}

Mix_Music *Sound::getMusic (music_t which) {
	switch(which) {
	default:      return NULL;
	}
}

void Sound::play (sound_t which) {
	play(which, MIX_MAX_VOLUME);
}

void Sound::play (sound_t which, int volume) {
	Mix_Chunk *sound = getChunk(which);
	if (!sound) return;

	/* Setting channel after starting it playing appears to work as
	   expected, without sudden volume gradients. */
	int channel = Mix_PlayChannel(-1, sound, 0);
	if (channel != -1)
		Mix_Volume(channel, volume);
}

void Sound::playMusic(music_t which) {
	Mix_Music *music = getMusic(which);
	if (!music) return;
	Mix_HaltMusic();
	Mix_PlayMusic(music, -1);
}

void Sound::haltMusic() {
	Mix_HaltMusic();
}
