export module Graphic:View;

import :Pixel;
import :Frame;
import <vector>;


namespace Graphic {
    export class View {
    protected:
        const unsigned short int width_max;
        const unsigned short int height_max;
        std::vector<std::vector<Pixel*>> pixels;

    public:
        View(const unsigned short int& width, const unsigned short int& height);
        ~View();

    public:
        virtual void show() const = 0;
        void insert(const Graphic::Frame& frame, int x=0, int y=0);
        virtual void clear();
    };
}