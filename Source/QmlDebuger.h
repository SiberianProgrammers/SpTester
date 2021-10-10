/// @author M. A. Serebrennikov
#pragma once

#include "ItemPicker.h"

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

    public:
        QmlDebuger(const QQmlApplicationEngine & engine);

        /** Выводит в лог название элемента в координатах (x, y). */
        Q_INVOKABLE void logItemAt(qreal x, qreal y);

    private:
        const QQmlApplicationEngine & _engine;
        ItemPicker _picker;
};

} // namespace sp
