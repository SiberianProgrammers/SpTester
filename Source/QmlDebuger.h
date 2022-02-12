/// @author M. A. Serebrennikov
#pragma once

#include "EventSender.h"
#include "ItemPicker.h"
#include "Screenshoter.h"

#include <QObject>

class QQmlApplicationEngine;

namespace sp {

class ItemPicker;

/***************************************************************************//**
 * @brief Класс QmlDebuger содержит методы для отладки QML.
 ******************************************************************************/
class QmlDebuger : public QObject
{
    Q_OBJECT

    Q_PROPERTY(EventSender * eventSender READ eventSender CONSTANT)

    public:
        QmlDebuger(const QQmlApplicationEngine & engine);

        inline const EventSender * eventSender() const { return &_eventSender; }
        inline EventSender * eventSender() { return &_eventSender; }

        /** Выводит в лог название элемента в координатах (x, y). */
        Q_INVOKABLE void logItemAt(qreal x, qreal y);

        /** Сохраняет изображение окна на рабочий стол (для отладки). */
        Q_INVOKABLE void captureWindow();

        /** Сохраняет прямоугольную область окна. */
        Q_INVOKABLE void captureRectangle(const QRect & rectangle);

    private:
        const QQmlApplicationEngine & _engine;
        ItemPicker _picker;
        EventSender _eventSender;
};

} // namespace sp
