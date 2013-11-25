#ifndef _DATE_H_
#define _DATE_H_
#include <time.h>
class Date {
    int year;
    int month;
    int day;
    public:
    Date(int year, int month, int day): year(year),month(month),day(day){}
    Date() {
        time_t ct;
        time(&ct);
        struct tm* info;
        info = localtime(&ct);
        Date(info->tm_year,info->tm_mon,info->tm_mday);
    }
    bool operator<(const Date& b) const {
        if(year < b.year)
            return true;
        if(month < b.month)
            return true;
        if(day < b.day)
            return true;
        return false;
    }
    bool operator>(const Date& b) const {
        if(year > b.year)
            return true;
        if(month > b.month)
            return true;
        if(day > b.day)
            return true;
        return false;
    }
    bool operator==(const Date& b) const {
        return (year == b.year && month == b.month && day == b.day);
    }
    int getYear() const {
        return year;
    }
    int getMonth() const {
        return month;
    }
    int getDay() const {
        return day;
    }
};
#endif
