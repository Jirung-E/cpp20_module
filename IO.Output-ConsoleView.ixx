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

    export class ConsoleView : public Graphic::View {
    public:
        ConsoleView(const unsigned short int& width, const unsigned short int& height);

    public:
        void show() const;
    };
}