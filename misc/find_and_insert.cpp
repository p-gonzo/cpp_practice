#include <algorithm>
#include <iostream>
#include <vector>

struct A
{
    A(int it, char ch): i(it), c(ch) { };
    int i;
    char c;
};

int main()
{
    std::vector<A> as { A(1, 'a'), A(2, 'b'), A(3, 'c'), A(4, 'b') };

    auto idx = std::find_if(as.begin(), as.end(), [](A a) { return a.i == 1; });

    std::vector<char> chrs { 'b', 'c' };

    chrs.insert(chrs.begin(), idx->c);

    for (auto itr = chrs.begin(); itr < chrs.end(); ++itr)
    {
        std::cout << *itr << std::endl;
    }

    return 0;
}