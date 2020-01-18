#include <iostream>

class A 
{
private:
  int val {0};
public:
  A(int _val): val(_val) { }
  void log()
  {
    std::cout << "The value is: " << val << std::endl;
  }
};

class B
{
protected:
  int val {0};
public:
  B(int _val): val(_val) { }
  virtual void log(int num)
  {
    std::cout << "The value is: " << val + num << std::endl;
  }
};

class C: public B
{
public:
  C(int _val): B(_val) { }
  void log(int num) override
  {
    std::cout << "Override Func - the value is: " << val + num << std::endl;
  }
};

int main()
{
  A* a = new A(5);
  a->log();
  std::cout << "The size of a is: " << sizeof(a) << std::endl;
  delete a;

  B* b = new B(10);
  b->log(1);
  std::cout << "The size of b is: " << sizeof(b) << std::endl;
  delete b;

  B* c = new C(15);
  c->log(1);
  std::cout << "The size of b is: " << sizeof(c) << std::endl;
  delete c;

  return 0;
}