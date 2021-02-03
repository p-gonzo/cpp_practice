#include <iostream>
#include <cmath>
#include <thread>
#include <future>
#include <functional>

int outerFunc(int x, int y) { return std::pow(x,y); }

void task_lambda()
{
    std::packaged_task<int(int,int)> task([](int a, int b) { return std::pow(a,b); });
    std::future<int> result = task.get_future();
    task(2,16);
    std::cout << "task_lambda:\t" << result.get() << '\n';
}

int main()
{
    task_lambda();
}