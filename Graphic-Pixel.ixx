export module Graphic:Pixel;

import <string>;


namespace Graphic {
    export class Pixel {
    protected:
        const int r_max;
        const int g_max;
        const int b_max;
        int r;
        int g;
        int b;

    public:
        Pixel(int r_max, int g_max, int b_max);
        Pixel(const std::string& value);
        Pixel();

    public:
        std::string value() const;
        void set(int r, int g, int b);
        virtual void set(const std::string& value);

    private:
        void setr(int value);
        void setg(int value);
        void setb(int value);
    };
}