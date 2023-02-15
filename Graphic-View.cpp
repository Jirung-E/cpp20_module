module Graphic;

import :View;

using namespace std;
using namespace Graphic;


View::View(const unsigned short int& width, const unsigned short int& height) : width_max { width }, height_max { height }, pixels { height, vector<Pixel*> { } } {
    for(vector<Pixel*>& e : pixels) {
        for(int i=0; i<width; ++i) {
            e.push_back(new Pixel { });
        }
    }
}

View::~View() {
    for(vector<Pixel*>& e : pixels) {
        for(int i=0; i<width_max; ++i) {
            delete e[i];
        }
    }
}


void View::insert(const Frame& frame, int x, int y) {
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

void View::clear() {
    for(vector<Pixel*>& e : pixels) {
        for(Pixel* p : e) {
            p->set(0, 0, 0);
        }
    }
}