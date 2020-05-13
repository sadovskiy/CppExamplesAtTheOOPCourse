#include "d.h"

using namespace std;

D::D(): B(), C(), d(0)
{
	//ctor
}

D::D(const int val_1, const int val_2, const int val_3): B(val_1, val_2), C(val_1, val_2), d(val_3)
{

}

D::~D()
{
	//dtor
}

D::D(const D& other): B(), C(), d(other.d)
{
	//copy ctor
}

void D::show_d() const
{
	cout << "class D" << B::get_a() << get_c() << d << endl;
}

int D::get_d() const
{
	return d;
}

void D::set_d(const int val)
{
	d = val;
}
