#include <iostream>

class Fish
{
public:
    virtual void Swim()
    {
        std::cout << "Fish swims!" << std::endl;
    }
    virtual ~Fish() { } // base class always has virtual destructor
};

class Tuna: public Fish
{
public:
    void Swim() override
    {
        std::cout << "Tuna swims!" << std::endl;
    }

    void TunaStuff()
    {
        std::cout << "Tuna likes to dance" << std::endl;
    }

};

class Carp: public Fish
{
public:
    void Swim() override
    {
        std::cout << "Carp Swims!" << std::endl;
    }

    void CarpStuff()
    {
        std::cout << "Carp likes to feed from the bottom" << std::endl;
    }

};

void DetectFishType(Fish *fishPtr)
{
    
    Tuna* tunaPtr = dynamic_cast<Tuna*>(fishPtr);
    if (tunaPtr)
    {
        tunaPtr->TunaStuff();
    } 

    Carp* carpPtr = dynamic_cast<Carp*>(fishPtr);
    if (carpPtr)
    {
        carpPtr->CarpStuff();
    }

    fishPtr->Swim();
}

void ForceCastToTuna(Fish *fishPtr)
{
    Tuna *tunaPtr = static_cast<Tuna*>(fishPtr);
    tunaPtr->TunaStuff();
    tunaPtr->Swim();
}

int main()
{
    Carp carp;
    Tuna tuna;

    std::cout << "dynamic casting" << std::endl;
    std::cout << "Passing a carp:" << std::endl;
    DetectFishType(&carp);
    std::cout << std::endl << "Passing a tuna:" << std::endl;
    DetectFishType(&tuna);

    std::cout << std::endl << "---" << std::endl <<std::endl;

    std::cout << "Upcasting:" << std::endl;
    carp.Swim();
    Fish upcastedCarp = static_cast<Fish>(carp);
    upcastedCarp.Swim();
    Fish upcastedCarp2 = (Fish)carp;
    upcastedCarp2.Swim();

    std::cout << std::endl << "---" << std::endl <<std::endl;

    std::cout << "Static cast carp to tuna:" << std::endl;
    ForceCastToTuna(&carp);

    return 0;
}
