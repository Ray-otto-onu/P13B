#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int getMonthNumber(const string& monthName);
void displayCalendar(int month, int year, ostream& outputStream);



int main() {
    string inputMonthAndYear;
    do {
        cout << "Enter a month and year (Month YYYY) or Q to quit: ";
        getline(cin, inputMonthAndYear);
        cout << endl;

        if (inputMonthAndYear == "Q" || inputMonthAndYear == "q") {
            break;
        }

        istringstream iss(inputMonthAndYear);
        string inputMonth, inputYear;
        iss >> inputMonth >> inputYear;

        int year = stoi(inputYear);

        if (year < 1582) {
            cout << "Invalid input. Year should be >= 1582." << endl;
            continue;
        }

        int month = getMonthNumber(inputMonth);
        if (month == -1) {
            cout << "Invalid month name. Please enter a valid full month name." << endl;
            continue;
        }

        cout << inputMonthAndYear << endl;

        ofstream outputFile(inputMonth.substr(0, 3) + inputYear + ".txt");

        if (!outputFile.is_open()) {
            cout << "Error opening output file." << endl;
            return 1;
        }

        outputFile << inputMonthAndYear << endl;

        displayCalendar(month, year, cout);
        displayCalendar(month, year, outputFile);

        cout << "Output file: " << inputMonth.substr(0, 3) + inputYear + ".txt" << endl;

        outputFile.close();

    } while (true);

    return 0;
}

int main();
int getMonthNumber(const string& monthName) {
    string monthNames[] = { "January", "February", "March", "April", "May", "June",
                           "July", "August", "September", "October", "November", "December" };

    for (int i = 0; i < 12; ++i) {
        if (monthName == monthNames[i]) {
            return i + 1;
        }
    }
    return -1;
}

void displayCalendar(int month, int year, ostream& outputStream) {
    const int daysInMonth[] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int firstDay = (6 + 9 * month + 3 * (month + 1) / 10 + year + year / 4 - year / 100 + year / 400 - (month < 3 ? 1 : 0)) % 7;
  
    if (firstDay == 0)
    firstDay = (1 + 4 * month + 3 * (month + 1) / 10 + year + year / 4 - year / 100 + year / 400 - (month < 3 ? 1 : 0)) % 7; 
   
    outputStream << " Su Mo Tu We Th Fr Sa" << endl;

    for (int i = 0; i < firstDay; ++i) {
        outputStream << "   ";
    }

    for (int day = 1; day <= daysInMonth[month]; ++day) {
        outputStream << " " << setw(2) << day;

        if ((firstDay + day) % 7 == 0) {
            outputStream << endl;
        }
    }

    if ((firstDay + daysInMonth[month]) % 7 != 0) {
        outputStream << endl;
    }

    outputStream << endl;
}