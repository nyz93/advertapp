#ifndef NEWSPAPERSELECTIONWINDOW_H
#define NEWSPAPERSELECTIONWINDOW_H
#include <vector>
#include <string>
#include <sstream>
#include "CancellableAction.h"
#include "Screen.h"
#include "Newspaper.h"
using namespace std;
class NewspaperSelectionScreen: public CancellableAction<vector<Newspaper*> >, public Screen {
    vector<Newspaper*> newspapers;
    int find(Newspaper* np);
    public:
    NewspaperSelectionScreen(const vector<Newspaper*>& newspapers,
            const vector<Newspaper*>& selection);
    virtual void show();
    virtual ~NewspaperSelectionScreen() {}
};
#endif
