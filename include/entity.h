#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "vector.h"
#include "sprite_sheet.h"

class Entity {

	public:
	Entity (float x, float y) { m_position.x = x; m_position.y = y; }
	~Entity () {}

	int getX() { return m_position.x; }
	void setX(float value) { m_position.x = value; }
	
	int getY() { return m_position.y; }
	void setY(float value) { m_position.y = value; }
	
	Vector2D getPosition() { return m_position; }

	void draw();
	void update();
	bool isStatic() {return m_static;}	

	protected:
	Vector2D m_position;
	SpriteSheet* m_sprite;
	bool m_static;
};

#endif
