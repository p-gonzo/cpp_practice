#include <iostream>
#include <sstream>
#include <string>

class Date
{
private:
    int day, month, year;

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
        return formattedDate.str().c_str();

    }

};

int main()
{
    Date birthday (11, 19, 1988);

    std::string birthdayString(birthday);
    
    std::cout << "Birthday String: " << birthdayString << std::endl;

    std::cout << "My birthday is on " << birthday << std::endl;

    birthday++;
    ++birthday;

    std::cout << "Two days after my birthday is " << birthday << std::endl;

    return 0;

    
}