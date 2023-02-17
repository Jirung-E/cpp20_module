export module Graphic:Frame;

import :Pixel;
import <string>;
import <vector>;


namespace Graphic {
    export class Frame {
    private:
        std::vector<std::vector<Pixel*>> pixels;
        
    public:
        Frame(const unsigned short int& width, const unsigned short int& height);
        Frame(const std::string& file_name);

    public:
        std::string value(const unsigned short int& x, const unsigned short int& y) const;
        void set(const unsigned short int& x, const unsigned short int& y, const std::string& value);

        int width() const;
        int height() const;

        void saveAs(const std::string& file_name) const;
    };
}