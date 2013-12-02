#ifndef CANCELLABLEWINDOW_H_
#define CANCELLABLEWINDOW_H_

#include "Screen.h"

class CancellableScreen : public virtual Screen
{
protected:
	bool cancelled;
	CancellableScreen(const std::string & t) : Screen(t), cancelled(false) {}
	CancellableScreen() : Screen(), cancelled(false) {}
public:
	bool isCancelled() { return cancelled; }

	virtual ~CancellableScreen() {}
};

#endif // CANCELLABLEWINDOW_H_
