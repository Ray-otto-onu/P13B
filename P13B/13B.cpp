#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int dayOfWeek(int month, int day, int year);
string getDayName(int dayOfWeek);

int main() {
    string inputMonth, inputDay, inputYear;
    do {
        cout << "Enter a date (MM DD YYYY) or Q to quit: ";
        cin >> inputMonth;

        if (inputMonth == "Q" || inputMonth == "q") {
            break;
        }

        cin >> inputDay >> inputYear;

        int month = stoi(inputMonth);
        int day = stoi(inputDay);
        int year = stoi(inputYear);

        if (month < 1 || month > 12 || day < 1 || day > 31 || year < 1582) {
            cout << "Invalid input. Please enter a valid date." << endl;
            continue;
        }

        int dayOfWeekValue = dayOfWeek(month, day, year);
        cout << getDayName(dayOfWeekValue) << ", " << month << " " << day << ", " << year << endl;

    } while (true);

    return 0;
}

int dayOfWeek(int month, int day, int year) {
    if (month <= 2) {
        month += 12;
        year -= 1;
    }

    int h = (day + static_cast<int>(floor((13 * (month + 1)) / 5)) + year + static_cast<int>(floor(year / 4)) -
        static_cast<int>(floor(year / 100)) + static_cast<int>(floor(year / 400))) % 7;

    return h;
}

string getDayName(int dayOfWeek) {
    static const string dayNames[] = { "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
    return dayNames[dayOfWeek];
}
