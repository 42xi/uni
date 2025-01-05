#include <iostream>
using namespace std;

class Date
{

    int _day, _month, _year;

public:
    Date(int = 0, int = 0, int = 0);

    Date operator+(int days);
    friend ostream &operator<<(ostream &, const Date &);
};

// Konstruktor-Implementierung
Date::Date(int day, int month, int year)
    : _day(day), _month(month), _year(year) {}

// Implementierung der Operatorüberladung für das Hinzufügen von Tagen
Date Date::operator+(int days)
{
    int new_day = _day + days;
    int new_month = _month;
    int new_year = _year;

    // Berechnung der Überläufe:
    // 1 Monat = 30 Tage, 1 Jahr = 12 Monate = 360 Tage
    while (new_day > 30)
    {
        new_day -= 30;
        new_month += 1;

        // Überlauf für Monate zu Jahren
        if (new_month > 12)
        {
            new_month -= 12;
            new_year += 1;
        }
    }

    return Date(new_day, new_month, new_year);
}

// Implementierung des Ausgabeoperators
ostream &operator<<(ostream &out, const Date &date)
{
    out << date._day << "." << date._month << "." << date._year;
    return out;
}

int main(int argc, char *argv[])
{
    Date begin_task = Date(26, 10, 2023);
    cout << "Die Aufgabe beginnt am " << begin_task << endl;
    Date end_task = begin_task + 6;
    cout << "Die Aufgabe endet am " << end_task << endl;
    Date one_year_and_one_month_later = begin_task + 390;
    cout << "Ein Jahr und ein Monat nach Aufgabenbeginn ist der " << one_year_and_one_month_later << endl;
    Date three_years_and_eleven_months_later = begin_task + 1410;
    cout << "Drei Jahre und 11 Monate nach Aufgabenbeginn ist der " << three_years_and_eleven_months_later << endl;
}
