/// @author M. A. Serebrennikov
#pragma once

#include <QObject>

namespace sp {

/***************************************************************************//**
 * @brief Класс EventWatcher отлиавливает сигналы мыши и клавиатуры и
 * и передаёт дальше, для записи сценария.
 ******************************************************************************/
class EventWatcher : public QObject
{
    Q_OBJECT

    public:
    protected:
         bool eventFilter( QObject *dest, QEvent *event) override;
};

} // namespace sp
