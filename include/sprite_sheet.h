#ifndef __SPRITE_SHEET_H__
#define __SPRITE_SHEET_H__

#include <string>
#include <SDL/SDL_opengl.h>

class SpriteSheet {

	public:
	SpriteSheet(std::string name, int sprite_width, int sprite_height);
	SpriteSheet(std::string name) { SpriteSheet(name, 0, 0); }
	~SpriteSheet();
	
	static float brightness; // global brightness value.
		
	// Draw at x, y.
	// By default, draw the first sprite with no rotation, fully opaque.
	void draw(float x, float y, int sprite_x = 0, int sprite_y = 0, float rotation = 0.0f, float alpha = 1.0f) const;
	
	protected:
	bool loadImage(std::string name);	// Load the spritesheet in from file.
	
	GLuint texture;		// Texture.
	int sheet_width;	// Width of the sprite sheet.
	int sheet_height;	// Height of the sprite sheet.
	float sprite_width;	// Width of each sprite in the sheet.
	float sprite_height;	// Height of each sprite in the sheet.
	int sprites_in_x;	// Number of sprites in x direction.
	int sprites_in_y;	// Number of sprites in y direction.

};

#endif
