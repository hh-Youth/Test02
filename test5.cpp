#include <iostream>
using namespace std;
const double PI = 3.14159;
class Shape
{
public:
	int x, y;
public:
	Shape() {

	}
	Shape(int xx, int yy)
	{
		x = xx;  y = yy;
	}
	virtual double area() = 0;
	virtual void show() = 0;
};
class Rectangle :public Shape
{
public:
	int len, wid,x;
public:
	Rectangle(int xx, int yy, int a, int b) :Shape(xx, yy)
	{
		len = a; wid = b;
		x = 10;
	}
	double area()
	{
		return len * wid;
	}
	void show()
	{
		cout << "该图形为矩形！" << endl;
		cout << "中心位置为:" << x << "," << y << endl;
		cout << "长为:" << len << "," << "宽为:" << wid << endl;
	}
};
class Circle :public Shape
{
private:
	int radius;
public:
	Circle(int xx, int yy, int rr) :Shape(xx, yy)
	{
		radius = rr  ;
	}
	double area()
	{
		return PI * radius * radius;
	}
	void show()
	{
		cout << "该图形为圆！" << endl;
		cout << "中心位置为:" << x << "," << y << endl;
		cout << "半径为:" << radius << endl;
	}
};
int main5()
{
	Shape* p;
	Rectangle r1(20, 20, 4, 8);
	cout << "r1的信息如下:" << endl;
	p = &r1;
	p->show();
	cout << "面积为:" << p->area() << endl << endl;

	cout << r1.x << endl;
	cout << r1.Shape::x<<endl;

	Circle c1(5, 6, 7);
	cout << "c1的信息如下:" << endl;
	p = &c1;
	p->show();
	cout << "面积为:" << p->area() << endl;

	return 0;
}