#include "calcDate.h"
#include "data_types.h"

int calcDate(date curr_date) {
    int days = 0;
    const int days_before_month[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    
    for (int year = 2000; year < curr_date.year; year++) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            days += 366;
        } else {
            days += 365;
        }
    }
    
    days += days_before_month[curr_date.month - 1];
    
    if (curr_date.month > 2) {
        if ((curr_date.year % 4 == 0 && curr_date.year % 100 != 0) || (curr_date.year % 400 == 0)) {
            days += 1;
        }
    }
    
    days += curr_date.day;
    return days;
}