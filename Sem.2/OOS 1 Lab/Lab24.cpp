#include <iostream>
#include <list>
#include <string>
#include <map>
#include <exception>

using namespace std;

// Hier Exception implementieren
class Exception : public exception
{
    string nachricht;

public:
    Exception(const string &s) : nachricht(s) {}

    const char *what() const noexcept override
    {
        return nachricht.c_str();
    }
};

// Hier Interface implementieren
class ISubscriber
{
public:
    virtual void update(string s) = 0;
};

// Hier Klassen Customer und GoldCustomer implementieren
class Customer : public ISubscriber
{
    static int _id_generator;
    int id;

public:
    Customer() : id(++_id_generator) {}
    void update(const string nachricht) override
    {
        cout << "Customer " << id << ": neue Nachricht verfügbar --> " << nachricht << endl;
    }
};

class GoldCustomer : public ISubscriber
{
    static int _id_generator;
    int id;

public:
    GoldCustomer() : id(++_id_generator) {}
    void update(const string nachricht) override
    {
        cout << "GoldCustomer " << id << ": neue Nachricht verfügbar --> " << nachricht << endl;
    }
};

class Store
{
public:
    // Hier Methoden implementieren
    void subscribe(ISubscriber *s)
    {
        _subscribers.push_back(s);
    }
    void unsubscribe(ISubscriber *s)
    {
        _subscribers.remove(s);
    }
    void notify_subscribers(string nachricht)
    {
        for (ISubscriber *s : _subscribers)
        {
            s->update(nachricht);
        }
    }
    void deliver_products(string typ_product, int betrag)
    {
        cout << "Vorrätige Artikel vom Typ " << typ_product << ": " << _product_availability[typ_product] << endl;
        cout << "Ausgelieferte Artikel vom Typ " << typ_product << ": " << betrag << endl;
        _product_availability[typ_product] += betrag;
        cout << "Neuer Bestand: " << _product_availability[typ_product] << endl;
        // Prüfen, ob vor der Lieferung keine Produkte verfügbar waren
        if (_product_availability[typ_product] - betrag == 0)
        {
            notify_subscribers("Neue Artikel vom Typ " + typ_product + " verfügbar.");
        }
    }

    void sell_products(string typ_product, int betrag)
    {
        unsigned int amount = static_cast<unsigned int>(betrag);
        if (_product_availability[typ_product] < amount)
        {
            throw Exception("Es sind " + to_string(_product_availability[typ_product]) + " Artikel vom Typ " + typ_product + " verfügbar. Es können nicht " + to_string(amount) + " Artikel verkauft werden.");
        }
        cout << "Vorrätige Artikel vom Typ " << typ_product << ": " << _product_availability[typ_product] << endl;
        cout << "Verkaufte Artikel vom Typ " << typ_product << ": " << betrag << endl;
        _product_availability[typ_product] -= betrag;
        cout << "Neuer Bestand: " << _product_availability[typ_product] << endl;

        if (_product_availability[typ_product] == 0)
        {
            notify_subscribers("Artikel vom Typ " + typ_product + " nicht mehr verfügbar");
        }
    }

private:
    list<ISubscriber *> _subscribers;
    map<string, unsigned int> _product_availability{{"iPhone", 0}, {"Galaxy", 5}};
};

int Customer::_id_generator = 100;
int GoldCustomer::_id_generator = 0;

void manage_store()
{
    try
    {
        Store *store = new Store;
        ISubscriber *customer_1 = new Customer();
        store->subscribe(customer_1);
        ISubscriber *customer_2 = new GoldCustomer();
        store->subscribe(customer_2);
        ISubscriber *customer_3 = new GoldCustomer();
        store->subscribe(customer_3);
        store->deliver_products("iPhone", 5);
        store->unsubscribe(customer_3);
        store->sell_products("iPhone", 3);
        ISubscriber *customer_4 = new Customer();
        store->subscribe(customer_4);
        store->deliver_products("iPhone", 5);
        store->sell_products("iPhone", 7);
        store->unsubscribe(customer_1);
        ISubscriber *customer_5 = new GoldCustomer();
        store->subscribe(customer_5);
        store->deliver_products("iPhone", 15);
        store->sell_products("Galaxy", 8);
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }
    catch (...)
    {
        cout << "Ein unbekannter Fehler ist aufgetreten." << endl;
    }
}

int main(int argc, char *argv[])
{
    manage_store();
    return 0;
}