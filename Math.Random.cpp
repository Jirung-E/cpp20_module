module;

#include <random>

module Math.Random;


namespace Math {
    std::random_device rd;
    std::mt19937 gen { rd() };

    double random(double start, double end) {
        static std::uniform_real_distribution<> urd { start, end };
        return urd(gen);
    }

    int randomInt(int start, int end) {
        static std::uniform_int_distribution<> uid { start, end };
        return uid(gen);
    }
}