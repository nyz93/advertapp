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
