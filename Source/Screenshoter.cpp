#include "Screenshoter.h"

#include <QDebug>
#include <QGuiApplication>
#include <QQuickWindow>

Screenshoter::Screenshoter()
{

}

QImage Screenshoter::captureWindow()
{
    if (qApp->allWindows().empty()) {
        qCritical() << "captureWindow: There are no windows";
        Q_ASSERT(false);
        return {};
    }

    auto mainWindow = dynamic_cast<QQuickWindow *>(qApp->allWindows().first());
    if (!mainWindow) {
        qCritical() << "captureWindow: It support only QQuickWindow";
        Q_ASSERT(false);
        return {};
    }

    return mainWindow->grabWindow();
}

QImage Screenshoter::captureRectangle(const QRect & rectangle)
{
    QImage windowScreenshot = captureWindow();
    if (windowScreenshot.isNull()) {
        return {};
    }

    return windowScreenshot.copy(rectangle);
}
