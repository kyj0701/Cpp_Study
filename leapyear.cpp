#include <iostream>
#include <iomanip>
#include <vector>
#include <cstring>
#include <ctime>

using namespace std;

bool is_leap_year(int year) {
    return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}

// Print date to "YYYY-MM-DD"
void print_date(int year, int month, int day) {
    cout << year << '-';
    cout << setfill('0');
    cout << setw(2) << month << '-';
    cout << setw(2) << day << endl;    
}

int main(void) {
    int birth_year = 0;
    int birth_month = 0;
    int birth_day = 0;

    cout << "When's your birtday?" << endl;
    cout << "Year (YYYY) : ";
    cin >> birth_year;
    while (birth_year < 1900 || birth_year > 2022) {
        cout << "Wrong year" << endl;
        cout << "Year (YYYY) : ";
        cin >> birth_year;
    }
    cout << " Month (MM) : ";
    cin >> birth_month;
    while (birth_month < 1 || birth_month > 12) {
        cout << "Wrong month" << endl;
        cout << " Month (MM) : ";
        cin >> birth_month;
    }
    cout << "   Day (DD) : ";
    cin >> birth_day;
    while (birth_day < 1 || birth_day > 31) {
        cout << "Wrong day" << endl;
        cout << "   Day (DD) : ";
        cin >> birth_day;
    }

    // print_date(birth_year, birth_month, birth_day);

    time_t now = time(NULL);
    struct tm* now_t = localtime(&now);
    
    int now_year = now_t -> tm_year + 1900;
    int now_month = now_t -> tm_mon + 1;
    int now_day = now_t -> tm_mday;

    // print_date(now_year, now_month, now_day);

    int days = 0;
    int wday = now_t -> tm_wday + 1;

    days += now_day;
    if (now_month == 1) {
        now_year -= 1;
        now_month = 12;
    } else {
        now_month -= 1;
    }

    if (now_month < 12) {
        for (int i = 1; i <= now_month; i++)
        {
            if (i == 2) {
                if (is_leap_year(now_year)) days += 29;
                else days += 28;
            } 
            else if (i == 4 || i == 6 || i == 9 || i == 11) days += 30;
            else days += 31;
        }
        now_year -= 1;
    }

    for (int i = now_year; i > birth_year; i--) {
        if (is_leap_year(i)) days += 366;
        else days += 365;
    }

    for (int i = 12; i > birth_month; i--) {
        if (i == 2) {
            if (is_leap_year(birth_year)) days += 29;
            else days += 28;
        } 
        else if (i == 4 || i == 6 || i == 9 || i == 11) days += 30;
        else days += 31;
    }

    if (birth_month == 2) {
        if (is_leap_year(birth_year)) days += (29-birth_day+1);
        else days += (28-birth_day+1);
    }
    else if (now_month == 4 || now_month == 6 || now_month == 9 || now_month == 11) days += (30-birth_day+1);
    else days += (31-birth_day+1);

    days -= wday;

    int res = 6 - days % 7;

    if (res == 0) cout << "SUN" << endl;
    else if (res == 1) cout << "MON" << endl;
    else if (res == 2) cout << "TUE" << endl;
    else if (res == 3) cout << "WED" << endl;
    else if (res == 4) cout << "THU" << endl;
    else if (res == 5) cout << "FRI" << endl;
    else  cout << "SAT" << endl;


    return 0;
}