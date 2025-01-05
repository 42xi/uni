#include <iostream>
#include <array>
#include <vector>
#include <string>

using namespace std;

class Meal
{
    string _name_of_the_meal;
    vector<string> _toppings;

public:
    Meal(string name) : _name_of_the_meal(name) {}

    virtual void add_topping(string _name_of_the_topping)
    {
        _toppings.push_back(_name_of_the_topping);
    }
    string get_name_meal()
    {
        return _name_of_the_meal;
    }
    virtual void prepare() // print methode
    {
        for (string top : _toppings)
        {
            cout << "- " << top << endl;
        }
    }
    virtual Meal *clone() const = 0;
};

class Pizza : public Meal
{
    const string _name_of_the_pizza;

public:
    Pizza(string p) : Meal(p) {}
    void prepare() override
    {
        cout << "Pizza " << get_name_meal() << ". Pizzaboden, belegt mit:" << endl;
        Meal::prepare();
    }
    Meal *clone() const override { return new Pizza(*this); }
};

class Burger : public Meal
{
    const string _name_of_the_burger;

public:
    Burger(string b) : Meal(b) {}
    void prepare() override
    {
        cout << this->get_name_meal() << ". Brötchen mit:" << endl;
        Meal::prepare();
    }
    Meal *clone() const override { return new Burger(*this); }
};

int main(int argc, char *argv[])
{
    Pizza *mista = new Pizza("Mista");
    mista->add_topping("Salami");
    mista->add_topping("Pilzen");
    Meal *hawaii = new Pizza("Hawaii");
    hawaii->add_topping("Schinken");
    hawaii->add_topping("Ananas");
    Burger *hamburger = new Burger("Hamburger");
    hamburger->add_topping("Hackfleisch");
    Meal *cheesburger = new Burger("Cheesburger");
    cheesburger->add_topping("Hackfleisch");
    cheesburger->add_topping("Käse");
    array<Meal *, 4> menu = {mista, hawaii, hamburger, cheesburger};
    for (Meal *g : menu)
    {
        g->prepare(); //*[1]
    }
    return 0;
}
