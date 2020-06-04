#include <iostream>
#include <tuple>
#include <string>

template <typename TupleType>
void DisplayTupleInfo (const TupleType& tup)
{
    const int numMembers = std::tuple_size<TupleType>::value;
    std::cout << "Number of elements in tuple is: " << numMembers << std::endl;
    std::cout << "The last element's value is: " << std::get<numMembers - 1>(tup) << std::endl;
}

template <typename TupleType>
void DisplaySingleTupleEntry (const TupleType &tup, const int &i)
{
    // this wont work b/c in order to maintain type safety, the template type must be known at compile time
    std::cout << std::get<i>(tup) << std::endl;
}

template <typename TupleType>
void DisplayFirstTupleEntry (const TupleType &tup)
{
    std::cout << std::get<0>(tup) << std::endl;
}



int main()
{
    std::tuple<int, char, std::string> tup1(std::make_tuple(101, 's', "Hello Tuple!"));
    DisplayTupleInfo(tup1);

    auto tup2(std::make_tuple(3.14, false));
    DisplayTupleInfo(tup2);

    auto concatTup(std::tuple_cat(tup2, tup1));
    DisplayTupleInfo(concatTup);

    double pi;
    std::string sentence;

    std::tie(pi, std::ignore, std::ignore, std::ignore, sentence) = concatTup;
    std::cout << "Unpacked! Pi: " << pi << " and sentence: " << sentence << std::endl;
    return 0;
}