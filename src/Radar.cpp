/*
 * Radar.cpp
 *
 *  Created on: 09/07/2014
 *      Author: wachs
 */

#include "Radar.h"

Radar::Radar() :
		timer(this), radarAngle(0), radarMax(0), a(-0.2, 0.3), b(-0.5, 0.9), c(
				-0.45, 0.7) {

	QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(updateGL()));
	timer.start(20);
	posx = 0;
}

Radar::~Radar() {
	// TODO Auto-generated destructor stub
}

void Radar::initializeGL() {
	glClearColor(0, 0.1, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void Radar::resizeGL(int w, int h) {
	float side = qMin(w, h);
	radarMax = qSqrt(qPow(w, 2) + qPow(h, 2)) / side;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-w / side, w / side, -h / side, h / side, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(90, 0, 0, 1);
	//glRotatef(45, 0, 1, 0);
	//glRotatef(45, 1, 0, 0);

}

void Radar::paintGL() {
	glPushMatrix();
	glClear(GL_COLOR_BUFFER_BIT);

	drawCenteredCircle(0.25);
	drawCenteredCircle(0.5);
	drawCenteredCircle(1);
	drawCenteredCircle(1.5);

	drawRadarLine(radarAngle);
	a.drawOnScope(360 - radarAngle);
	b.drawOnScope(360 - radarAngle);
	c.drawOnScope(360 - radarAngle);

	radarAngle = (radarAngle + 0.5);
	if (radarAngle >= 360)
		radarAngle = radarAngle - 360;

	a.setX(posx = -0.001);

	//printf("%f\n", 360 - radarAngle);
	//fflush(stdout);

	glPopMatrix();

}

void Radar::drawCenteredCircle(GLfloat radius) {
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0.3, 0);
	for (float t = 0; t < 360; t++) {
		float x = qCos(qDegreesToRadians(t)) * radius;
		float y = qSin(qDegreesToRadians(t)) * radius;
		glVertex2f(x, y);
	}
	glEnd();
}

void Radar::drawRadarLine(float angle) {

	glBegin(GL_POLYGON);

	float x = qCos(qDegreesToRadians(angle)) * radarMax;
	float y = qSin(qDegreesToRadians(angle)) * radarMax;
	glColor4f(0.5, 1, 0.5, 0.0);
	glVertex2f(0, 0);

	glColor4f(0.5, 1, 0.5, 0.2);
	glVertex2f(x, y);

	for (int i = 1; i < 350; i++) {
		x = qCos(qDegreesToRadians(angle - i)) * radarMax;
		y = qSin(qDegreesToRadians(angle - i)) * radarMax;
		glColor4f(0.5, 1, 0.5, 0.175 - 0.175 / 270. * i);
		glVertex2f(x, y);
	}

	glBegin(GL_LINE_STRIP);
	x = qCos(qDegreesToRadians(angle)) * radarMax;
	y = qSin(qDegreesToRadians(angle)) * radarMax;
	glColor4f(0, 1, 0, 1);
	glVertex2f(0, 0);
	glVertex2f(x, y);
	glEnd();
}
