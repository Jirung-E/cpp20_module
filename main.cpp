import Math.Space;
import IO;
import Graphic;
import <chrono>;
import <numbers>;
import <cmath>;
import <format>;
import <iostream>;

using namespace std;
using namespace chrono;
using namespace Math;
using namespace IO;
using namespace Graphic;


string getColor(const string& value) {
    size_t sep1;
    int r = stoi(value, &sep1, 16);
    string sub = value.substr(sep1+1);
    size_t sep2;
    int g = stoi(sub, &sep2, 16);
    int b = stoi(sub.substr(sep2+1), nullptr, 16);

    string result;
    const int x = 5;
    const int y = 5;
    setCursorPosition(x, y);
    print("Press '+' or '-' to increase or decrease value.");

    int cx = x;
    int cy = y+1;
    bool update = true;
    enum Arrow {
        Left = 75, Right = 77, Up = 72, Down = 80
    };
    const int y_red = y+1;
    const int y_green = y+2;
    const int y_blue = y+3;
    int* rgb[3] = { &r, &g, &b };
    while(true) {
        if(update) {
            string bar;

            setCursorPosition(x, y+1);
            print("R: ");
            for(int i=0; i<r; ++i) {
                bar += '#';
            }
            print(format("{:.<40} ({:X}) ", bar.substr(0, 40), r));
            bar = "";

            setCursorPosition(x, y+2);
            print("G: ");
            for(int i=0; i<g; ++i) {
                bar += '#';
            }
            print(format("{:.<40} ({:X}) ", bar.substr(0, 40), g));
            bar = "";

            setCursorPosition(x, y+3);
            print("B: ");
            for(int i=0; i<b; ++i) {
                bar += '#';
            }
            print(format("{:.<40} ({:X}) ", bar.substr(0, 40), b));

            setCursorPosition(cx, cy);

            update = false;
        }
        if(Keyboard::detected()) {
            int key_code = Keyboard::get();
            if(key_code == KEY::ESC) return value;
            if(key_code == KEY::ENTER) break;
            if(key_code == 224) {
                switch(Keyboard::get()) {
                case Arrow::Left:
                    (*(rgb[cy - y_red]))--;
                    update = true;
                    break;
                case Arrow::Down:
                    cy++;
                    if(cy > y_blue) {
                        cy = y_blue;
                    }
                    break;
                case Arrow::Right:
                    (*(rgb[cy - y_red]))++;
                    update = true;
                    break;
                case Arrow::Up:
                    cy--;
                    if(cy < y_red) {
                        cy = y_red;
                    }
                    break;
                }
                setCursorPosition(cx, cy);
            }
        }
    }

    return format("{:X}:{:X}:{:X}", r, g, b);
}


int main() {
    ConsoleView display { 50, 20 };
    Frame view { 50, 20 };
    Frame player { 3, 3 };
    player.set(1, 0, "3:3:3");
    player.set(1, 1, "5:5:5");
    player.set(1, 2, "4:4:4");
    player.set(0, 1, "2:2:2");
    player.set(2, 1, "2:2:2");
    int px = 0;
    int py = 0;
    Frame player_footprint { 1, 1 };
    player_footprint.set(0, 0, "1:1:1");
    bool painting = false;

    auto o = system_clock::now();
    auto entry_time = o;
    while(true) {
        if(Keyboard::detected()) {
            int key_code = Keyboard::get();
            println(format("{:<10}", key_code));
            if(key_code == KEY::ESC) break;
            switch(key_code) {
            case ' ': 
                painting = !painting; 
                break;
            case 'A': 
            case 'a': 
                px--; 
                break;
            case 'D': 
            case 'd': 
                px++; 
                break;
            case 'W': 
            case 'w': 
                py--; 
                break;
            case 'S': 
            case 's': 
                py++; 
                break;
            case ':':
                player_footprint.set(0, 0, getColor(player_footprint.value(0, 0)));
                break;
            }

            if(painting) {
                view.paste(player_footprint, px+1, py+2);
            }
        }
        auto now = system_clock::now();
        auto diff = (now - entry_time).count() / 10'000;
        size_t frame_per_sec = 15;
        if(diff >= 1000.0/frame_per_sec) {
            auto sec = (now - o).count() / 10'000;      // -> milliseconds
            display.clear();
            display.insert(view);
            display.insert(player, px, py);
            setCursorPosition(0, 0);
            println("play time: " + to_string(sec) + "ms");
            println(format("paint: {:<20} brush: {:<7}", player_footprint.value(0, 0), painting ? "on" : "off"));
            display.show();
            entry_time = now;
        }
    }
    
    println("Bye~");
}