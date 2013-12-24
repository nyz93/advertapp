/*
 * The MIT License (MIT)
 * 
 * Copyright (c) 2013 Zoltán Nyikos
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef SELECTIONSCREEN_H
#define SELECTIONSCREEN_H
#include <string>
#include <sstream>
#include <vector>
#include "CancellableAction.h"
#include "Screen.h"
template <class T>
class SelectionScreen: public Screen, public CancellableAction<T> {
    public:
    typedef std::string (*Converter)(T);
    private:
    std::vector<T> options;
    Converter conv;
    public:
    SelectionScreen(const std::vector<T>& options, Converter conv): options(options), conv(conv) {}
    virtual ~SelectionScreen() {}
    virtual void show() {
        bool completed = false;
        do {
            drawTitle();
            CancellableAction<T>::cancelled = false;
            std::stringstream ss;
            for(unsigned i = 0; i < options.size(); i++) {
                std::cout << "(" << i+1 << ") " << conv(options[i]) << std::endl;
            }
            std::cout << std::endl;
            std::cout << "(c)ancel" << std::endl;
            if(options.size() == 1) {
                ss << "[1,c] > ";
            }else{
                ss << "[1-" << options.size() << ",c] > ";
            }
            std::string cmdline = ss.str();
            std::string cmd = readCommand(cmdline);
            if(cmd == "c") {
                CancellableAction<T>::cancelled = true;
                completed = true;
            } else {
                int id = 0;
                std::stringstream conv;
                conv << cmd;
                conv >> id;
                if(id > 0 && id < (int)options.size()+1) {
                    CancellableAction<T>::result = options[id-1];
                    completed = true;
                }
            }
        }while(!completed);
    }
};
#endif
