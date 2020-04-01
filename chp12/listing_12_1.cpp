#include <iostream>
#include <sstream>
#include <string>

class Date
{
private:
    int day, month, year;
    std::string dateString;

public:
    Date(int m, int d, int y)
        : month(m), day(d), year(y) { };
    
    Date& operator++ () // preifx
    {
        ++ day;
        return *this;
    }

    Date operator++ (int) // postfix
    {
        Date copy(*this);
        ++ day;
        return copy;
    }

    Date& operator-- ()
    {
        -- day;
        return *this;
    }

    Date operator-- (int)
    {
        Date copy(*this);
        -- day;
        return copy;
    }

    operator const char*() // conversion operator
    {
        std::ostringstream formattedDate;
        formattedDate << month << "/" << day << "/" << year;
        dateString = formattedDate.str();
        return dateString.c_str();

    }

};

int main()
{
    Date birthday (11, 19, 1988);

    std::cout << "My birthday is on " << birthday << std::endl;
    birthday++;
    ++birthday;
    std::cout << "Two days after my birthday is " << birthday << std::endl;

    std::cout << "We can also now convert Dates directly to strings: " << std::string(Date(1,1,1)) << std::endl;

    return 0;

    
}