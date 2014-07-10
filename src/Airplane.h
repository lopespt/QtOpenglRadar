/*
 * Airplane.h
 *
 *  Created on: 10/07/2014
 *      Author: wachs
 */

#ifndef AIRPLANE_H_
#define AIRPLANE_H_

#include "RadarObject.h"
#include <QGLWidget>
#include <glut/glut.h>

class Airplane: public RadarObject {
public:
	Airplane(float x = 0, float y = 0);
	virtual ~Airplane();
	void setX(float x);
	virtual void draw();

};

#endif /* AIRPLANE_H_ */
