module Graphic;

import :Frame;
import <fstream>;
import <iostream>;
import <regex>;

using namespace std;
using namespace Graphic;


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
        cout << "No such file - \"" + file_name + "\"\n";
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
            pixels[line].push_back(new Pixel { match.str() });
            buff = match.suffix();
        }
        line++;
    }
}


string Frame::value(const unsigned short int& x, const unsigned short int& y) const {
    return pixels[y][x]->value();
}

void Frame::set(const unsigned short int& x, const unsigned short int& y, const string& value) {
    pixels[y][x]->set(value);
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