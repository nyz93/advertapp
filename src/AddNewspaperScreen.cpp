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
