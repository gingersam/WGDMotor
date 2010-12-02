#include "../include/camera.h"

#include <GL/gl.h>
#include <GL/glu.h>


bool Camera::isVisible (Entity* entity) const {

	return true;

}

Vector2D Camera::screen2world (int x, int y) const {

	Vector2D v;
	
	int width = Window::getWidth();
	int height = Window::getHeight();
	
	// Make it scale when you resize window or go fullscreen
	float realScale = scale / (800.0f / width);
	
	v.x = centre.x + (x - width / 2) / realScale;
	v.y = centre.y - (y - height / 2) / realScale;
	return v;

}

void Camera::update () {

	if (targetScale > 500) { targetScale = 500; }
	if (targetScale < 2.0f) { targetScale = 2.0f; }
	
	if (scale != targetScale) {
		float scaleChange = (targetScale - scale) / 10;
		scale += scaleChange;
		centre = mouse + (centre - mouse) * (scale - scaleChange) / scale;
	}
	
	const float minY = 0.0f;
	const float maxY = 100.0f;
	const float minX = -100.0f;
	const float maxX = 100.0f;
	
	if (centre.y < minY) { centre.y = minY; }
	if (centre.y > maxY) { centre.y = maxY; }
	if (centre.x < minX) { centre.x = minX; }
	if (centre.x > maxX) { centre.x = maxX; }
	
	// Record visible bounds of the camera for draw culling
	const int width = Window::getWidth();
	const int height = Window::getHeight();
	
	minWorld = screen2world(0, height);
	maxWorld = screen2world(width, 0);

}

void Camera::use () {

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	int width = Window::getWidth();
	int height = Window::getHeight();
	
	// Make it scale when you resize window or go fullscreen
	width = (int) (width * 600.0f / height);
	height = 600;
	
	// Set up the projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-width/2, width/2, height/2, -height/2, 1, 400);
	glTranslatef(-centre.x, -centre.y, -2);
	
	// Make lines look better	
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glScissor(0, 0, Window::getWidth(), Window::getHeight());
	glEnable(GL_SCISSOR_TEST);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_TEXTURE_2D);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	glLineWidth (1.5);

}

