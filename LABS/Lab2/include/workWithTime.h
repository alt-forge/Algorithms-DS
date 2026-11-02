#ifndef MEASURETIME
#define MEASURETIME

#include <chrono>
#include <utility>
#include <string>

template <typename F>
double measure_ms(F&& fn) {
    auto t0 = std::chrono::steady_clock::now();
    std::forward<F>(fn)();
    auto t1 = std::chrono::steady_clock::now();
    return std::chrono::duration<double, std::milli>(t1 - t0).count();
}

void print_time(std::string title, double t1, double t2, double t3);

#endif