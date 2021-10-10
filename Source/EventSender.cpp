/// @author M. A. Serebrennikov
#include "EventSender.h"

#include <QCoreApplication>
#include <QMouseEvent>
#include <QQuickItem>
#include <QTimer>

namespace sp {

void EventSender::sendClick(QQuickItem * item)
{
    QPointF localPos(item->width()/2, item->height()/2);
    auto * pressEvent = new QMouseEvent(QEvent::MouseButtonPress, localPos, Qt::LeftButton, Qt::LeftButton, Qt::NoModifier);
    auto * releaseEvent = new QMouseEvent(QEvent::MouseButtonRelease, localPos, Qt::LeftButton, Qt::LeftButton, Qt::NoModifier);

    qApp->postEvent(item, pressEvent);
    QTimer::singleShot(_clickInterval, item, [item, releaseEvent]{
        qApp->postEvent(item, releaseEvent);
    });
}

} // namespace sp
