/*
 * RadarIconEngine.h
 *
 *  Created on: 10/07/2014
 *      Author: wachs
 */

#ifndef RADARICONENGINE_H_
#define RADARICONENGINE_H_

#include <QIconEngine>
#include <QPainter>

class RadarIconEngine: public QIconEngine {
public:
	RadarIconEngine();
	virtual ~RadarIconEngine();
	virtual void paint(QPainter * painter, const QRect & rect, QIcon::Mode mode, QIcon::State state);
	virtual QIconEngine *clone() const;
};

#endif /* RADARICONENGINE_H_ */
