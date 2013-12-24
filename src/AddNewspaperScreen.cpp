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

#include "AddNewspaperScreen.h"

AddNewspaperScreen::AddNewspaperScreen() {}

AddNewspaperScreen::~AddNewspaperScreen() {}

void AddNewspaperScreen::show() {
    bool completed = false;
    string name;
    int img = 0;
    int text = 0;
    int textimg = 0;
    do {
        cancelled = false;
        drawTitle();
        cout << "(n)ame: " << name << endl;
        cout << "(t)ext price: " << text << endl;
        cout << "(i)mage price: " << img << endl;
        cout << "(t)ext-(i)mage price: " << textimg << endl;
        cout << "(c)ancel" << endl;
        stringstream cmdline;
        cmdline << "[n,t,i,ti,c";
        if(name != "" && img > 0 && text > 0 && textimg > 0) {
            cout << "(f)inish" << endl;
            cmdline << ",f] > ";
        }else{
            cmdline << "] > ";
        }
        string cmd = readCommand(cmdline.str());
        if(cmd == "n") {
            name = readCommand("name > ");
        }else if(cmd == "t") {
            stringstream conv(readCommand("text price > "));
            conv >> text;
        }else if(cmd == "i") {
            stringstream conv(readCommand("image price > "));
            conv >> img;
        }else if(cmd == "ti") {
            stringstream conv(readCommand("text-image price > "));
            conv >> textimg;
        }else if(cmd == "f" && name != "" && img > 0 && text > 0 && textimg > 0) {
            result = new Newspaper(name);
            result->setPriceFor(AdvertType::TextImage,textimg);
            result->setPriceFor(AdvertType::Text,text);
            result->setPriceFor(AdvertType::Image,img);
            completed = true;
        }else if(cmd == "c") {
            cancelled = true;
            completed = true;
        }
    }while(!completed);
}
