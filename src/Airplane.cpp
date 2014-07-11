/*
 * Airplane.cpp
 *
 *  Created on: 10/07/2014
 *      Author: wachs
 */

#include "Airplane.h"

Airplane::Airplane(float x, float y) :
		timer() {

	information.setX(x);
	information.setY(y);
	information.setZ(0.5);
	information.setDx(0);
	information.setDy(0);
	information.setDz(0);
	speed = 0.001;
	heading = 270;

	QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(computePosition()));
	timer.start(timeStep);
}

Airplane::~Airplane() {

}

void Airplane::draw() {
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.01, -0.01);
	glVertex2f(-0.01, 0.01);
	glVertex2f(0.01, 0.01);
	glVertex2f(0.01, -0.01);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(0, 0);
	glVertex2f(0, 0.05);
	glEnd();

	textInfo txt;
	strcpy(txt.texts[0], "TAM3651 18 180");
	strcpy(txt.texts[1], "R18 -");
	information.setText(txt);

}

void Airplane::computePosition() {

	float sx = qCos(heading.getGLAngle()) * speed;
	float sy = qSin(heading.getGLAngle()) * speed;

	information.setX(information.getX() + sx);
	information.setY(information.getY() + sy);

}
