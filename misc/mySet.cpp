#include <iostream>

template <typename T>
class mySet
{
public:
    void insert(const T &val)
    {
        insert(*this, val);
    }
    bool contains(const T &val) const
    {
        return contains(*this, val);
    }
private:
    T *val = nullptr;
    mySet<T> *left = nullptr;
    mySet<T> *right = nullptr;

    void insert(mySet<T> &node, const T &val)
    {
        if (node.val == nullptr || *node.val == val)
        {
            node.val = new T(val);
            return;
        }
        else if (val < *node.val)
        {
            if (node.left == nullptr)
            {
                node.left = new mySet<T>;
            }
            return insert(*node.left, val);
        }
        else if (val > *node.val)
        {
            if (node.right == nullptr)
            {
                node.right = new mySet<T>;
            }
            return insert(*node.right, val);
        }
    }

    bool contains(const mySet<T> &node, const T &val) const
    {
        if (*node.val == val)
        {
            return true;
        }
        else if (val < *node.val)
        {
            if (node.left == nullptr)
            {
                return false;
            }
            else
            {
                return contains(*node.left, val);
            }
        }
        else /*val > *node.val */
        {
            if (node.right == nullptr)
            {
                return false;
            }
            else 
            {
                return contains(*node.right, val);
            }
        }
    }
};

int main()
{
    mySet<int> set;
    set.insert(5);
    set.insert(4);
    set.insert(1);
    set.insert(100);

    std::cout << "set contains the number 5: " << set.contains(5) << std::endl;
    std::cout << "set contains the number 4: " << set.contains(4) << std::endl;
    std::cout << "set contains the number 1: " << set.contains(1) << std::endl;
    std::cout << "set contains the number 3: " << set.contains(3) << std::endl;
    std::cout << "set contains the number 6: " << set.contains(6) << std::endl;
    std::cout << "set contains the number 100: " << set.contains(100) << std::endl;
    return 0;
}