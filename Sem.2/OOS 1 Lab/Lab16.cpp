#include <iostream>
#include <vector>
using namespace std;

class Point
{
    double _x, _y; // Koordinaten des Punktes

public:
    // Konstruktor mit Parametern (Standardwerte sind 0.0)
    Point(double x = 0.0, double y = 0.0) : _x(x), _y(y) {}

    // Verschiebt einen Punkt
    void move(double dx, double dy)
    {
        _x += dx;
        _y += dy;
    }

    // Gibt den Punkt auf der Konsole aus
    void print(bool nl = true)
    {
        cout << "(" << _x << ", " << _y << ")";
        if (nl)
        {
            cout << endl;
        }
    }
};

class Polygonline
{
    vector<Point> _points; // Punkte der Polygonlinie

public:
    // Standard-Konstruktor (leere Polygonlinie)
    Polygonline() {}

    // Konstruktor mit einem Punkt
    Polygonline(Point &p)
    {
        _points.push_back(p);
    }

    // Gibt die Punkte der Polygonlinie auf der Konsole aus
    void print(bool nl = true)
    {
        cout << "|";
        for (size_t i = 0; i < _points.size(); ++i)
        {
            _points[i].print(false);
            if (i < _points.size() - 1)
            {
                cout << " - ";
            }
        }
        cout << "|";
        if (nl)
        {
            cout << endl;
        }
    }

    // Fügt einen Punkt zur Polygonlinie hinzu
    Polygonline &add_point(Point p)
    {
        _points.push_back(p);
        return *this;
    }

    // Fügt eine andere Polygonlinie ans Ende an
    void append_polygonline(Polygonline &pl)
    {
        for (const Point &p : pl._points)
        {
            _points.push_back(p);
        }
    }

    // Verschiebt alle Punkte der Polygonlinie
    void move(double dx, double dy)
    {
        for (Point &p : _points)
        {
            p.move(dx, dy);
        }
    }
};

int main()
{
    Point p1(1, 1), p2(2, 2), p3(3, 3), p4(4, 4), p5(5, 5);
    Polygonline l1;
    Polygonline l2(p3);

    cout << "Ausgabe 1:" << endl;
    l1.print();
    l2.print();

    l1.add_point(p1).add_point(p2);
    l2.add_point(p4).add_point(p5);

    cout << "Ausgabe 2:" << endl;
    l1.print();
    l2.print();

    p2.move(0.5, 0.5);

    cout << "Ausgabe 3:" << endl;
    p2.print();
    l1.print();
    l2.print();

    l1.append_polygonline(l2);

    cout << "Ausgabe 4:" << endl;
    l1.print();
    l2.print();

    l1.move(0, 0.5);

    cout << "Ausgabe 5:" << endl;
    l1.print();
    l2.print();

    return 0;
}
