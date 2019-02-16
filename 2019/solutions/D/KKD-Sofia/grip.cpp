#include <bits/stdc++.h>
using namespace std;

int months2019[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int months2020[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int months2021[13] = {0, 31, 28, 31, 30, 31};

int n;
int day, month, year;
char placeholder;
int weekday;

string to_string(int a) {
    string s = "";
    while (a > 0) {
        s += a % 10 + '0';
        a /= 10;
    }
    string so = "";
    for (int i = s.size() - 1; i >= 0; -- i) {
        so += s[i];
    }
    return so;
}

int main() {
    cin >> day >> placeholder >> month >> placeholder >> year;
    cin >> n;
    //find weekday
    if (year == 2019) {
        int daynum = 1 + day;
        for (int i = 0; i < month; ++ i) {
            daynum += months2019[i];
        }
        weekday = daynum % 7 ? daynum % 7 : 7;
    }
    if (year == 2020) {
        int daynum = 2 + day;
        for (int i = 0; i < month; ++ i) {
            daynum += months2020[i];
        }
        weekday = daynum % 7 ? daynum % 7 : 7;
    }
    //goto the next monday
    while (n > 0) {
        if (n < 5) {
            day += n;
            weekday += n;
            n = 0;
        } else {
            n -= max(0, 6 - weekday);
            day += 7 - weekday + 1;
            weekday = 1;
        }
        if (year == 2019) {
            if (day > months2019[month]) {
                day -= months2019[month];
                month ++;
                if (month == 13) {
                    month = 1;
                    year ++;
                }
            }
        }
        if (year == 2020) {
            if (day > months2020[month]) {
                day -= months2019[month];
                month ++;
                if (month == 13) {
                    month = 1;
                    year ++;
                }
            }
        }
        if (year == 2021) {
            if (day > months2021[month]) {
                day -= months2021[month];
                month ++;
                if (month == 12) {
                    month = 1;
                    year ++;
                }
            }
        }
    }
    string date = "";
    if (day < 10) { date += "0"; }
    date += to_string(day);
    date += ".";
    if (month < 10) { date += "0"; }
    date += to_string(month);
    date += ".";
    date += to_string(year);
    cout << date << endl;
    return 0;
}
