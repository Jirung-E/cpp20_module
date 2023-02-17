import Math.Space;
import IO;
import Graphic;
import <chrono>;

using namespace std::chrono;
using namespace Math;
using namespace IO;
using namespace Graphic;


int main() {
    ConsoleView view { 50, 20 };
    Frame frame { "frame1" };
    view.insert(frame);

    auto entry_time = system_clock::now();
    while(true) {
        if(Keyboard::detected()) {
            int ch = Keyboard::get();
            if(ch == KEY::ESC) {
                break;
            }
        }
        auto now = system_clock::now();
        size_t frame_per_sec = 60;
        if(now-entry_time >= milliseconds(1000/frame_per_sec)) {
            clear();
            view.show();
            entry_time = system_clock::now();
        }
    }

    println("Bye~");
}