#include "Radar.h"
#include <QApplication>
#include <QSystemTrayIcon>
#include <QIcon>
#include "RadarIconEngine.h"

int main(int argc, char * argv[]) {
	QApplication app(argc, argv);
	RadarIconEngine *eng = new RadarIconEngine();
	QIcon i(eng);
	//QApplication::setWindowIcon(QIcon("/Users/wachs/Pictures/img003.jpg"));

	Radar r;
	r.setVisible(true);
	r.setWindowTitle("teste");

	QSystemTrayIcon tray(QIcon("/Users/wachs/Pictures/img003.jpg"));
	tray.setVisible(true);

	return app.exec();
}
