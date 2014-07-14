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
#include <QObject>
#include <QTimer>
typedef int milisecs;

class RadarObject: public QObject {
	Q_OBJECT
private:
	QTimer timer;
	ObjectInformation lastInformation;
private slots:
	void callUpdatePosition();

protected:
	ObjectInformation currentInformation;
	RadarObject();
	virtual void drawLabels();

protected slots:
	virtual void updatePosition(milisecs timeShift = 100)=0;
public:
	virtual ~RadarObject();
	ObjectInformation getLastObjectInformation();
	void drawOnScope(float scopeAngle);
	virtual void draw()=0;
	Angle getRadial();

};

#endif /* RADAROBJECT_H_ */
