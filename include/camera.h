#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "vector.h"
#include "window.h"
#include "entity.h"

class Camera {

	public:
	Camera(const Vector2D& centre, float scale)
		: centre(centre), scale(scale), targetScale(scale) {}
	
	Camera(float x, float y, float scale)
		: centre(Vector2D(x, y)), scale(scale), targetScale(scale) {}
	
	Vector2D screen2world(int x, int y) const;
	
	Vector2D getCentre() { return centre; }
	void translate(const Vector2D& t) { centre += t; }
	void focusOn(const Vector2D& t) { centre = t; }
	
	void update();	// Update the camera.
	void use();		// Apply the correct matrices in OpenGL.
	
	bool isVisible(Entity* entity) const;

	private:
	Vector2D centre;
	Vector2D mouse;
	float scale;
	float targetScale;
	
	Vector2D minWorld;
	Vector2D maxWorld;
	
};

#endif

