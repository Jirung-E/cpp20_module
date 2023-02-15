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
}