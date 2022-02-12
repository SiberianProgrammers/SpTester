/// @author M. A. Serebrennikov
#pragma once

#include <QObject>

class QQuickItem;

namespace sp {

/***************************************************************************//**
 * @brief Класс EventSender эмулирует сообытие мыши и посылает его в QQuickItem.
 ******************************************************************************/
class EventSender : public QObject
{
    Q_OBJECT

    public:
        /** Посылает событие нажатия кнопки мыши в середине элемента. */
        Q_INVOKABLE static void sendClick(QQuickItem * item);

    private:
        static const int _clickInterval = 100;
};

} // namespace sp
