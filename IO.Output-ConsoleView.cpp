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


ConsoleView::ConsoleView(const unsigned short int& width, const unsigned short int& height) : width_max { width }, height_max { height }, pixels { height, vector<Pixel*> { } } {
    for(vector<Pixel*>& e : pixels) {
        for(int i=0; i<width; ++i) {
            e.push_back(new ConsolePixel { });
        }
    }
}


void ConsoleView::show() const {
    for(const std::vector<Pixel*>& e : pixels) {
        for(Pixel* p : e) {
            print(dynamic_cast<ConsolePixel*>(p)->get());
        }
        println("");
    }
}

void ConsoleView::insert(const Graphic::Frame& frame, int x, int y) {
    for(int i=0; i<frame.height(); ++i) {
        int vy = y+i;
        if(vy<0 || vy>=height_max) {
            continue;
        }
        for(int k=0; k<frame.width(); ++k) {
            int vx = x+k;
            if(vx<0 || vx>=width_max) {
                continue;
            }
            pixels[vy][vx]->set(frame.value(k, i));
        }
    }
}

void ConsoleView::clear() {
    for(vector<Pixel*>& e : pixels) {
        for(Pixel* p : e) {
            p->set(0, 0, 0);
        }
    }
}