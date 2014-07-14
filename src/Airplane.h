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
#include "Angle.h"
#include <qmath.h>
#include <QTimer>
#include <QObject>

class Airplane: public RadarObject {
Q_OBJECT
public:
	Airplane(float x = 0, float y = 0);
	virtual ~Airplane();
	virtual void draw();
	virtual void updatePosition(milisecs timeSlice);
private:
	const float timeStep = 100;
	float speed;
	float toSpeeding;

	float altitude;
	float toAltitude;

	Angle heading;
	Angle toHeading;

	QTimer timer;
	float x, y, z;

private slots:
	void computePosition();

};

#endif /* AIRPLANE_H_ */
