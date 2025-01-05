#include <iostream>
using namespace std;

/* hier */

#include <iostream>
import Manager;
import Worker;

int main()
{
    Manager m("Gerd", "Mayer", 1000.00);
    m.print();
    cout << "Gehalt: " << m.get_income() << endl
         << endl;
    Worker w("Idris", "Wahib", 15.00, 40);
    w.print();
    cout << "Lohn: " << w.get_income() << endl;
    return 0;
}