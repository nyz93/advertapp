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

#include "LoginScreen.h"


LoginScreen::LoginScreen():Screen("Login") {}
const string& LoginScreen::getUsername() const {
	return name;
}
const string& LoginScreen::getPassword() const {
	return pass;
}
bool LoginScreen::isGuest() const {
	return guest;
}
void LoginScreen::show() {
	bool complete = false;
	do {
		drawTitle();
		stringstream cmdline;
		cout << "(u)ser: " << name << endl;
		cout << "(p)assword: " << string(pass.length(),'*') << endl;
		//cout << endl << "Write 'u' to edit the username, 'p' to edit the password." << endl;
		cmdline << "[u,p,";
		if(pass != "" && name != "") {
			cout << "(l)ogin" << endl;
			cmdline << "l] > ";
		}else{
			cout << "login as (g)uest" << endl;
			cmdline << "g] > ";
		}
		string cmd = readCommand(cmdline.str());
		if(cmd == "u") {
			string name = readCommand("User > ");
			this->name = name;
		}else if(cmd == "p") {
			string pass = readCommand("Pass > ");
			this->pass = pass;
		}else if(pass == "" && name == "" && cmd == "g") {
			complete = true;
			guest = true;
		}else if(pass != "" && name != "" && cmd == "l") {
			complete = true;
		}
	}while(!complete);
}
