/// @author M. A. Serebrennikov
#include "QmlDebuger.h"
#include "Screenshoter.h"

#include <QDebug>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlContext>
#include <QQuickItem>
#include <QStandardPaths>
#include <QStringBuilder>

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

void QmlDebuger::captureWindow()
{
    QImage screenshot = Screenshoter::captureWindow();
    screenshot.save(QStandardPaths::writableLocation(QStandardPaths::DesktopLocation)
                    % "/screenshot.png");
}

void QmlDebuger::captureRectangle(const QRect & rectangle)
{
    QImage screenshot = Screenshoter::captureRectangle(rectangle);
    screenshot.save(QStandardPaths::writableLocation(QStandardPaths::DesktopLocation)
                    % "/screenshot.png");
}

} // namespace sp
