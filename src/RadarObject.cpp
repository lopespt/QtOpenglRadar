/*
 * RadarObject.cpp
 *
 *  Created on: 10/07/2014
 *      Author: wachs
 */

#include "RadarObject.h"

RadarObject::RadarObject() :
		timer(this) {

	timer.setInterval(100);
	QObject::connect(&timer, SIGNAL(timeout()), this,
			SLOT(callUpdatePosition()));
	timer.start();
}

RadarObject::~RadarObject() {

}

void RadarObject::drawOnScope(float scopeAngle) {
	glColor3f(0, 1, 0);
	ObjectInformation i = lastInformation;

	float posAngle = getRadial().getAngle();

	glTranslatef(i.getX(), i.getY(), 0);
	glRotatef(i.getAngle().getGLAngle(), 0, 0, 1);
	float alpha;
	Angle sc(scopeAngle);
	Angle pos(posAngle);
	float diff = (sc - pos).getAngle();
	alpha = diff / 270;
	alpha = alpha > 1 ? 1 : alpha;
	if (diff <= 2)
		lastInformation = currentInformation;

	glColor4f(0, 0.9, 0, alpha);
	draw();
	glRotatef(-i.getAngle().getGLAngle(), 0, 0, 1);

	drawLabels();

	glTranslatef(-i.getX(), -i.getY(), 0);
}

ObjectInformation RadarObject::getLastObjectInformation() {
	return lastInformation;
}

void RadarObject::drawLabels() {

	for (int t = 0; t < 2; t++) {
		glPushMatrix();
		switch (getRadial().quadrant()) {
		case Angle::Angle_Quad_A:
			glTranslatef(0.03, 0.03 - 0.015 * t, 0);
			break;
		case Angle::Angle_Quad_B:
			glTranslatef(0.03, -0.03 - 0.015 * t, 0);
			break;
		case Angle::Angle_Quad_C:
			glTranslatef(-0.2, -0.03 - 0.015 * t, 0);
			break;
		case Angle::Angle_Quad_D:
			glTranslatef(-0.2, 0.03 - 0.015 * t, 0);
			break;
		}

		glScalef(0.0001, 0.0001, 0);
		int l = strlen(currentInformation.getText().texts[t]);
		for (int i = 0; i < l; i++)
			glutStrokeCharacter(&glutStrokeMonoRoman,
					currentInformation.getText().texts[t][i]);
		glPopMatrix();
	}

}

Angle RadarObject::getRadial() {
	return qRadiansToDegrees(
			qAtan2(currentInformation.getX(), currentInformation.getY()));
}

void RadarObject::callUpdatePosition() {
	updatePosition(timer.interval());
}
