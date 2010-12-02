#include "../include/sprite_sheet.h"

#include <SDL/SDL_image.h>
#include <cstring>
#include <iostream>

float SpriteSheet::brightness = 1;

SpriteSheet::SpriteSheet(std::string name, int sprite_width, int sprite_height)
	: sprite_width(sprite_width), sprite_height(sprite_height) {

	// Get the full filepath to the image
    std::string full_filename = "./media/images/" + name;

    // Try and load the image if we can't load the image display a error and setup basic black texture;
    if(!loadImage(full_filename)) {
		std::cout << "Failed to load " << full_filename << "\n";
		texture = 0;
		this->sheet_width = 16;
		this->sheet_height = 16;
	} else {
		std::cout << "Loaded " << full_filename << "\n";
	}
	
	// If either of these values are 0, assume that the SpriteSheet is one large sprite!
	if (sprite_width == 0 || sprite_height == 0) {
		this->sprite_width = sheet_width;
		this->sprite_height = sheet_height;
		sprites_in_x = 1;
		sprites_in_y = 1;
	} else {
		sprites_in_x = sheet_width / sprite_width;
		sprites_in_y = sheet_height / sprite_height;
	}

}

SpriteSheet::~SpriteSheet() {

    if (texture >= 0) {
		glDeleteTextures(1, &texture);
	}
	
}

void SpriteSheet::draw(float x, float y, int sprite_x, int sprite_y, float rotation, float alpha) const {

	float w = sprite_width / 2.0f;
	float h = sprite_height / 2.0f;

	// Change rotation to degrees.
	if (rotation != 0.0) {
		rotation *= 180.0f / 3.141592f;
	}
	
    // Push the matrix to translate the image to (x,y), then rotate it.
	glPushMatrix();
	glTranslatef(x, y, 0.0f);
	glRotatef(rotation, 0.0f, 0.0f, 1.0f);
    // Set the current texture.
	glBindTexture(GL_TEXTURE_2D, texture);
	
	// Calculate the top left corner of the sprite in texture space.
	float top_left_x = (sprite_x * sprite_width) / sheet_width;
	float top_left_y = (sprite_y * sprite_height) / sheet_height;
	
    // Draw a quad (Rectangle) to display the sprite at the origin.
    // The matrix above will move it to the desired position/orientation.
    // This might not be the NICEST maths to do this...
	glBegin(GL_QUADS);
		glColor4f(brightness, brightness, brightness, alpha);
		glTexCoord2f(top_left_x, top_left_y); glVertex2f(-w, -h);
		glTexCoord2f(top_left_x + (sprite_width / sheet_width), top_left_y); glVertex2f( w, -h);
		glTexCoord2f(top_left_x + (sprite_width / sheet_width), top_left_y + (sprite_height / sheet_height)); glVertex2f( w, h);
		glTexCoord2f(top_left_x, top_left_y + (sprite_height / sheet_height)); glVertex2f(-w, h);
	glEnd();
	
    // Remove the matrix so we can draw other things.
	glPopMatrix();

}

bool SpriteSheet::loadImage(std::string full_filename) {

	// Create an SDL_SURFACE with image loaded on it
	SDL_Surface* surface = IMG_Load(full_filename.c_str());
	
    // If the surface couldn't be loaded, throw an error.
	if (!surface) 
        return false;
	
    // Get image width and height
	sheet_width = surface->w;
	sheet_height = surface->h;
	
    // Do formating for colour levels of image.
	int format, format2;
	GLint colors = surface->format->BytesPerPixel;
	if (colors == 4) {
		format = GL_RGBA;
		if (surface->format->Rmask == 0x000000ff) 
            format2 = GL_RGBA;
		else format2 = GL_BGRA_EXT;
	} else
        if (colors == 3) {
		    format = GL_RGB;
		    if (surface->format->Rmask == 0x000000ff) 
                format2 = GL_RGB;
		    else 
                format2 = GL_BGR_EXT;
	} else {
		printf("Image is not truecolour: %s\n", full_filename.c_str());
		return false;
	}
	
	// Create an OpenGL texture.
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	
	// Copy texture data.
	glTexImage2D( GL_TEXTURE_2D, 0, format,
				sheet_width, sheet_height, 0, format2,
				GL_UNSIGNED_BYTE, surface->pixels );
	
    // Free the surface now the texture has been loaded.
	SDL_FreeSurface(surface);
	
	return true;

}
