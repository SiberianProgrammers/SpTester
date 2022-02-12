#include "SignalBlocker.hpp"

namespace sp {

void SignalBlocker::block(QObject * target)
{
    target->blockSignals(true);
}

void SignalBlocker::unblock(QObject * target)
{
    target->blockSignals(false);
}

} // namespace sp
