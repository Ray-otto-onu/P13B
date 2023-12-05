#include <iostream>
#include <string>

using namespace std;
bool isLeapYear(int year);

int main() {
    string input;
    do {
        cout << "Enter a year or Q to quit: ";
        cin >> input;
        if (input == "Q" || input == "q") {
            break;
        }

        int year = stoi(input);
        if (isLeapYear(year)) {
            cout << year << " is a leap year." << endl;
        }
        else {
            cout << year << " is not a leap year." << endl;
        }
    } while (true);
    return 0;
}

bool isLeapYear(int year) {
    if (year < 1582) {
        cout << "Year should be >= 1582 for Gregorian calendar." << endl;
        return false;
    }

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    }
    else {
        return false;
    }
}


