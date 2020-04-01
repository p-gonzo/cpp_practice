#include <iostream>
#include <memory> //needed for unique_ptr
#include <sstream>

class Date
{
private:
    int day, month, year;
    std::string dateString;

public:
    Date(int m, int d, int y) : month(m), day(d), year(y) { };
    
    operator const char*()
    {
        std::ostringstream formattedDate;
        formattedDate << month << "/" << day << "/" << year;
        dateString = formattedDate.str();
        return dateString.c_str();
    }
};

int main()
{
    std::unique_ptr<int> smartIntPtr(new int);
    *smartIntPtr = 42;
    std::cout << "Integer value is: " << *smartIntPtr << std::endl;

    std::unique_ptr<Date> smartDatePtr(new Date(4, 1, 2020));
    std::cout << "Date contained in smart pointer is: " << *    smartDatePtr << std::endl;

    return 0;
}