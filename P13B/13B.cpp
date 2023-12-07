#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int dayOfWeek(int month, int day, int year);
void displayCalendar(int month, int year);

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

        displayCalendar(month, year);

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

void displayCalendar(int month, int year) {

    string calendar[] = { " 1  2  3  4  5  6  7  ",
                         " 8  9 10 11 12 13 14 ",
                         "15 16 17 18 19 20 21 ",
                         "22 23 24 25 26 27 28 ",
                         "29 30 31             " };

    int firstDay = dayOfWeek(month, 1, year);

    cout << " Mo Tu We Th Fr Sa Su" << endl;

    for (int i = 0; i < firstDay; ++i) {
        cout << "   ";
    }

    for (int i = 0; i < 6; ++i) {
        cout << calendar[i].substr(3 * firstDay, 21);

        if (i == 4 && calendar[i].length() > 21) {
            cout << calendar[i].substr(21);
        }

        cout << endl;
    }
    cout << endl;
}
