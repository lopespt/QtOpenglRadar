/*
 * Airplane.cpp
 *
 *  Created on: 10/07/2014
 *      Author: wachs
 */

#include "Airplane.h"

Airplane::Airplane(float x, float y) {
	information.setX(x);
	information.setY(y);
	information.setZ(0.5);
	information.setDx(0);
	information.setDy(0);
	information.setDz(0);
}

Airplane::~Airplane() {
	// TODO Auto-generated destructor stub
}

void Airplane::setX(float x) {
	information.setX(x);
}

void Airplane::draw() {
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.01, -0.01);
	glVertex2f(-0.01, 0.01);
	glVertex2f(0.01, 0.01);
	glVertex2f(0.01, -0.01);
	glEnd();

	char txt[][20] = { "TAM3651 18 180", "R18 -" };

	for (int t = 0; t < 2; t++) {
		glPushMatrix();
		glTranslatef(0.01, 0.03 - 0.015 * t, 0);
		glScalef(0.0001, 0.0001, 0);
		int l = strlen(txt[t]);
		for (int i = 0; i < l; i++)
			glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, txt[t][i]);
		glPopMatrix();
	}

}
