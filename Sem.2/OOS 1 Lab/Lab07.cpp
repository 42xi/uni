#include <iostream>
#include <string>

using namespace std;

class Customer
{
    static int _s_count;
    static int _s_id_generator;
    string _name;
    string _location;
    int _age;
    double _business_done;
    int _transaction_count = 0;
    int _id;

public:
    Customer(string name = "", int age = 0, string location = "")
        : _name(name), _location(location), _age(age), _id(++_s_id_generator)
    {
        ++_s_count;
    }

    ~Customer()
    {
        --_s_count;
    }

    void do_business(double amount)
    {
        _business_done += amount;
        ++_transaction_count;
    }

    static int get_s_count()
    {
        return _s_count;
    }

    void print()
    {
        cout << "Kunde " << _name << " aus " << _location
             << " (ID = " << _id << ", " << _age << " Jahre) hatte "
             << _transaction_count << " Transaktion(en) und "
             << _business_done << " Euro Umsatz" << endl;
    }
};

int Customer::_s_count = 0;
int Customer::_s_id_generator = 0;

int main(int argc, char *argv[])
{
    Customer peter = Customer("Peter", 17, "Stuttgart");
    Customer simon = Customer("Simon", 23, "Heilbronn");
    peter.~Customer();
    Customer micheal = Customer("Michael", 21, "Karlsruhe");
    Customer claudia = Customer("Claudia", 30, "Nagold");
    std::cout << "Anzahl Kunden: " << Customer::get_s_count() << std::endl;
    simon.do_business(230);
    simon.do_business(400);
    claudia.do_business(1000);
    micheal.do_business(199);
    simon.do_business(3.99);
    simon.print();
    micheal.print();
    claudia.print();
    claudia.~Customer();
    std::cout << "Anzahl Kunden: " << Customer::get_s_count() << std::endl;
    return 0;
}