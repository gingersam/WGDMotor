#ifndef _MOVINGENTITY_H_
#define _MOVINGENTITY_H_

#include "entity.h"
#include "vector.h"


class MovingEntity : public Entity
{
	public:

	MovingEntity(float x, float y) : Entity(x,y) {};
	
	Vector2D getVelocity() { return m_velocity; }
	void setVelocity(Vector2D velocity) { m_velocity = velocity; }

	float getXVelocity() { return m_velocity.x; }
	void setXVelocity(float value){ m_velocity.x = value; }
	
	float getYVelocity() { return m_velocity.y; }
	void setYVelocity(float value) { m_velocity.y = value; }
	
	protected:
	Vector2D m_velocity;

};

#endif
