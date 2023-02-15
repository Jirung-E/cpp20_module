export module IO.Output:ConsoleView;

import Container;
import Graphic;


namespace IO {
    // Do not export
    const std::vector<char> pixel_set { ' ', '.', ':', 'i', 'l', 'I', '%' };

    class ConsolePixel : public Graphic::Pixel {
    public:
        ConsolePixel();

    public:
        void set(int value);
        char get() const;
    };

    export class ConsoleView {
    private:
        const unsigned short int width_max;
        const unsigned short int height_max;
        std::vector<std::vector<Graphic::Pixel*>> pixels;

    public:
        ConsoleView(const unsigned short int& width, const unsigned short int& height);

    public:
        void show() const;
        void insert(const Graphic::Frame& frame, int x=0, int y=0);
        void clear();
    };
}