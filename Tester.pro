QT += quick

CONFIG += c++17

SOURCES += \
        Source/EventWatcher.cpp \
        Source/ItemPicker.cpp \
        Source/Main.cpp \
        Source/Platform.cpp \
        Source/QmlDebuger.cpp

INCLUDEPATH += Source/

RESOURCES += $$PWD/Qml/Qml.qrc

QML_IMPORT_PATH = $$PWD/Qml

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Source/EventWatcher.h \
    Source/ItemPicker.h \
    Source/Platform.h \
    Source/QmlDebuger.h
