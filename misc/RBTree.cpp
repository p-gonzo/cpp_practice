#include <iostream>

template <typename T>
class RBTree
{
public:
void insert(const T &val)
{
    insert(this, val);
}

bool contains(const T &val)
{
    return true; // TODO - implement me
}
    RBTree() = default;
private:
    RBTree(RBTree *p): parent(p) { };
    void insert(RBTree *node, const T& val)
    {
        if (node->val == nullptr || *(node->val) == val)
        {
            node->val = new T(val);
            reballance(node);
            return;
        }
        if (val < *(node->val))
        {
            if (node->left == nullptr) {node->left = new RBTree<T>(node);}
            return insert(node->left, val);
        }
        if (val > *(node->val))
        {
            if (node->right == nullptr) {node->right = new RBTree<T>(node);}
            return insert(node->right, val);
        }
    }

    void reballance(RBTree *node)
    {
        // root
        if (node->left == nullptr && node->right == nullptr)
        {
            node->color = 'b';
        }
    }

    T *val = nullptr;
    RBTree *left = nullptr;
    RBTree *right = nullptr;
    RBTree *parent = nullptr;
    char color = 'r';
};

int main()
{
    RBTree<int> tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
}