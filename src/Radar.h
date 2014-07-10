/*
 * Radar.h
 *
 *  Created on: 09/07/2014
 *      Author: wachs
 */

#ifndef RADAR_H_
#define RADAR_H_
#include <QGLWidget>
#include <qmath.h>
#include <QTimer>
#include <QObject>
#include "Airplane.h"

class Radar: public QGLWidget {
	Q_OBJECT
public:
	Radar();
	virtual ~Radar();
	virtual void initializeGL();
	virtual void resizeGL(int w, int h);
	virtual void paintGL();
private:
	void drawCenteredCircle(GLfloat radius);
	void drawRadarLine(float angle);
	QTimer timer;
	float radarAngle;
	float radarMax;
	Airplane a,b,c;
	float posx;
};

#endif /* RADAR_H_ */
