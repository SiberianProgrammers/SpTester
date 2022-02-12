/// @author M. A. Serebrennikov
#pragma once

#include <QScopedPointer>

class QQmlApplicationEngine;
class QGuiApplication;

namespace sp {

class QmlDebuger;
class EventWatcher;

/***************************************************************************//**
 * @brief Класс AppTester инициализирует тестирование.
 ******************************************************************************/
class AppTester
{
    public:
        AppTester(QGuiApplication & app, const QQmlApplicationEngine & engine);
        ~AppTester();

    private:
        QScopedPointer<QmlDebuger> _qmlDebuger;
        QScopedPointer<EventWatcher> _eventWatcher;
};

} // namespace sp
