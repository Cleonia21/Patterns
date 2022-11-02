//
// Created by Cleonia on 02.11.2022.
//

#include <string>
#include <iostream>

//Components

class Salt
{
    int gram = 0;
public:
    void getInfo() {
        std::cout << "salt " << gram << " gram\n";
    }

    Salt& operator=(int a) {
        gram = a;
        return *this;
    }
};

class Flour
{
    int gram = 0;
public:
    void getInfo() {
        std::cout << "flour " << gram << " gram\n";
    }

    Flour& operator=(int a) {
        gram = a;
        return *this;
    }
};

class Water
{
    int gram = 0;
public:
    void getInfo() {
        std::cout << "water " << gram << " gram\n";
    }

    Water& operator=(int a) {
        gram = a;
        return *this;
    }
};

//Product

class Bread
{
public:
    Salt salt;
    Flour flour;
    Water water;

    void info() {
        std::cout << "bread is made from" << std::endl;
        salt.getInfo();
        flour.getInfo();
        water.getInfo();
    }
};

//Abstract builder

class Builder
{
protected:
    Bread *bread = new Bread;

public:
    virtual void addSalt() {}
    virtual void addFlour() {}
    virtual void addWater() {}
    virtual Bread* getBread() { return bread; }

    virtual ~Builder() = default;
};

//Concrete builders

class BlackBreadBuilder : public Builder
{
public:
    void addSalt() override {
        bread->salt = 10;
    }

    void addFlour() override {
        bread->flour = 100;
    }

    void addWater() override {
        bread->water = 50;
    }
};

class WhiteBreadBuilder : public Builder
{
public:
    void addSalt() override {
        bread->salt = 5;
    }

    void addFlour() override {
        bread->flour = 200;
    }

    void addWater() override {
        bread->water = 50;
    }
};

class DietaryBreadBuilder : public Builder
{
public:
    void addFlour() override {
        bread->flour = 100;
    }

    void addWater() override {
        bread->water = 50;
    }
};

// Director

class Director
{
public:
    Bread* makeBread(Builder &builder) {
        builder.addSalt();
        builder.addFlour();
        builder.addWater();
        return builder.getBread();
    }
};

int main() {
    Director director;
    BlackBreadBuilder blackBuilder;
    WhiteBreadBuilder whiteBuilder;
    DietaryBreadBuilder dietaryBuilder;

    Bread* blackBread = director.makeBread(blackBuilder);
    Bread* whiteBread = director.makeBread(whiteBuilder);
    Bread* dietaryBread = director.makeBread(dietaryBuilder);

    std::cout << "Black ";
    blackBread->info();
    std::cout << "White ";
    whiteBread->info();
    std::cout << "Dietary ";
    dietaryBread->info();
}
