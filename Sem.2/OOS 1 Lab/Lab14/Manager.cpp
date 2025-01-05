/* hier */
module;

#include <string>
#include <iostream>
import Employee;
export module Manager;
using namespace std;

/* hier */ export class Manager : public Employee /* hier */
{
    double _salary;

public:
    Manager(const string f_n, const string l_n, double s = 0)
        : Employee(f_n, l_n)
    {
        /* HIER */
        _salary = s;
    }
    double get_income() const
    {
        /* HIER */
        return _salary;
    }
    void print() const
    {
        cout << "Manager: ";
        Employee::print();
    }
};
