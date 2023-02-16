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
    int res = static_cast<int>(static_cast<long int>(r) + static_cast<long int>(g) + static_cast<long int>(b)) / 3;   // 최댓값을 가질때, int인체로 그냥 합쳐버리변 overflow 발생하므로, 형변환 해줌
    if(res >= pixel_set.size()) {
        return pixel_set[pixel_set.size()-1];
    }
    return pixel_set[res];
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