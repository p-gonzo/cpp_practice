#include <iostream>
#include <list>
#include <string>

template <typename T>
void displayAsContents (const T &container)
{
    for (auto elem: container)
        std::cout << elem << std::endl;
}

struct ContactItem
{
    std::string name;
    std::string phone;
    std::string displayAs;

    ContactItem(const std::string &n, const std::string &p):
        name(n), phone(p), displayAs(n + ": " + p) { }

    operator const char*() { return displayAs.c_str(); }
    bool operator== (const ContactItem &other) const { return name == other.name; }
    bool operator< (const ContactItem &other) const { return name < other.name; }
    bool operator> (const ContactItem &other) const { return name > other.name; }
};

int main()
{
    std::list<ContactItem> myContacts {ContactItem("Phil", "555-5555"), ContactItem("Adam", "123-4567")};
    displayAsContents(myContacts);
    return 0;
}