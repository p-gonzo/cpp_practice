#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

#define THREADED 1 /*Comment me out to see non-threaded code*/

void addOne(int &num)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    #ifdef THREADED
    static std::mutex m; // Our mutex must be static to work accross threads
    std::lock_guard<std::mutex> lock(m);
    #endif
    ++num;
}

int main()
{
    int myNum {0};
    std::vector<std::thread> threads;
    for (int i = 0; i < 1000; ++i)
    {
        threads.push_back(std::thread(addOne, std::ref(myNum)));
    }
    for (auto &thread: threads)
    {
        thread.join();
    }
    std::cout << myNum << std::endl;
    return 0;
}