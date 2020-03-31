#include <iostream>
#include <cmath>
using namespace std;

class Shape
{
  public:
    virtual void Print() = 0;
    virtual ~Shape() { };

  protected:
    double _area { 0 };
};

class Circle: public Shape
{
public:
  Circle(double _radius)
  {
    _area = pow(_radius * 3.14, 2);
  }

  void Print() override
  {
    cout << "The area of the circle is: " << _area << endl;
  }
};

class Square: public Shape
{
public:
  Square(double _side)
  {
    _area = _side * _side;
  }
  
  void Print() override
  {
    cout << "The area of the square is: " << _area << endl;
  }

};


int main()
{
  Circle myCircle(5);
  myCircle.Print();
  

  Square mySquare(5);
  mySquare.Print();

  return 0;
}

