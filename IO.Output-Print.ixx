export module IO.Output:Print;

import <string>;


namespace IO {
    export void print(const std::string& text);
    export void print(const char& ch);
    export void println(const std::string& text="");
    export void clear();
    export void setCursorPosition(const unsigned short int& x, const unsigned short int& y);
}