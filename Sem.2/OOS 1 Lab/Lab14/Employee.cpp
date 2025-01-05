module;

#include <string>
#include <iostream>
using namespace std;
export module Employee;
/* hier */
export class Employee
{
    string _first_name;
    string _last_name;

public:
    Employee(const string f_n, const string l_n)
    {
        /* HIER */
        _first_name = f_n;
        _last_name = l_n;
    }
    void print() const
    {
        cout << _last_name << ", " << _first_name << endl;
    }
};
