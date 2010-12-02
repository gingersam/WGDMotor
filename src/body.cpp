#include "../include/body.h"


bool RectBody::collidesWithRect(RectBody *b) const {}
bool RectBody::collidesWithCircle(CircularBody *b) const {}

bool CircularBody::collidesWithRect(RectBody *b) const {


}

bool CircularBody::collidesWithCircle(CircularBody *b) const {
	if ( m_position.distanceSquared(b->getPosition())  < (m_radius + b->getRadius()) * (m_radius + b->getRadius()) ) 
		return true;
	else 
		return false;	
}
