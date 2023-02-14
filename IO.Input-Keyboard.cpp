module IO.Input;

import :Keyboard;
import <conio.h>;


namespace IO {
    bool Keyboard::detected() {
        return _kbhit();
    }

    int Keyboard::get() {
        return _getch();
    }
}