#include "date.h"
#include <iostream>
date::date()
{
    dd = 0;
    mm = 0;
    yy = 0;
}
date::date(int day, int month, int year)
{
    this->dd = day;
    this->mm = month;
    this->yy = year;
}

bool date::compare(date date1, date date2)
{
    bool flag = false;
    int d1 = date1.dd + date1.mm * 31 + date1.yy * 365;
    int d2 = date2.dd + date2.mm * 31 + date2.yy * 365;
    if (d2 - d1 > 365)
        return true;
    return false;
}

void date::print_date()
{
    std::cout << "Date of issue: ";
    std::cout << dd << "-" << mm << "-" << yy << "\n";
}
