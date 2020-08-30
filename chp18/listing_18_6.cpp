#include <algorithm>
#include <list>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

template <typename T>
void displayContents(const T& container)
{
    for (auto item: container) { std::cout << item << std::endl; }
    std::cout << std::endl;
}

class Person
{
public:
    Person(unsigned int a, std::string b): age(a), name(b) { };

    operator const char*()
    {
        std::ostringstream formattedPerson;
        formattedPerson << "name: " << name << " age: " << age;
        stringRepresentation = formattedPerson.str();
        return stringRepresentation.c_str();
    }

    unsigned int age;
    std::string name;

private:
    std::string stringRepresentation;
};

int main()
{
    std::list<Person> peeps{ Person(51, "Jim"), Person(31, "Phil"), Person(29, "Alex"), Person(17, "Finn") };
    displayContents(peeps);
    peeps.sort([](const Person& lhs, const Person& rhs) { return (rhs.age > lhs.age); });
    displayContents(peeps);
    std::vector<Person> moarPeeps(peeps.cbegin(), peeps.cend());
    displayContents(moarPeeps);
    std::sort(moarPeeps.begin(), moarPeeps.end(), [](const Person& lhs, const Person& rhs) { return (rhs.name > lhs.name); });
    displayContents(moarPeeps);
    return 0;
}