#include <iostream>
using namespace std;

class Shape
{
public:
	virtual double Area() = 0;
	virtual void Print() = 0;
	virtual ~Shape();

private:
	double _area { 0 };
};

class Circle
{
public:
	double Area() override
	{

	}

