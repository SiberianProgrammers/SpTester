/// @author M. A. Serebrennikov
#include "QmlDebuger.h"

#include <QDebug>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlContext>
#include <QQuickItem>

namespace sp {

QmlDebuger::QmlDebuger(const QQmlApplicationEngine & engine)
    : _engine(engine)
    , _picker(engine)
{
}

//------------------------------------------------------------------------------
void QmlDebuger::logItemAt(qreal x, qreal y)
{
    qDebug();
    auto items = _picker.itemAt(x, y);
    bool hasItems = false;
    for (auto * item : items) {
        auto itemId = qmlContext(item)->nameForObject(item);
        hasItems = true;
        qDebug() << "Item:" << item << itemId;
    }

    if (!hasItems) {
        qDebug() << "No item at" << x << y;
    }
}

} // namespace sp
