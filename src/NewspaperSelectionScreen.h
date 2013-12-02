#ifndef NEWSPAPERSELECTIONWINDOW_H
#define NEWSPAPERSELECTIONWINDOW_H
#include <vector>
#include <string>
#include <sstream>
#include "CancellableScreen.h"
#include "Newspaper.h"
using namespace std;
class NewspaperSelectionScreen: public CancellableScreen{
    vector<Newspaper*> newspapers;
    vector<Newspaper*> selection;
    int find(Newspaper* np);
    public:
    NewspaperSelectionScreen(const vector<Newspaper*>& newspapers,
            const vector<Newspaper*>& selection);
    virtual void show();
    const vector<Newspaper*>& getSelection() const;
    virtual ~NewspaperSelectionScreen() {}
};
#endif
