#include <iostream>
#include <sstream>
#include <string>

class Date
{
private:
    int day, month, year;
    std::string dateString;

public:
    Date(int m, int d, int y): month(m), day(d), year(y) { };

    operator const char * ()
    {
        std::ostringstream formattedDate;
        formattedDate << month << "/" << day << "/" << year;
        dateString = formattedDate.str();
        return dateString.c_str();
    }

    explicit operator const int ()
    {
        return std::stoi(std::to_string(day) + std::to_string(month) + std::to_string(year));
    }

    bool operator== (const Date& other)
    {
        return day == other.day && month == other.month && year == other.year;
    }

    bool operator!= (const Date& other)
    {
        return !operator==(other);
    }
};

int main()
{
    Date myBirthday(11, 19, 1988);
    std::cout << "My birthday is on: " << myBirthday << std::endl;
    std::cout << "As an integer it is represented by: " << (int)myBirthday << std::endl;

    std::cout << "My birthday is not on Christmas: " << (myBirthday == Date(12, 25, 1988)) << (myBirthday != Date(12, 25, 1988)) << std::endl;
    std::cout << "But it is on the day I was born: " << (myBirthday == Date(11, 19, 1988)) << (myBirthday != Date(11, 19, 1988)) << std::endl;
    
    return 0;
}