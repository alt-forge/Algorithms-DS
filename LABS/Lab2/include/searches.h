#ifndef SEARCHES
#define SEARCHES
#include <vector>
#include "data_types.h"

int linearSearch_arr(booking* arr, int target, int filled, int& cmp);
int linearSearch_vec(const std::vector<booking>& vec, int target, int& cmp);
int interpolationSearch_arr(booking* arr, int n, int target, int& cmp);
int interpolationSearch_vec(const std::vector<booking>& vec, int target, int& cmp);
int barrierSearch_arr(booking* arr, int n, int target, int& cmp);
int barrierSearch_vec(const std::vector<booking>& vec, int target, int& cmp);

#endif