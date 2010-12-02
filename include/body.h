#ifndef __BODY_H__
#define __BODY_H__

#include "vector.h"

class Body {
	public:
	Body() {}
	virtual bool collidesWith(Body *b) const = 0;

	protected: 
	int m_type;
};

class RectBody;

class CircularBody : public Body {
	public:
	CircularBody( Vector2D position, float radius): m_position(position), m_radius(radius) {
		m_type =0;
	}
	bool collidesWith(Body *b) const {}
	bool collidesWithRect(RectBody *b) const;
	bool collidesWithCircle(CircularBody *b) const;
	Vector2D getPosition() {return m_position;}
	float getRadius() {return m_radius;}
	private:
	Vector2D m_position;
	float m_radius;
};

class RectBody : public Body {
	public:
	RectBody(Vector2D position, float width, float height): 
		m_position(position), m_width(width) ,m_height(height) {
		m_type = 1;	
	}
	bool collidesWithRect(RectBody *b) const;
	bool collidesWithCircle(CircularBody *b) const;	
	private:
	Vector2D m_position;
	float m_width;
	float m_height;
};

#endif
