/*
 * ObjectInformation.h
 *
 *  Created on: 10/07/2014
 *      Author: wachs
 */

#ifndef OBJECTINFORMATION_H_
#define OBJECTINFORMATION_H_

#include "Angle.h"

typedef struct {
	char texts[4][8];
} textInfo;

class ObjectInformation {

private:
	float x, y, z;
	Angle angle;
	textInfo text;

public:
	ObjectInformation();
	virtual ~ObjectInformation();

	Angle getAngle() const {
		return angle;
	}

	void setAngle(const Angle& a) {
		this->angle = a;
	}

	float getX() const {
		return x;
	}

	void setX(float x) {
		this->x = x;
	}

	float getY() const {
		return y;
	}

	void setY(float y) {
		this->y = y;
	}

	float getZ() const {
		return z;
	}

	void setZ(float z) {
		this->z = z;
	}

	const textInfo& getText() const {
		return text;
	}

	void setText(const textInfo& text) {
		this->text = text;
	}

};

#endif /* OBJECTINFORMATION_H_ */
