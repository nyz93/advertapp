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
        year = info->tm_year+1900;
        month = info->tm_mon;
        day = info->tm_mday;
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
    bool isValid() const {
        struct tm backup;
        time_t ct;
        time(&ct);
        struct tm* info;
        info = localtime(&ct);
        backup.tm_year = info->tm_year = year-1900;
        backup.tm_mon = info->tm_mon = month;
        backup.tm_mday = info->tm_mday = day;
        mktime(info);
        return (info->tm_year == backup.tm_year && info->tm_mon == backup.tm_mon &&
                info->tm_mday == backup.tm_mday);
    }
};
#endif
