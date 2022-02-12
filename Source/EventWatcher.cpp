/// @author M. A. Serebrennikov
#include "EventWatcher.h"

#include <QDebug>
#include <QEvent>

namespace sp {

bool EventWatcher::eventFilter(QObject * dest, QEvent * event)
{
    qDebug() << "Debug!!!" << dest << "/" << event->type();
    return QObject::eventFilter(dest, event);
}

} // namespace sp
