#include <string>
using namespace std;

/* HIER */
#pragma once
#include "Employee.h"

class Manager : public Employee /* HIER */
{
    double _salary;

public:
    Manager(const string, const string, double);
    double get_income() const;
    void print() const;
};