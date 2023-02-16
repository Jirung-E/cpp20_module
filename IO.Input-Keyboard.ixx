export module IO.Input:Keyboard;


namespace IO {
    export enum KEY {
        ESC = 27
    };
    export class Keyboard {
    public:
        static bool detected();
        static int get();
    };
}