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

class RadarObject {
protected:
	ObjectInformation information;
protected:
	RadarObject();
public:
	virtual ~RadarObject();
	ObjectInformation getObjectInformation();
	void drawOnScope(float scopeAngle);
	virtual void draw()=0;

};

#endif /* RADAROBJECT_H_ */
