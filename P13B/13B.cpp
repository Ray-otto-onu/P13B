#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

bool isLeapYear(int year);
string getMonthName(int month);
string daysInMonth(int month, int year);

int main() {
    string inputMonth, inputYear;
    do {
        cout << "Enter a month and year (MM YYYY) or Q to quit: ";
        cin >> inputMonth;

        if (inputMonth == "Q" || inputMonth == "q") {
            break;
        }

        cin >> inputYear;

        int month = stoi(inputMonth);
        int year = stoi(inputYear);

        if (month < 1 || month > 12 || year < 1582) {
            cout << "Invalid input. Month should be in the range [1..12] and year should be >= 1582." << endl;
            continue;
        }

        cout << getMonthName(month) << " " << year << " has " << daysInMonth(month, year) << " days." << endl;

    } while (true);

    return 0;
}

bool isLeapYear(int year) {
    if (year < 1582) {
        cout << "Year should be >= 1582 for Gregorian calendar." << endl;
        return false;
    }

    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

string getMonthName(int month) {
    static const string monthNames[] = { "January", "February", "March", "April", "May", "June",
                                        "July", "August", "September", "October", "November", "December" };
    return monthNames[month - 1];
}

string daysInMonth(int month, int year) {
    int days = 0;

    switch (month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        days = 31;
        break;
    case 4: case 6: case 9: case 11:
        days = 30;
        break;
    case 2:
        days = isLeapYear(year) ? 29 : 28;
        break;
    }

    return to_string(days);
}
