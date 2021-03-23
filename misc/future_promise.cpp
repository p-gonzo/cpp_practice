#include <chrono>
#include <cmath>
#include <functional>
#include <future>
#include <iostream>
#include <thread>

int outerFunc(int x, int y) { return std::pow(x,y); }

void PackagedTaskInLambda()
{
    std::packaged_task<int(int,int)> task([](int a, int b) {
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        return std::pow(a,b);
    });
    std::future<int> result = task.get_future();
    task(2,16);
    int val = result.get(); // blocking call
    std::cout << "PackagedTaskInLambda:\t" << val << '\n';
}

void PromiseAndFutre()
{
    auto promise = std::promise<std::string>();
    
    auto producer = std::thread([&promise]{
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        promise.set_value("Hello World!");
    });

    auto future = promise.get_future();
    auto consumer = std::thread([&future] {
        std::string val = future.get(); // blocking call
        std::cout << val << '\n';
    });

    producer.join();
    consumer.join();
}

int main()
{
    PackagedTaskInLambda();
    PromiseAndFutre();
}