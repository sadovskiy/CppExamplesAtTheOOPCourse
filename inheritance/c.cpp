#include "c.h"

using namespace std;

C::C(): A(), c(0)
{
	//ctor
}

C::C(const int val_1, const int val_2): A(val_1), c(val_2)
{

}

C::~C()
{
	//dtor
}

C::C(const C& other): A(other.c), c(other.c)
{
	//copy ctor
}

void C::show_c() const
{
	cout << "class C" << get_a() << c << endl;
}

int C::get_c() const
{
	return c;
}

void C::set_c(const int val)
{
	c = val;
}
