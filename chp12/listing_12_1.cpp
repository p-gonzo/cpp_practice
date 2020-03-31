#include <iostream>
#include <string>
using namespace std;

class Hi
{
public:
  void Print()
  {
    cout << "this is a location: " << this << endl;
    cout << "(*this) dereferences: " (*this) << endl;
  }

  friend ostream& operator<<(ostream& os, Hi& hi)
  {
    os << "Hello!";
    return os;
  }

};

int main()
{
  Hi hi;
  hi.Print();
  return 0;
}