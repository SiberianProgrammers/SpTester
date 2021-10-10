/// @author M. A. Serebrennikov
#include "Platform.h"
#include "EventSender.h"
#include "QmlDebuger.h"

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

    context->setContextProperty("dp", Platform::dp());
    context->setContextProperty("qmlDebuger", &qmlDebuger);

    engine.addImportPath("qrc:///");
    engine.load("qrc:/Main.qml");

    return app.exec();
}
