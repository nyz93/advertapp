/*
 * The MIT License (MIT)
 * 
 * Copyright (c) 2013 Zoltán Nyikos
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "Date.h"

Date::Date(int year, int month, int day): year(year),month(month),day(day){}

Date::Date() {
	time_t ct;
	time(&ct);
	struct tm* info;
	info = localtime(&ct);
	year = info->tm_year+1900;
	month = info->tm_mon+1;
	day = info->tm_mday;
}

bool Date::operator<(const Date& b) const {
	if(year < b.year)
		return true;
	if(month < b.month)
		return true;
	if(day < b.day)
		return true;
	return false;
}

bool Date::operator>(const Date& b) const {
	if(year > b.year)
		return true;
	if(month > b.month)
		return true;
	if(day > b.day)
		return true;
	return false;
}

bool Date::operator==(const Date& b) const {
	return (year == b.year && month == b.month && day == b.day);
}

int Date::getYear() const {
	return year;
}

int Date::getMonth() const {
	return month;
}

int Date::getDay() const {
	return day;
}

bool Date::isValid() const {
	struct tm backup;
	time_t ct;
	time(&ct);
	struct tm* info;
	info = localtime(&ct);
	backup.tm_year = info->tm_year = year-1900;
	backup.tm_mon = info->tm_mon = month-1;
	backup.tm_mday = info->tm_mday = day;
	mktime(info);
	return (info->tm_year == backup.tm_year && info->tm_mon == backup.tm_mon &&
			info->tm_mday == backup.tm_mday);
}

int Date::diffDays(const Date& b) const {
	time_t ct;
	time(&ct);
	struct tm* date;
	date = localtime(&ct);
	date->tm_year = year-1900;
	date->tm_mon = month-1;
	date->tm_mday = day;
	time_t this_t = mktime(date);
	date->tm_year = b.year-1900;
	date->tm_mon = b.month-1;
	date->tm_mday = b.day;
	time_t b_t = mktime(date);
	time_t secdiff = this_t - b_t;
	return abs((int)(secdiff/60/60/24));
}

std::ostream& operator<<(std::ostream& o, const Date& d) {
    o << d.year << "-" << d.month << "-" << d.day;
    return o;
}
