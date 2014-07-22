/*
 * Radar.cpp
 *
 *  Created on: 09/07/2014
 *      Author: wachs
 */

#include "Radar.h"

Radar::Radar() :
		timer(this), radarAngle(135), radarMax(0), a(0.25, 0.25), b(-0.5, 0.5), c(
				-0.45, -0.7) {

	QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(updateGL()));
	timer.start(10);
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
	//glRotatef(90, 0, 0, 1);
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
	a.drawOnScope(radarAngle);
	b.drawOnScope(radarAngle);
	c.drawOnScope(radarAngle);

	radarAngle = (radarAngle - 2);
	if (radarAngle <= 0)
		radarAngle = radarAngle + 360;

	//a.setX(posx = -0.001);

	//printf("%f\n", 360 - radarAngle);
	//fflush(stdout);
	drawRadials();

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

	angle = 360 - angle + 90;
	glBegin(GL_POLYGON);

	float x = qCos(qDegreesToRadians(angle)) * radarMax;
	float y = qSin(qDegreesToRadians(angle)) * radarMax;
	glColor4f(0.5, 1, 0.5, 0);
	glVertex2f(0, 0);

	glColor4f(0.5, 1, 0.5, 0.2);
	glVertex2f(x, y);

	for (int i = 350; i > 2; i--) {
		x = qCos(qDegreesToRadians(angle + i)) * radarMax;
		y = qSin(qDegreesToRadians(angle + i)) * radarMax;
		glColor4f(0.5, 1, 0.5, i / 350. * 0.2);
		glVertex2f(x, y);
	}
	glEnd();

	glBegin(GL_LINES);
	x = qCos(qDegreesToRadians(angle)) * radarMax;
	y = qSin(qDegreesToRadians(angle)) * radarMax;
	glColor4f(0, 1, 0, 1);
	glVertex2f(0, 0);
	glVertex2f(x, y);
	glEnd();
}

void Radar::drawRadials() {

	char txt[5];
	glPushMatrix();
	glRotatef(90, 0, 0, 1);
	glColor4f(0, 1, 0, 0.1);
	for (int i = 0; i < 8; i++) {
		sprintf(txt, "%i", 360 - 360 / 8 * i);
		glBegin(GL_LINES);
		glVertex2f(0, 0);
		glVertex2f(1.5, 0);
		glEnd();

		glPushMatrix();

		if (i > 0 && i < 6) {
			glTranslatef(0.75, 0.03, 0);
			glRotatef(180, 0, 0, 1);
		} else {
			glTranslatef(0.75, -0.03, 0);
		}
		glScaled(0.0005, 0.0005, 0);

		for (int c = 0; c < strlen(txt); c++)
			glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, txt[c]);
		glPopMatrix();

		glRotatef(360 / 8, 0, 0, 1);
	}

	glPopMatrix();

}
