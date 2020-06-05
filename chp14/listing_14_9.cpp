template<typename T>
class AllButInt
{
public:
    AllButInt(const T& val): _val(val)
    {
        static_assert(sizeof(T) != sizeof(int), "Error, cannot instantiate AllButInt with int.");
    }

private:
    T _val;
};

int main()
{
    // AllButInt<int> containerA(1); // Failure
    AllButInt<char> containerB('c'); // Success
    return 0;
}