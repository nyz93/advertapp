#include "NewspaperSelectionScreen.h"

NewspaperSelectionScreen::NewspaperSelectionScreen(const vector<Newspaper*>& newspapers,
            const vector<Newspaper*>& selection): Screen("Select newspapers"), newspapers(newspapers) {
    result = selection;
}
int NewspaperSelectionScreen::find(Newspaper* np) {
	for(unsigned int i = 0; i < result.size(); i++) {
		if(result[i] == np) {
			return i;
		}
	}
	return -1;
}

void NewspaperSelectionScreen::show() {
	bool completed = false;
	cancelled = false;
	do {
		drawTitle();
		stringstream cmdline;
		int size = newspapers.size();
		if(size > 1) {
			cmdline << ",(1" << "-" << size << ")";
		}else{
			cmdline << ",1";
		}
		for(unsigned i = 0; i < newspapers.size(); i++) {
			cout << "(" << i+1 << ") ";
			if(find(newspapers[i]) != -1) {
				cout <<"[*]";
			}else{
				cout <<"[ ]";
			}
			Newspaper* p = newspapers[i];
			string test = p->getName();
			cout << test << endl;
		}
		cout << "(c)ancel selection" << endl;
		cout << "(f)inish selection" << endl;
		cmdline <<",c,f] > ";
		string prompt = cmdline.str();
		prompt[0] = '[';
		string cmd = readCommand(prompt);
		if(cmd == "c") {
			completed = true;
			cancelled = true;
		}else if(cmd == "f") {
			completed = true;
		}else{
			stringstream conv(cmd);
			unsigned s = 0;
			conv >> s;
			if(s > 0 && s < newspapers.size()+1) {
				auto current = newspapers[s-1];
				bool found = false;
				for(auto i = result.begin(); i != result.end(); i++) {
					if(*i == current) {
						result.erase(i);
						found = true;
						break;
					}
				}
				if(!found) {
					result.push_back(current);
				}
			}
		}
	}while(!completed);
}
