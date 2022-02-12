#pragma once

#include <QObject>

namespace sp {

/**
 * @brief Класс позволяет блокировать сигналы в qml
 * на подобии QSignalBlocker.
 *
 * @warning Имейте ввиду, что во время блокирования не будут
 * работать биндинги properties.
 */
class SignalBlocker : public QObject
{
    Q_OBJECT

    public:
        Q_INVOKABLE void block(QObject * target);
        Q_INVOKABLE void unblock(QObject * target);
};

} // namespace sp
