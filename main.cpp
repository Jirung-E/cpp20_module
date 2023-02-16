import <iostream>;
import <chrono>;

import Math.Space;
import IO;
import Graphic;

using namespace std;
using namespace chrono;
using namespace Math;
using namespace IO;
using namespace Graphic;


int main() {
    ConsoleView view { 50, 20 };
    //Frame frame { 50, 20 };
    Frame frame { "frame1" };
    //frame.set(5, 5, "2:4:0");
    //frame.saveAs("frame1");
    view.insert(frame);

    auto entry_time = system_clock::now();
    while(true) {
        if(Keyboard::detected()) {
            int ch = Keyboard::get();
            //cout << ch << endl;
            if(ch == KEY::ESC) {
                break;
            }
        }
        auto now = system_clock::now();
        size_t frame_per_sec = 60;
        if(now-entry_time >= milliseconds(1000/frame_per_sec)) {
            //view.clear();
            clear();
            //cout << now-entry_time << endl;
            //view.insert(frame);
            view.show();
            entry_time = system_clock::now();
        }
    }

    println("Bye~");
}