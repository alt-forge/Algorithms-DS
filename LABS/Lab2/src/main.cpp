#include <iostream>

#include "read_arr.h"
#include "read_arr_sort.h"
#include "read_vec.h"

#include "remove_arr_vec.h"

#include "calcDate.h"
#include "searches.h"
#include "workWithTime.h"

int main() {
    // Инициализация входных данных
    std::string f = "output_1000.txt";

    date goal_date_search;
    goal_date_search.day = 12;
    goal_date_search.month = 6;
    goal_date_search.year = 2025;
    int goal_key_search = calcDate(goal_date_search);

    date goal_date_del;
    goal_date_del.day = 22;
    goal_date_del.month = 1;
    goal_date_del.year = 2021;
    int goal_key_del = calcDate(goal_date_del);

    // Считывание в статический массив
    booking* arr = nullptr;
    int n_arr = 0;
    double t_arr = measure_ms([&] {
        auto p = read_in_arr(f);
        arr = p.first;
        n_arr = p.second;
    });

    // Считывание в статический упорядоченный массив
    booking* arr_sort = nullptr;
    int n_sort = 0;
    double t_sort = measure_ms([&] {
        auto p = read_in_arr_sort(f);
        arr_sort = p.first;
        n_sort = p.second;
    });

    // Считывание в упорядоченный вектор
    std::vector<booking> vec;
    double t_vec = measure_ms([&] {
        vec = read_in_vector(f);
    });

    print_time("Время затраченное на считывание:", t_arr, t_sort, t_vec);


    // Интерполяционный поиск
    int cmp_interp_arr = 0;
    int idx_interp_arr = -1;
    double t_interp_arr = measure_ms([&] {
        idx_interp_arr = interpolationSearch_arr(arr, n_arr, goal_key_search, cmp_interp_arr);
    });

    int cmp_interp_sort = 0;
    int idx_interp_sort = -1;
    double t_interp_sort = measure_ms([&] {
        idx_interp_sort = interpolationSearch_arr(arr_sort, n_sort, goal_key_search, cmp_interp_sort);
    });

    int cmp_interp_vec = 0;
    int idx_interp_vec = -1;
    double t_interp_vec = measure_ms([&] {
        idx_interp_vec = interpolationSearch_vec(vec, goal_key_search, cmp_interp_vec);
    });

    print_cmp(cmp_interp_arr,cmp_interp_sort,cmp_interp_vec);
    print_time("Время затраченное при INTERPOLATION SEARCH:", t_interp_arr, t_interp_sort, t_interp_vec);

    /*
    if ((idx_interp_sort != -1) and (idx_interp_vec != -1)) {
        std::cout << arr[idx_interp_arr].date_booking << ' ' << idx_interp_arr << '\n';
        std::cout << arr_sort[idx_interp_sort].date_booking << ' ' << idx_interp_sort << '\n';
        std::cout << vec[idx_interp_vec].date_booking << ' ' << idx_interp_vec << '\n'; 
    } else std::cout << "элемент не найден" << '\n'; 
     */

    // Линейный поиск с барьером
    int cmp_barrier_arr = 0;
    int idx_barrier_arr = -1;
    double t_barrier_arr = measure_ms([&] {
        idx_barrier_arr = barrierSearch_arr(arr, n_arr, goal_key_search, cmp_barrier_arr);
    });

    int cmp_barrier_sort = 0;
    int idx_barrier_sort = -1;
    double t_barrier_sort = measure_ms([&] {
        idx_barrier_sort = barrierSearch_arr(arr_sort, n_sort, goal_key_search, cmp_barrier_sort);
    });

    int cmp_barrier_vec = 0;
    int idx_barrier_vec = -1;
    double t_barrier_vec = measure_ms([&] {
        idx_barrier_vec = barrierSearch_vec(vec, goal_key_search, cmp_barrier_vec);
    });

    print_cmp(cmp_barrier_arr,cmp_barrier_sort,cmp_barrier_vec);
    print_time("Время затраченное при BARRIER SEARCH:", t_barrier_arr, t_barrier_sort, t_barrier_vec);
    
    /*
    if ((idx_barrier_arr != -1) and (idx_barrier_sort != -1) and (idx_barrier_vec != -1)) {
        std::cout << arr[idx_barrier_arr].date_booking << ' ' << idx_barrier_arr << '\n';
        std::cout << arr_sort[idx_barrier_sort].date_booking << ' ' << idx_barrier_sort << '\n';
        std::cout << vec[idx_barrier_vec].date_booking << ' ' << idx_barrier_vec << '\n'; 
    } else std::cout << "элемент не найден" << '\n';
    */

    // Поиск позиции для удаления по ключу
    int cmp_del_arr = 0;
    int cmp_del_sort = 0;
    int cmp_del_vec = 0;
    int idx_for_del_arr = barrierSearch_arr(arr, n_arr, goal_key_del, cmp_del_arr);
    int idx_for_del_sort = interpolationSearch_arr(arr_sort, n_sort, goal_key_del, cmp_del_sort);
    int idx_for_del_vec = interpolationSearch_vec(vec, goal_key_del, cmp_del_vec);

    /*    
    std::cout << '\n';
    std::cout << "idx_arr = " << idx_for_del_arr
          << ", idx_sort = " << idx_for_del_sort
          << ", idx_vec = " << idx_for_del_vec << "\n";
    std::cout << "n_arr before = " << n_arr
            << ", n_sort before = " << n_sort
            << ", vec.size before = " << vec.size() << "\n";
    std::cout << '\n'; */

    // Удаление в статическом массиве
    double t_remove_arr = measure_ms([&] {
        n_arr = remove_arr(arr, n_arr, idx_for_del_arr);
    });

    // Удаление в статическом упорядоченном массиве
    double t_remove_sort = measure_ms([&] {
        n_sort = remove_arr(arr_sort, n_sort, idx_for_del_sort);
    });
    
    // Удаление в упорядоченом векторе
    bool l = false;
    double t_remove_vec = measure_ms([&] {
        remove_vec(vec, idx_for_del_vec);
    });

    print_cmp(cmp_del_arr,cmp_del_sort,cmp_del_vec);
    print_time("Время удаления внутри:", t_remove_arr, t_remove_sort, t_remove_vec);
}