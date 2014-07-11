/*
 * Angle.h
 *
 *  Created on: 11/07/2014
 *      Author: wachs
 */

#ifndef ANGLE_H_
#define ANGLE_H_

#include <stdio.h>

class Angle {
public:
	typedef enum {
		Angle_Quad_A, Angle_Quad_B, Angle_Quad_C, Angle_Quad_D
	} Quadrant;

	Angle();
	Angle(float f);
	Angle(const Angle &f);
	virtual ~Angle();
	Angle operator+(Angle a);
	Angle operator-(Angle a);
	bool operator<(Angle a);
	bool operator>(Angle a);
	bool operator==(Angle a);
	Angle::Quadrant quadrant();
	void print();
	float getAngle();
	float getGLAngle();

private:
	float angle;
	Angle sumAngle(float a);

};

#endif /* ANGLE_H_ */
