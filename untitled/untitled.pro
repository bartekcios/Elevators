TEMPLATE = app

QT += qml quick widgets
QT += declarative

SOURCES += main.cpp \
    celevator.cpp \
    cpassenger.cpp \
    cdriver.cpp \
    cguihandler.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    celevator.h \
    precompiled.h \
    cpassenger.h \
    cdriver.h \
    ienums.h \
    cguihandler.h

DISTFILES +=
