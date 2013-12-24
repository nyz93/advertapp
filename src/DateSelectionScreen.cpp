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

#include "DateSelectionScreen.h"
DateSelectionScreen::DateSelectionScreen(const Date& date) {
    result = date;
}

void DateSelectionScreen::show() {
	int day = result.getDay();
	int month = result.getMonth();
	int year = result.getYear();
	bool completed = false;
	do {
		cancelled = false;
		drawTitle();
		cout << "(y)ear: " << year << endl;
		cout << "(m)onth: " << month << endl;
		cout << "(d)ay: " << day << endl;
		cout << "(f)inish selection" << endl;
		cout << "(c)ancel selection" << endl;
		string cmd = readCommand("[y,m,d,f,c] > ");
		if(cmd == "y") {
			string y = readCommand("year > ");
			stringstream conv(y);
			conv >> year;
		}
		else if(cmd == "m") {
			string m = readCommand("month > ");
			stringstream conv(m);
			conv >> month;
		}
		else if(cmd == "d") {
			string d = readCommand("day > ");
			stringstream conv(d);
			conv >> day;
		}
		else if(cmd == "f") {
			Date test = Date(year,month,day);
			if(!test.isValid()) {
				MessageScreen msg("Not valid date!");
				msg.show();
			}else{
				result = test;
				completed = true;
			}
		}else if(cmd == "c") {
			completed = true;
			cancelled = true;
		}
	}while(!completed);
}
