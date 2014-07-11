/*
 * ObjectInformation.h
 *
 *  Created on: 10/07/2014
 *      Author: wachs
 */

#ifndef OBJECTINFORMATION_H_
#define OBJECTINFORMATION_H_

typedef struct {
	char texts[4][8];
} textInfo;

class ObjectInformation {

private:
	float x, y, z;
	float dx, dy, dz;
	textInfo text;

public:
	ObjectInformation();
	virtual ~ObjectInformation();

	float getDx() const {
		return dx;
	}

	void setDx(float dx) {
		this->dx = dx;
	}

	float getDy() const {
		return dy;
	}

	void setDy(float dy) {
		this->dy = dy;
	}

	float getDz() const {
		return dz;
	}

	void setDz(float dz) {
		this->dz = dz;
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
