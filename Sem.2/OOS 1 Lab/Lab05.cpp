
#include <iostream>
using namespace std;

// hier die Klasse Punkt implementieren
class Point
{
    double x;
    double y;

public:
    void set_x(double x_v)
    {

        x = x_v;
    }

    void set_y(double y_v)
    {

        y = y_v;
    }

    double get_x()
    {
        return x;
    }

    double get_y()
    {
        return y;
    }

    void print()
    {

        cout << "print-Methode:\n";
        cout << "X = " << x << '\n';
        cout << "Y = " << y << '\n';
    }
};

int main(int argc, char *argv[])
{
    Point p;
    p.set_x(1);
    p.set_y(10.5);
    p.print();
    p.set_x(5);
    cout << "X ohne print(): " << p.get_x() << endl;
    cout << "Y ohne print(): " << p.get_y() << endl;
    return 0;
}
