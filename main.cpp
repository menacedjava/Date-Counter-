#include <iostream>
#include <ctime>

using namespace std;

// Sana hafta kunini qaytaradi
string findDayOfWeek(int day, int month, int year) {
    tm time_in = {};
    time_in.tm_mday = day;
    time_in.tm_mon = month - 1;
    time_in.tm_year = year - 1900;

    mktime(&time_in); // Sana hisoblanadi

    string days[] = {"Yakshanba", "Dushanba", "Seshanba", "Chorshanba", "Payshanba", "Juma", "Shanba"};
    return days[time_in.tm_wday];
}

// Joriy sanagacha kunlarni hisoblaydi
int daysBetween(int d, int m, int y) {
    time_t now = time(0);
    tm *current = localtime(&now);

    tm inputDate = {};
    inputDate.tm_mday = d;
    inputDate.tm_mon = m - 1;
    inputDate.tm_year = y - 1900;

    time_t inputTime = mktime(&inputDate);
    double seconds = difftime(now, inputTime);

    return seconds / (60 * 60 * 24); // Sekundni kunga aylantiramiz
}

int main() {
    int day, month, year;

    cout << "Sanani kiriting (kun oy yil): ";
    cin >> day >> month >> year;

    cout << "Bu sana: " << findDayOfWeek(day, month, year) << endl;
    cout << "Joriy sanagacha " << daysBetween(day, month, year) << " kun o‘tgan." << endl;

    return 0;
}
