/*
 * Angle.cpp
 *
 *  Created on: 11/07/2014
 *      Author: wachs
 */

#include "Angle.h"

Angle::Angle() {
	angle = 0;
}

Angle::Angle(const Angle& f) {
	angle = f.angle;
}

Angle::Angle(float f) {
	while (f > 360) {
		f -= 360;
	}
	while (f <= 0) {
		f += 360;
	}
	angle = f;
}

Angle::~Angle() {

}

Angle Angle::operator +(Angle a) {
	return sumAngle(a.angle);
}

Angle Angle::operator -(Angle a) {
	return sumAngle(-a.angle);
}

bool Angle::operator <(Angle a) {
	if (quadrant() == a.quadrant()) {
		return angle > a.angle;
	} else if (quadrant() == Angle_Quad_A) {
		return (a.quadrant() == Angle_Quad_B || a.quadrant() == Angle_Quad_C) ?
				true : false;
	} else if (quadrant() == Angle_Quad_B) {
		return (a.quadrant() == Angle_Quad_C || a.quadrant() == Angle_Quad_D) ?
				true : false;
	} else if (quadrant() == Angle_Quad_C) {
		return (a.quadrant() == Angle_Quad_D || a.quadrant() == Angle_Quad_A) ?
				true : false;
	} else {
		return (a.quadrant() == Angle_Quad_A || a.quadrant() == Angle_Quad_B) ?
				true : false;
	}
}

bool Angle::operator >(Angle a) {
	if (a.angle == angle)
		return false;
	return !operator <(a);
}

bool Angle::operator ==(Angle a) {
	return a.angle == angle;
}

Angle::Quadrant Angle::quadrant() {
	if (angle >= 0 && angle < 90 || angle == 360) {
		return Angle_Quad_A;
	} else if (angle >= 90 && angle < 180) {
		return Angle_Quad_B;
	} else if (angle >= 180 && angle < 270) {
		return Angle_Quad_C;
	} else {
		return Angle_Quad_D;
	}
}

void Angle::print() {
	printf("%f\n", angle);
	fflush(stdout);
}

float Angle::getAngle() {
	return angle;
}

float Angle::getGLAngle() {
	return Angle(360 - angle + 90).angle;
}

Angle Angle::sumAngle(float a) {
	return Angle(a + angle);
}
