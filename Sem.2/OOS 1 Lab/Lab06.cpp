#include <string>
#include <iostream>
using namespace std;

// Klasse Student
class Student
{

private:
    string _name;
    string _first_name;

public:
    Student(string name, string first_name);

    string get_name() const;
    string get_firstname() const;

    void print();
    void print(bool newLine);

    ~Student();
};

Student::Student(string name, string first_name)
{
    _name = name;
    _first_name = first_name;
    cout << "Parametrisierter Konstruktor Student: " << _first_name << " " << _name << endl;
}

string Student::get_name() const
{
    return _name;
}

string Student::get_firstname() const
{
    return _first_name;
}

void Student::print()
{
    cout << "print() ohne Parameter; Student: " << _first_name << " " << _name << endl;
}

void Student::print(bool newLine)
{
    cout << "print() mit Parameter; Student: " << _first_name << " " << _name;
    if (newLine)
    {
        cout << endl;
    }
}

Student::~Student()
{
    cout << "Destruktor Student: " << _first_name << " " << _name << endl;
}

// Klasse Employee
// Klasse Employee
class Employee
{
private:
    string _name;
    string _first_name;

public:
    // Default constructor
    Employee()
        : Employee("Mustermann", "Erika")
    {
        // This will match the output you want
       cout << "Standardkonstruktor Employee: " << _first_name << " " << _name << endl;
    }

    // Parameterized constructor
    Employee(string name, string first_name)
        : _name (name),
          _first_name (first_name)
    {
        // Change this to "Standardkonstruktor Employee" as per your requirement
        
         cout << "Parametrisierter Konstruktor Employee: " << _first_name << " " << _name << endl;
    }

    // Conversion constructor from Student to Employee
    Employee(Student &student)
        : _name (student.get_name()),
          _first_name(student.get_firstname())
    {
        cout << "Konvertierungskonstruktor Employee: " << _first_name << " " << _name << endl;
    }

    // Print methods
    void print()
    {
        cout << "print() ohne Parameter; Mitarbeiter: " << _first_name << " " << _name << endl;
    }

    void print(bool newLine)
    {
        cout << "print() mit Parameter; Mitarbeiter: " << _first_name << " " << _name;
        if (newLine)
        {
            cout << endl;
        }
    }

    // Destructor
    ~Employee()
    {
        cout << "Destruktor Employee: " << _first_name << " " << _name << endl;
    }
};

int main(int argc, char *argv[])
{
    Student stud_mustermann = Student("Mustermann", "Max");
    Employee empl_mustermann = Employee(stud_mustermann);
    Employee mit_default = Employee();
    stud_mustermann.print();
    stud_mustermann.print(true);
    empl_mustermann.print();
    mit_default.print();
    Student *p_stud_mustermann = nullptr;
    cout << "Block wird betreten" << endl;
    {
        p_stud_mustermann = new Student("Mustermann", "Markus");
        p_stud_mustermann->print(true);
    }
    cout << "Block wurde verlassen" << endl;
    delete p_stud_mustermann;
    return 0;
}
