/*
 * RadarIconEngine.cpp
 *
 *  Created on: 10/07/2014
 *      Author: wachs
 */

#include "RadarIconEngine.h"

RadarIconEngine::RadarIconEngine() {
	// TODO Auto-generated constructor stub

}

RadarIconEngine::~RadarIconEngine() {
	// TODO Auto-generated destructor stub
}

void RadarIconEngine::paint(QPainter* painter, const QRect& rect,
		QIcon::Mode mode, QIcon::State state) {
	painter->eraseRect(rect);
	painter->drawLine(0, 0, 5, 5);
}

QIconEngine* RadarIconEngine::clone() const {
	return new RadarIconEngine;
}
