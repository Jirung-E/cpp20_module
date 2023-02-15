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
    std::cout << "Hello World!" << std::endl;

    //Point p1 = Point::randomPoint();
    //printf("<%.2f, %.2f, %.2f>\n", p1.x, p1.y, p1.z);
    //Point p2 = Point::randomPoint();
    //printf("<%.2f, %.2f, %.2f>\n", p2.x, p2.y, p2.z);
    //Point p3 = Point::randomPoint();
    //printf("<%.2f, %.2f, %.2f>\n", p3.x, p3.y, p3.z);

    //Vector v = p1 - p2;
    //printf("<%.2f, %.2f, %.2f>\n", v.x, v.y, v.z);

    //for(int i=0; i<1000; ++i) {
    //    Vector rv = Vector::randomVector();
    //    printf("<%3.0f, %3.0f, %3.0f>\n", rv.x, rv.y, rv.z);
    //}

    ConsoleView view { 50, 20 };
    //Frame frame { 50, 20 };
    Frame frame { "frame1" };
    //frame.set(5, 5, "2:4:0");
    //frame.saveAs("frame1");

    auto entry_time = system_clock::now();
    while(true) {
        if(Keyboard::detected()) {
            int ch = Keyboard::get();
            //cout << ch << endl;
            if(ch == 27) {
                break;
            }
        }
        auto now = system_clock::now();
        size_t frame_per_sec = 60;
        if(now-entry_time >= milliseconds(1000/frame_per_sec)) {
            //view.clear();
            clear();
            //cout << now-entry_time << endl;
            view.insert(frame);
            view.show();
            entry_time = system_clock::now();
        }
    }

    cout << "Bye~" << endl;
}