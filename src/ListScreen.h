#ifndef LISTSCREEN_H
#define LISTSCREEN_H
#include <vector>
#include "Screen.h"
template <class T>
class ListScreen: public Screen {
    typedef std::string (*Converter)(T);
    const std::vector<T> list;
    Converter conv;
    public:
    ListScreen(const std::vector<T> list, Converter conv): list(list),conv(conv) {}
    virtual void show() {
        bool completed = false;
        do{
            drawTitle();
            for(auto ad: list) {
                std::cout << conv(ad) << std::endl;
            }
            std::cout << "(b)ack" << std::endl;
            std::string cmd = readCommand("[b] > ");
            if(cmd == "b") {
                completed = true;
            }
        }while(!completed);
    }
};
#endif
