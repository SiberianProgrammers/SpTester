/// @author M. A. Serebrennikov
#include "ItemPicker.h"

#include <QQmlApplicationEngine>
#include <QQuickItem>
#include <QQuickWindow>
#include <QQmlContext>

namespace sp {

ItemPicker::ItemPicker(const QQmlApplicationEngine & engine)
    : _engine(engine)
{
}

//------------------------------------------------------------------------------
QList<QQuickItem *> ItemPicker::itemAt(qreal x, qreal y)
{
    auto objects = _engine.rootObjects();
    for (const auto * object : objects) {
        const QQuickItem * rootItem = nullptr;

        if (const auto * window = dynamic_cast<const QQuickWindow *>(object)) {
            rootItem = window->contentItem();
        } else {
            rootItem = dynamic_cast<const QQuickItem *>(object);
        }

        if (rootItem) {
            auto childItems = rootItem->childItems();
            QList<QQuickItem *> result;

            while (!childItems.empty()) {
                auto * child = childItems.takeLast();
                if (child->mapRectToScene(child->boundingRect()).contains(x, y)) {
                    result.append(child);
                }

                if (child->mapRectToScene(child->childrenRect()).contains(x, y)) {
                    childItems.append(child->childItems());
                }
            }

            return result;
        }
    }

    return {};
}

} // namespace sp
