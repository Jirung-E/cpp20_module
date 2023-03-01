module Graphic;

import :Frame;
import IO.Output;
import <fstream>;
import <regex>;

using namespace std;
using namespace Graphic;
using namespace IO;


Frame::Frame(const unsigned short int& width, const unsigned short int& height) : pixels { height, vector<Pixel*> { } } {
    for(vector<Pixel*>& e : pixels) {
        for(int i=0; i<width; ++i) {
            e.push_back(new Pixel { });
        }
    }
}

Frame::Frame(const std::string& file_name) {
    ifstream ifs { file_name };
    if(ifs.fail()) {
        println("No such file - \"" + file_name + "\"");
        return;
    }

    regex re { "(\\w+:\\w+:\\w+)" };
    smatch match;
    string buff;

    size_t line = 0;
    while(getline(ifs, buff)) {
        pixels.push_back(vector<Pixel*> { });

        size_t i = 0;
        while(regex_search(buff, match, re)) {
            pixels[line].push_back(new Pixel { });
            pixels[line][i++]->set(match.str());
            buff = match.suffix();
        }
        line++;
    }
}


string Frame::value(const unsigned short int& x, const unsigned short int& y) const {
    return pixels[y][x]->value();
}

void Frame::set(const unsigned short int& x, const unsigned short int& y, const string& value) {
    if(x >= width()) {
        return;
    }
    if(y >= height()) {
        return;
    }
    pixels[y][x]->set(value);
}

void Frame::paste(const Frame& other, const unsigned short int& x, const unsigned short int& y) {
    for(int i=0; i<other.height(); ++i) {
        int vy = y+i;
        if(vy<0 || vy>=height()) {
            continue;
        }
        for(int k=0; k<other.width(); ++k) {
            int vx = x+k;
            if(vx<0 || vx>=width()) {
                continue;
            }
            pixels[vy][vx]->set(other.value(k, i));
        }
    }
}

int Frame::width() const {
    return pixels[0].size();
}

int Frame::height() const {
    return pixels.size();
}


void Frame::saveAs(const string& file_name) const {
    ofstream ofs { file_name };
    for(const vector<Pixel*>& e : pixels) {
        for(Pixel* p : e) {
            ofs << p->value() << ',';
        }
        ofs << endl;
    }
}