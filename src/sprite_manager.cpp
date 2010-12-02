#include "../include/sprite_manager.h"

#include <iostream>

void SpriteManager::loadSpriteSheet(std::string name, int sprite_width, int sprite_height) {

	SpriteSheet* sprite_sheet = new SpriteSheet(name, sprite_width, sprite_height);
	sprites[name] = sprite_sheet;

}
