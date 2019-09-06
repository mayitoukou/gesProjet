QT += qml quick sql svg
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp

RESOURCES += qml.qrc icons/icons.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../gesprojet/release/ -lgesprojet
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../gesprojet/debug/ -lgesprojet
else:unix: LIBS += -L$$OUT_PWD/../gesprojet/ -lgesprojet

INCLUDEPATH += $$PWD/../gesprojet
DEPENDPATH += $$PWD/../gesprojet
