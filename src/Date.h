#ifndef DATE_H
#define DATE_H
#include <time.h>
#include <stdlib.h>
class Date {
    int year;
    int month;
    int day;
    public:
    Date(int year, int month, int day);
    Date();
    bool operator<(const Date& b) const;
    bool operator>(const Date& b) const;
    bool operator==(const Date& b) const;
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    bool isValid() const;
    int diffDays(const Date& b) const;
};
#endif
