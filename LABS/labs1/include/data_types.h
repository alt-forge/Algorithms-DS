#ifndef DATA_TYPES
#define DATA_TYPES

#include <string>
#include <set>
#include <ostream>

struct date
{
    int day;
    int month;
    int year;
};

struct booking
{
    std::string passport;
    date date_booking;
    std::set<int> rooms_nums;
    int price;
};

std::ostream& operator<<(std::ostream& os, const date& d);

#endif