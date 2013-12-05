#ifndef CANCELLABLEACTION_H
#define CANCELLABLEACTION_H
#include "Action.h"
template <class T>
class CancellableAction: public Action<T> {
    protected:
    bool cancelled;
    public:
    bool isCancelled() const {
        return cancelled;
    }
};
#endif
