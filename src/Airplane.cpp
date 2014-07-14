/*
 * Airplane.cpp
 *
 *  Created on: 10/07/2014
 *      Author: wachs
 */

#include "Airplane.h"

Airplane::Airplane(float x, float y) :
		timer() {

	currentInformation.setX(x);
	currentInformation.setY(y);
	currentInformation.setZ(0.5);
	this->x = x;
	this->y = y;

	speed = 0.001;
	heading = 335;
	currentInformation.setAngle(heading);

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
	glVertex2f(0.05, 0);
	glEnd();

	textInfo txt;
	strcpy(txt.texts[0], "TAM3651 18 180");
	strcpy(txt.texts[1], "R18 -");
	currentInformation.setText(txt);

}

void Airplane::computePosition() {

	float sx = qCos(qDegreesToRadians(heading.getGLAngle())) * speed;
	float sy = qSin(qDegreesToRadians(heading.getGLAngle())) * speed;

	x += sx;
	y += sy;

}

void Airplane::updatePosition(milisecs timeSlice) {
	currentInformation.setX(x);
	currentInformation.setY(y);
}
