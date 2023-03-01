export module IO.Output:ConsoleView;

import Graphic;
import <vector>;


namespace IO {
    // Do not export
    const std::vector<char> pixel_set { ' ', '.', ',', ':', ';', 'i', 'j', 'I', '%' };

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