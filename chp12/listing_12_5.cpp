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

    operator const char*()
    {
        std::ostringstream formattedDate;
        formattedDate << month << "/" << day << "/" << year;
        dateString = formattedDate.str();
        return dateString.c_str();
    }

    void operator+= (int daysToAdd)
    {
        day += daysToAdd;
    }

    void operator+= (Date &dateToAdd)
    {
        day += dateToAdd.day;
        month += dateToAdd.month;
        year += dateToAdd.year;
    }

    void operator-= (int daysToSubtract)
    {
        day-= daysToSubtract;
    }

    void operator-= (Date &dateToSubtract)
    {
        day -= dateToSubtract.day;
        month -= dateToSubtract.month;
        year -= dateToSubtract.year;
    }
};

int main()
{
    Date holiday(12, 25, 2020);
    std::cout << "Holiday is on: " << holiday << std::endl;

    holiday -= 19;
    std::cout << "Holiday -= 19 gives us: " << holiday << std::endl;

    holiday += 25;
    std::cout << "Holiday += 25 gives us: " << holiday << std::endl;

    Date offset(-1, -12, 0);
    holiday += offset;
    std::cout << "Holiday += Date(-1, -6, 0) gives us: " << holiday << std::endl; 

    return 0;
}