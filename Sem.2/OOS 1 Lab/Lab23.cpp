#include <iostream>
#include <vector>
using namespace std;

// Interface IComponent
class IComponent
{
public:
    virtual int getPrice() = 0;
    virtual void add(IComponent *component) {}
};

// Class Product
class Product : public IComponent
{
private:
    int price;

public:
    Product(int price)
    {
        this->price = price;
    }
    int getPrice() override
    {
        return price;
    }
};

// Class Box
class Box : public IComponent
{
public:
    vector<IComponent *> components;
    int getPrice() override
    {
        int price = 0;
        for (size_t i = 0; i < components.size(); i++)
        {
            price += components[i]->getPrice();
        }
        return price;
    }
    void add(IComponent *component) override
    {
        components.push_back(component);
    }
};

void ClientCode(IComponent *component)
{
    cout << "Preis: " << component->getPrice() << endl;
}

int main()
{
    cout << "Preisermittlung für ein einfaches Produkt: " << endl;
    IComponent *product = new Product(10);
    ClientCode(product);
    cout << endl;

    cout << "Preisermittlung für eine verschachtelte Box: " << endl;
    IComponent *outer_box = new Box;
    IComponent *inner_box_1 = new Box;
    IComponent *product_1 = new Product(10);
    IComponent *product_2 = new Product(5);
    IComponent *product_3 = new Product(4);
    inner_box_1->add(product_1);
    inner_box_1->add(product_2);
    IComponent *inner_box_2 = new Box;
    inner_box_2->add(product_3);
    outer_box->add(inner_box_1);
    outer_box->add(inner_box_2);
    ClientCode(outer_box);
    cout << endl;

    cout << "Preisermittlung für eine erweiterte verschachtelte Box: " << endl;
    IComponent *product_4 = new Product(7);
    inner_box_2->add(product_4);
    ClientCode(outer_box);
    cout << endl;

    return 0;
}
