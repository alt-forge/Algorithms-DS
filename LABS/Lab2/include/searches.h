#ifndef SEARCHES
#define SEARCHES
#include <vector>
#include "data_types.h"

int linearSearch_arr(booking* arr, int target, int filled);
int linearSearch_vec(const std::vector<booking>& vec, int target);
int interpolationSearch_arr(booking* arr, int n, int target);
int interpolationSearch_vec(const std::vector<booking>& vec, int target);
int barrierSearch_arr(booking* arr, int n, int target);
int barrierSearch_vec(const std::vector<booking>& vec, int target);

#endif