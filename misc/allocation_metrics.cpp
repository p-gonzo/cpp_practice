#include <iostream>
#include <memory>
#include <string>


class AllocationMetrics
{
private:
    AllocationMetrics() { };
    AllocationMetrics(const AllocationMetrics&);
    const AllocationMetrics& operator=(const AllocationMetrics&);

    
public:
    static AllocationMetrics& GetInstance()
    {
        static AllocationMetrics onlyInstance;
        return onlyInstance;
    }

    void printMemoryUsage()
    {
        std::cout
            << "Allocated: " << totalAllocated
            << " Freed: " << totalFreed
            << " Usage: " << totalAllocated - totalFreed
            << std::endl;
    }
    
    uint64_t totalAllocated {0};
    uint64_t totalFreed {0};
    
};

void* operator new(size_t size)
{
    auto& AM = AllocationMetrics::GetInstance();
    AM.totalAllocated += size;
    return malloc(size);
}

void operator delete(void* memory, size_t size)
{
    auto& AM = AllocationMetrics::GetInstance();
    AM.totalFreed += size;
    free(memory);
}

/*************************************************************/


struct Object
{
    int a, b, c;
};

int main(int argc, char** argv)
{
    auto& AM = AllocationMetrics::GetInstance();

    AM.printMemoryUsage();
    {
        auto obj = std::make_unique<Object>();
        AM.printMemoryUsage();
    }
    AM.printMemoryUsage();
}