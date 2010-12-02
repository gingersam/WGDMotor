#ifndef __SPRITE_MANAGER_H__
#define __SPRITE_MANAGER_H__

#include "sprite_sheet.h"

#include <map>

class SpriteManager {

	public:
	SpriteManager() {}
	~SpriteManager() {
	// Clear all of the sprites.
		for (std::map<std::string, SpriteSheet*>::iterator i= sprites.begin(); i != sprites.end(); i++) {
			if (i->second) {
				delete i->second;
			}
		}
		sprites.clear();  	
	}

    SpriteSheet* getSpriteSheet(std::string name) { return sprites[name]; }
    void loadSpriteSheet(std::string name, int sprite_width = 0, int sprite_height = 0);

	private:
    std::map<std::string,SpriteSheet*> sprites;

};

#endif
