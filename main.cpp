import Math.Space;
import IO;
import Graphic;
import <chrono>;
import <numbers>;
import <cmath>;

using namespace std;
using namespace chrono;
using namespace Math;
using namespace IO;
using namespace Graphic;


int main() {
    ConsoleView view { 50, 20 };
    Frame frame_view { 50, 20 };

    auto o = system_clock::now();
    auto entry_time = o;
    while(true) {
        if(Keyboard::detected()) {
            int ch = Keyboard::get();
            if(ch == KEY::ESC) {
                break;
            }
        }
        auto now = system_clock::now();
        auto diff = (now - entry_time).count();
        size_t frame_per_sec = 60;
        if(diff >= 1000/frame_per_sec) {
            auto sec = (now - o).count() / 10'000;      // -> milliseconds
            Vector v;
            v.x = sec/100.0;
            v.y = v.x;
            frame_view.set(v.x, v.y, "F:F:F");
            view.insert(frame_view);
            setCursorPosition(0, 0);
            println("play time: " + to_string(sec) + "ms");
            view.show();
            entry_time = now;
        }
    }

    println("Bye~");
}