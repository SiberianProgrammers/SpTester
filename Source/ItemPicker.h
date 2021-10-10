/// @author M. A. Serebrennikov
#pragma once

#include <QList>

class QQmlApplicationEngine;
class QQuickItem;

namespace sp {

/***************************************************************************//**
 * @brief Класс QuickItemPicker определяет какой элемент находится в заданной точке.
 ******************************************************************************/
class ItemPicker
{
    public:
        ItemPicker(const QQmlApplicationEngine & engine);

        /** Возвращает элемент с кординатами x, y */
        QList<QQuickItem *> itemAt(qreal x, qreal y);

    private:

    private:
        const QQmlApplicationEngine & _engine;
};

} // namespace sp
