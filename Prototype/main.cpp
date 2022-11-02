//
// Created by Cleonia on 21.09.2022.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Warrior
{
public:
    virtual Warrior* clone() = 0;
    virtual void info() = 0;
    virtual ~Warrior() = default;
};


// Производные классы различных родов войск
class Infantryman: public Warrior
{
    friend class PrototypeFactory;
public:
    Warrior* clone() override {
        return new Infantryman( *this);
    }

    void info() override {
        cout << "Infantryman" << endl;
    }
private:
    Infantryman() = default;
};

class Archer: public Warrior
{
    friend class PrototypeFactory;
public:
    Warrior* clone() override {
        return new Archer( *this);
    }

    void info() override {
        cout << "Archer" << endl;
    }
private:
    Archer() = default;
};

class Horseman: public Warrior
{
    friend class PrototypeFactory;
public:
    Warrior* clone() override {
        return new Horseman( *this);
    }

    void info() override {
        cout << "Horseman" << endl;
    }
private:
    Horseman() = default;
};


// Фабрика для создания боевых единиц всех родов войск
class PrototypeFactory
{
public:
    Warrior* createInfantrman() {
        static Infantryman prototype;
        return prototype.clone();
    }
    Warrior* createArcher() {
        static Archer prototype;
        return prototype.clone();
    }
    Warrior* createHorseman() {
        static Horseman prototype;
        return prototype.clone();
    }
};


int main()
{
    PrototypeFactory factory;
    vector<Warrior*> v;
    v.push_back( factory.createInfantrman());
    v.push_back( factory.createArcher());
    v.push_back( factory.createHorseman());

    for(auto & i : v)
        i->info();
}