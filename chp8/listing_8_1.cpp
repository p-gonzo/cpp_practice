#include <iostream>
using namespace std;

int main()
{
    int age {30};
    const double Pi {3.1416};

    cout << "Integer age is located at addres: "<< &age << endl;
    cout << "Double Pi is located at address: " << &Pi << endl;

    return 0;
}