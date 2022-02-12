/// @author M. A. Serebrennikov
#include "AppTester.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>

using namespace sp;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    AppTester appTester(app, engine);

    engine.addImportPath("qrc:///");
    engine.load("qrc:/Main.qml");

    return app.exec();
}
