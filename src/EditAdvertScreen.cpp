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

#include "EditAdvertScreen.h"

EditAdvertScreen::EditAdvertScreen(const vector<Newspaper*>& newspapers, const Advert* a) : Screen("Edit advertisment"),newspapers(newspapers),old(a) {}

void EditAdvertScreen::show() {
	drawTitle();
	bool complete = false;
    AdvertType type = old->getType();
    const User* currentUser = old->getCreator();
	string name = old->getName();
	string image = old->getImage();
	string text = old->getText();
	vector<Newspaper*> selection = old->getNewspapers();
	Date validUntil = old->getExpirationDate();
	do {
        Advert tmpad;
		stringstream cmdline;
		drawTitle();
		cout << "(n)ame: " << name << endl;
		cmdline << ",n";
		switch(type) {
			case AdvertType::Image: {
				cout << "(i)mage: " << image << endl;
				cmdline << ",i";
			}break;
			case AdvertType::Text: {
				cout << "(t)ext: " << text << endl;
				cmdline << ",t";
			}break;
			case AdvertType::TextImage: {
				cout << "(t)ext: " << text << endl;
				cout << "(i)mage: " << image << endl;
				cmdline << ",t,i";
			}break;
		}
        cout << "(ty)pe: ";
		cmdline << ",ty";
        switch(type) {
            case AdvertType::Text:
                cout << "text";
                break;
            case AdvertType::Image:
                cout << "image";
                break;
            case AdvertType::TextImage:
                cout << "text-image";
                break;
        }
        cout << endl;
		cout << "(s)et expiration (d)ate" << endl;
		cmdline << ",sd";
		cout << "(s)elect (n)newspapers" << endl;
        cmdline << ",sn";
        switch(type) {
            case AdvertType::Image: {
                tmpad = Advert::imageAdvert(name,image,currentUser,validUntil,selection);
            }break;
            case AdvertType::Text: {
                tmpad = Advert::textAdvert(name,text,currentUser,validUntil,selection);
            }break;
            case AdvertType::TextImage: {
                tmpad = Advert::textImageAdvert(name,text,image,currentUser,validUntil,selection);
            }break;
        }
        int price = tmpad.getPrice();
        cout << "current price: $ " << price << endl;
        if(selection.size() > 0) {
            cout << "(f)inish" << endl;
            cmdline << ",f";
        }
        cout << "(c)ancel" << endl;
		cmdline << ",c] > ";
		string prompt = cmdline.str();
		prompt[0]='[';
		string cmd = readCommand(prompt);
		if(cmd == "n") {
			name = readCommand("name > ");
		}else if(cmd == "sn") {
			NewspaperSelectionScreen sw(newspapers,selection);
			sw.show();
			if(!sw.isCancelled()) {
				selection = sw.getResult();
			}
		}else if(cmd == "sd") {
			DateSelectionScreen dw(validUntil);
			dw.show();
			if(!dw.isCancelled()) {
				validUntil = dw.getResult();
			}
		}else if(cmd == "i" && (type == AdvertType::Image || type == AdvertType::TextImage)) {
			image = readCommand("image > ");
		}else if(cmd == "t" && (type == AdvertType::Text || type == AdvertType::TextImage)) {
			text = readCommand("text > ");
		}else if(cmd == "c") {
			cancelled = true;
			complete = true;
		}else if(cmd == "f" && selection.size() > 0) {
			complete = true;
			result = new Advert(tmpad);
		}else if(cmd == "ty") {
            AdvertTypeSelectionScreen ts;
            ts.show();
            type = ts.getType();
        }
	}while(!complete);
}
