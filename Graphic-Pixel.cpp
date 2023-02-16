module Graphic;

import :Pixel;
import <numeric>;
import <format>;

using namespace std;
using namespace Graphic;


Pixel::Pixel(int r_max, int g_max, int b_max) : r_max { r_max }, g_max { g_max }, b_max { b_max }, r { 0 }, g { 0 }, b { 0 } {

}

Pixel::Pixel() : Pixel { numeric_limits<int>::max(), numeric_limits<int>::max(), numeric_limits<int>::max() } {

}

Pixel::Pixel(const string& value) : Pixel { } {
    set(value);
}


string Pixel::value() const {
    return format("{:X}:{:X}:{:X}", r, g, b);
}

void Pixel::set(int r, int g, int b) {
    setr(r);
    setg(g);
    setb(b);
}

void Pixel::set(const string& value) {
    size_t sep1;
    int r = stoi(value, &sep1, 16);
    if(sep1 == string::npos) {
        int v = stoi(value);
        set(v, v, v);
        return;
    }

    string sub = value.substr(sep1+1);
    size_t sep2;
    int g = stoi(sub, &sep2, 16);
    int b = stoi(sub.substr(sep2+1), nullptr, 16);
    set(r, g, b);
}

void Pixel::setr(int value) {
    if(value > r_max) {
        r = r_max;
    }
    else if(value < 0) {
        r = 0;
    }
    else {
        r = value;
    }
}

void Pixel::setg(int value) {
    if(value > g_max) {
        g = g_max;
    }
    else if(value < 0) {
        g = 0;
    }
    else {
        g = value;
    }
}

void Pixel::setb(int value) {
    if(value > b_max) {
        b = b_max;
    }
    else if(value < 0) {
        b = 0;
    }
    else {
        b = value;
    }
}
