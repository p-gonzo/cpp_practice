#include <iostream>
#include <string>
using namespace std;

class President
{

private: // TODO - is making these private is similar to `=delete`?
    President() {}; // private default constructor
    President(const President&); // private copy constructor
    const President& operator=(const President&); // private assignment operator

    string name;

public:
    static President& GetInstance() // because GetInstance is a static member, it acts like a global function
    {
        // Static objects are constructed only once, so only one President will ever be constructed
        static President onlyInstance;
        return onlyInstance;
    }

    string GetName () { return name; }
    void SetName(string _name) { name = _name; }
};

int main()
{
    President& onlyPresident = President::GetInstance();
    onlyPresident.SetName("Abraham Lincoln");

    // Uncomment lines to see how compile failures prohibit duplicates
    // President second; // cannot access constructor
    // President *third = new President(); // cannot access constructor
    // President fourth = onlyPresident; // cannot access copy constructor
    // onlyPresident = President::GetInstance(); // cannot access operator=

    cout << "The name of the President is: " << President::GetInstance().GetName() << endl;
    return 0;
}