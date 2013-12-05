#include "EditNewspaperScreen.h"
using namespace std;

EditNewspaperScreen::EditNewspaperScreen(const Newspaper* old): old(old) {}

EditNewspaperScreen::~EditNewspaperScreen() {}

void EditNewspaperScreen::show() {
    bool completed = false;
    string name = old->getName();
    int img = old->getPriceFor(AdvertType::Image);
    int text = old->getPriceFor(AdvertType::Text);
    int textimg = old->getPriceFor(AdvertType::TextImage);
    do {
        cancelled = false;
        drawTitle();
        cout << "(n)ame: " << name << endl;
        cout << "(t)ext price: " << text << endl;
        cout << "(i)mage price: " << img << endl;
        cout << "(t)ext-(i)mage price: " << textimg << endl;
        stringstream cmdline;
        cmdline << "[n,t,i,ti";
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
