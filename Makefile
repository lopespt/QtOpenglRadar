
PRO   = QtOpenglRadar.pro
QMAKE = /Users/wachs/Qt5.3.0/5.3/clang_64/bin/qmake

all:	QtMakefile
	$(MAKE) -f QtMakefile

clean:
	rm -fr QtMakefile QtMakefile.debug QtMakefile.release debug release *.o

QtMakeProject:
	$(QMAKE) -project $(PRO) "QT += core gui widgets opengl" "CONFIG += console" "ICON = QtOpenGlRadar.icns" "LIBS+= -framework glut" 

QtMakefile: QtMakeProject
	$(QMAKE) -o QtMakefile $(PRO) CONFIG+=debug_and_release 

debug:	QtMakefile
	$(MAKE) -f QtMakefile debug

release:	QtMakefile
	$(MAKE) -f QtMakefile release

.PHONY: all clean debug clean-debug release clean-release
