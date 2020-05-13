#include "a.h"

using namespace std;

A::A(): a(0)
{
	//ctor
}

A::A(const int val): a(val)
{

}

A::~A()
{
	//dtor
}

A::A(const A& other): a(other.a)
{
	//copy ctor
}

void A::show_a() const
{
	cout << "class A" << a << endl;
}

int A::get_a() const
{
	return a;
}

void A::set_a(const int val)
{
	a = val;
}
