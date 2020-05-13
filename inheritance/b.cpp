#include "b.h"

using namespace std;

B::B(): A(), b(0)
{
	//ctor
}

B::B(const int val_1, const int val_2): A(val_1), b(val_2)
{

}

B::~B()
{
	//dtor
}

B::B(const B& other): A(other.b), b(other.b)
{
	//copy ctor
}

void B::show_b() const
{
	cout << "class B" << get_a() << b << endl;
}

int B::get_b() const
{
	return b;
}

void B::set_b(const int val)
{
	b = val;
}
