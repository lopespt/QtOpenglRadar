/*
 * RadarObject.cpp
 *
 *  Created on: 10/07/2014
 *      Author: wachs
 */

#include "RadarObject.h"

RadarObject::RadarObject() {
	// TODO Auto-generated constructor stub

}

RadarObject::~RadarObject() {
	// TODO Auto-generated destructor stub
}

void RadarObject::drawOnScope(float scopeAngle) {
	glColor3f(0, 1, 0);
	ObjectInformation i = getObjectInformation();

	GLfloat angle = qRadiansToDegrees(
			qAtan2((i.getDy() - i.getY()), (i.getDx() - i.getX())));

	float posAngle = getRadial().getAngle();

	glTranslatef(i.getX(), i.getY(), 0);
	glRotatef(angle - 90, 0, 0, 1);
	float alpha;
	Angle sc(scopeAngle);
	Angle pos(posAngle);
	float diff = (sc - pos).getAngle();
	alpha = diff / 270;
	alpha = alpha > 1 ? 1 : alpha;

	glColor4f(0, 0.9, 0, alpha);
	draw();
	glRotatef(-angle + 90, 0, 0, 1);

	drawLabels();

	glTranslatef(-i.getX(), -i.getY(), 0);
}

ObjectInformation RadarObject::getObjectInformation() {
	return information;
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
		int l = strlen(information.getText().texts[t]);
		for (int i = 0; i < l; i++)
			glutStrokeCharacter(&glutStrokeMonoRoman,
					information.getText().texts[t][i]);
		glPopMatrix();
	}

}

Angle RadarObject::getRadial() {
	return qRadiansToDegrees(qAtan2(information.getX(), information.getY()));
}
