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
			qAtan((i.getDy() - i.getY()) / (i.getDx() - i.getX())));

	float posAngle = 180 - qRadiansToDegrees(qAtan(i.getY() / i.getX()));

	glTranslatef(i.getX(), i.getY(), 0);

	glRotatef(angle, 0, 0, 1);

	float alpha = 0;
	//printf("%f : %f\n", scopeAngle, posAngle);
	//fflush(stdout);

	if (scopeAngle - posAngle > -270 && scopeAngle < posAngle) {
		alpha = 1 - (posAngle - scopeAngle) / 270.0;
	}

	glColor4f(0, 0.9, 0, alpha);
	draw();
	glRotatef(-angle, 0, 0, 1);
	glTranslatef(-i.getX(), -i.getY(), 0);

}

ObjectInformation RadarObject::getObjectInformation() {
	return information;
}
