#pragma once
class date
{
public:
    int dd;
    int mm;
    int yy;
    date();
    date(int day, int month, int year);
    bool compare(date date1, date date2);
    void print_date();
};

