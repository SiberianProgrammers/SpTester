/// @author M. A. Serebrennikov
#include "AppTester.h"
#include "EventSender.h"
#include "EventWatcher.h"
#include "Platform.h"
#include "QmlDebuger.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

namespace sp {

AppTester::AppTester(QGuiApplication & app, const QQmlApplicationEngine & engine)
    : _qmlDebuger(new QmlDebuger(engine))
    , _eventWatcher(new EventWatcher)
{
    QQmlContext *context = engine.rootContext();

    qRegisterMetaType<EventSender*>("EventSender*");

    app.installEventFilter(_eventWatcher.get());

    context->setContextProperty("dp", Platform::dp());
    context->setContextProperty("qmlDebuger", _qmlDebuger.get());
}

//------------------------------------------------------------------------------
AppTester::~AppTester()
{

}

} // namespace sp
