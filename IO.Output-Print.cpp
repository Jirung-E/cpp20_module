module IO.Output;

import :Print;
import <iostream>;

using namespace std;


namespace IO {
    void print(const string& text) {
        cout << text;
    }

    void print(const char& ch) {
        cout << ch;
    }

    void println(const string& text) {
        cout << text + '\n';
    }

    void clear() {
        system("cls");
    }
    
    void setCursorPosition(const unsigned short int& x, const unsigned short int& y) {
        printf("%c[%d;%df", 0x1B, y, x);
    }
}