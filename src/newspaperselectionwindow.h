#ifndef NEWSPAPERSELECTIONWINDOW_H
#define NEWSPAPERSELECTIONWINDOW_H
#include <vector>
#include <string>
#include <sstream>
#include "cancellablewindow.h"
#include "newspaper.h"
using namespace std;
class NewspaperSelectionWindow: public CancellableWindow{
    vector<Newspaper*> newspapers;
    vector<Newspaper*> selection;
    int find(Newspaper* np);
    public:
    NewspaperSelectionWindow(const vector<Newspaper*>& newspapers,
            const vector<Newspaper*>& selection):CancellableWindow("Select newspapers"), newspapers(newspapers), selection(selection){
    }
    virtual void handle();
    const vector<Newspaper*>& getSelection() const;
    virtual ~NewspaperSelectionWindow() {}
};
#endif
