#include <iostream>
#include <sstream>
#include <string>

class Date
{
private:
    int day, month, year;
    std::string dateString;

public:
    Date(int m, int d, int y) : month(m), day(d), year(y) { };

    Date operator+ (int val)
    {
        return Date(month, day + val, year);
    }

    Date operator- (int val)
    {
        return Date(month, day - val, year);
    }

    operator const char *()
    {
        std::ostringstream formattedDate;
        formattedDate << month << "/" << day << "/" << year;
        dateString = formattedDate.str();
        return dateString.c_str();
    }

};

int main()
{
    Date holiday(12, 25, 2016);
    std::cout << "Holiday is on: " << holiday << std::endl;

    Date previousHoliday(holiday - 19);
    std:: cout << "Previous holiday is on: " << previousHoliday << std::endl;

    Date nextHoliday(holiday + 6);
    std::cout << "Next holiday is on: " << nextHoliday << std::endl;

    return 0;
}