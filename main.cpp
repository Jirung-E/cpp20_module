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
    Frame frame { 50, 20 };
    Frame frame_view { 50, 20 };
    view.insert(frame);

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
            double rps = 2;                             // round per sec
            int x = 15 + round(10 * sin(rps * (sec / 1'000.0) * 2*numbers::pi));
            int y = 10 + round(5 * cos(rps * (sec / 1'000.0) * 2*numbers::pi));
            frame_view.set(x, y, "F:F:F");
            frame.set(x, y, "F:F:F");
            view.insert(frame_view);
            frame_view.set(x, y, "0:0:0");
            clear();
            println(to_string(sec));
            view.show();
            entry_time = now;
        }
    }

    frame.saveAs("circle");
    view.insert(frame);
    clear();
    view.show();

    println("Bye~");
}