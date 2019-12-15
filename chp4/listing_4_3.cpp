#include <iostream>

int main()
{
    char threeRowsThreeColumns [3][3] = {
        {'A', 'B', 'C'},
        {'D', 'E', 'F'},
        {'G', 'H', 'I'}
    };

    // TODO - Why do I have to refer to the row by reference in the for loop here?
    for (char (&row)[3]: threeRowsThreeColumns){
        for (char item: row) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}