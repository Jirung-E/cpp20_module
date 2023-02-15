module IO.Output;

import :ConsoleView;
import :Print;

using namespace std;
using namespace IO;
using namespace Graphic;


// ------------------------------ ConsolePixel ------------------------------
ConsolePixel::ConsolePixel() : Pixel { pixel_set.size()-1, pixel_set.size()-1, pixel_set.size()-1 } {
    //set(5);
}


void ConsolePixel::set(int value) {
    Pixel::set(value, value, value);
}

char ConsolePixel::get() const {
    return pixel_set[(r+g+b)/3];
}
// --------------------------------------------------------------------------


ConsoleView::ConsoleView(const unsigned short int& width, const unsigned short int& height) : View { width, height } {
    for(vector<Pixel*>& e : pixels) {
        for(int i=0; i<width; ++i) {
            delete e[i];
            e[i] = new ConsolePixel { };
        }
    }
}


void ConsoleView::show() const {
    for(const vector<Pixel*>& e : pixels) {
        for(Pixel* p : e) {
            print(dynamic_cast<ConsolePixel*>(p)->get());
        }
        println("");
    }
}