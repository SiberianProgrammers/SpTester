#pragma once

#include <QObject>
#include <QImage>
#include <functional>

class Screenshoter
{
    public:
        Screenshoter();

        /**
         *  Делает снимок главного окна. Результат обрабатывается в callback.
         *  @warning Текущая реализация поддерживает только QQuickWindow
         */
        // TODO Добавить поддержку многооконости
        static QImage captureWindow();
        // Debug!!!
        // QImage captureWindow(const std::function<void(const QImage &)> & callback);

        /** Делает снимок прямоугольной области главного окна. */
        static QImage captureRectangle(const QRect & rectangle);
};

