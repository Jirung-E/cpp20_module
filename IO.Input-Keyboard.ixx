export module IO.Input:Keyboard;


namespace IO {
    export class Keyboard {
    public:
        static bool detected();
        static int get();
    };
}