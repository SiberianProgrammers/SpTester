/// @author M. A. Serebrennikov
#include "EventSender.h"
#include "Platform.h"
#include "QmlDebuger.h"
#include "SignalBlocker.hpp"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

using namespace sp;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QQmlContext *context = engine.rootContext();

    qRegisterMetaType<EventSender*>("EventSender*");
    QmlDebuger qmlDebuger(engine);
    SignalBlocker signalBlocker;

    context->setContextProperty("dp", Platform::dp());
    context->setContextProperty("qmlDebuger", &qmlDebuger);
    context->setContextProperty("signalBlocker", &signalBlocker);

    engine.addImportPath("qrc:///");
    engine.load("qrc:/Main.qml");

    return app.exec();
}
