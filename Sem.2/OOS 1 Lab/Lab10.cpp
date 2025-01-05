#include <string>
#include <iostream>
using namespace std;

class Person
{
protected:
	string _name;
	int _check_out_duration;

public:
	// Basiskonstruktor für Person mit optionaler Ausleihdauer
	Person(string name, int check_out_duration = 0);
	int get_check_out_duration() const;
	void print() const;
};

// Implementierung des Konstruktors und der Methoden

Person::Person(string name, int check_out_duration)
	: _name(name), _check_out_duration(check_out_duration) {}

int Person::get_check_out_duration() const
{
	return _check_out_duration;
}

void Person::print() const
{
	cout << _name;
}

// Lecturer-Klasse, die von Person erbt
class Lecturer : public Person
{
	int _examiner_id;

public:
	Lecturer(string name, int examiner_id);
	void print() const;
};

// Konstruktor und Methoden für Lecturer

Lecturer::Lecturer(string name, int examiner_id)
	: Person(name, 90), _examiner_id(examiner_id) {} // Ausleihdauer für Dozenten ist 90 Tage

void Lecturer::print() const
{
	Person::print();
	cout << ", Prüfernummer " << _examiner_id << endl;
}

// Student-Klasse, die von Person erbt
class Student : public Person
{
	int _matriculation_number;

public:
	Student(string name, int matriculation_number);
	void print() const;
};

// Konstruktor und Methoden für Student

Student::Student(string name, int matriculation_number)
	: Person(name, 30), _matriculation_number(matriculation_number) {} // Ausleihdauer für Studenten ist 30 Tage

void Student::print() const
{
	Person::print();
	cout << ", Matrikelnummer " << _matriculation_number << endl;
}

int main(int argc, char *argv[])
{
	Student smith = Student("smith", 12345678);
	Lecturer miller = Lecturer("miller", 98);
	smith.print();
	cout << "Ausleihdauer: " << smith.get_check_out_duration() << " Tage(e)" << endl;
	miller.print();
	cout << "Ausleihdauer: " << miller.get_check_out_duration() << " Tage(e)" << endl;
}