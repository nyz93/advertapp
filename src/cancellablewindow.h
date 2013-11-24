#ifndef CANCELLABLEWINDOW_H_
#define CANCELLABLEWINDOW_H_

#include "window.h"

class CancellableWindow : public virtual Window
{
protected:
	bool cancelled;
	CancellableWindow(const std::string & t) : Window(t), cancelled(false) {}
	CancellableWindow() : Window(), cancelled(false) {}
public:
	bool isCancelled() { return cancelled; }

	virtual ~CancellableWindow() {}
};

#endif // CANCELLABLEWINDOW_H_
