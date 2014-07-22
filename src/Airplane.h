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

	float getAltitude() const {
		return altitude;
	}

	void setAltitude(float altitude) {
		this->altitude = altitude;
	}

	const Angle& getHeading() const {
		return heading;
	}

	void setHeading(const Angle& heading) {
		this->heading = heading;
	}

	float getSpeed() const {
		return speed;
	}

	void setSpeed(float speed) {
		this->speed = speed;
	}

	float getToAltitude() const {
		return toAltitude;
	}

	void setToAltitude(float toAltitude) {
		this->toAltitude = toAltitude;
	}

	const Angle& getToHeading() const {
		return toHeading;
	}

	void setToHeading(const Angle& toHeading) {
		this->toHeading = toHeading;
	}

	float getToSpeeding() const {
		return toSpeeding;
	}

	void setToSpeeding(float toSpeeding) {
		this->toSpeeding = toSpeeding;
	}

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
