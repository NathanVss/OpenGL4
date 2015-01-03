#include "Camera.h"


int Camera::curX = 0;
int Camera::curY = 0;

Camera::Camera(void) {
	this->resetPos();
}

void Camera::resetPos() {
	
	this->curX = 0;
	this->curY = 0;
	this->realFocus();
}

int Camera::getCurX() {
	return Camera::curX;
}

int Camera::getCurY() {

	return Camera::curY;
}

void Camera::realFocus() {
	glLoadIdentity();
	glTranslatef((Boot::width/2-this->curX), (Boot::height/2-this->curY), 0);
}


void Camera::focus(int dx, int dy) {

	this->resetPos();
	this->curX = dx;
	this->curY = dy;
	this->realFocus();

}

void Camera::update() {
	/*float x = 0,y = 0;
	float speed = 10.0f;
	if(Keyboard.getKeyUp()) {
		y = speed;
	}
	if(Keyboard.getKeyDown()) {
		y = -speed;
	}
	if(Keyboard.getKeyLeft()) {
		x = speed;
	}
	if(Keyboard.getKeyRight()) {
		x = -speed;
	}
	//glTranslatef(x,y,0);
	//std::cout << "Camera [ " << this->curX << ";" << this->curY << " ]" << std::endl; 
	this->curY -= y;
	this->curX -= x;*/
	
}

void Camera::setFontRenderer(FontRenderer* fFontRenderer) {
	this->fFontRenderer = fFontRenderer;
}

void Camera::render() {
	

	glPushMatrix();

		glTranslatef(Camera::curX, Camera::curY, 0);
		glBegin(GL_LINES);

		glColor3ub(231, 76, 60);
		glVertex2i(0, 0);
		glVertex2i(0, 50);

		glVertex2i(0, 0);
		glVertex2i(0, -50);

		glVertex2i(0, 0);
		glVertex2i(50, 0);

		glVertex2i(0, 0);
		glVertex2i(-50, 0);

		glEnd();

	glPopMatrix();

}