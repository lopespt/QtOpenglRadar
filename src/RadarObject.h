/*
 * RadarObject.h
 *
 *  Created on: 10/07/2014
 *      Author: wachs
 */

#ifndef RADAROBJECT_H_
#define RADAROBJECT_H_

#include <QGLWidget>
#include <qmath.h>
#include "ObjectInformation.h"
#include <glut/glut.h>
#include "Angle.h"

class RadarObject {
protected:
	ObjectInformation information;
protected:
	RadarObject();
	virtual void drawLabels();
public:
	virtual ~RadarObject();
	ObjectInformation getObjectInformation();
	void drawOnScope(float scopeAngle);
	virtual void draw()=0;
	Angle getRadial();

};

#endif /* RADAROBJECT_H_ */
