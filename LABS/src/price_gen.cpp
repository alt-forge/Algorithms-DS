#include <random>
#include "price_gen.h"

int nextPrice() {
    static std::random_device rd;
    static std::mt19937 engine(rd());
    static std::uniform_int_distribution<int> dist(100, 10000);
    return dist(engine);
}