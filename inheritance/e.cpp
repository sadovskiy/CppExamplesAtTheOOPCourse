#include "e.h"

using namespace std;

E::E(): C(), e(0)
{
	//ctor
}

E::E(const int val_1, const int val_2, const int val_3): C(val_1, val_2), e(val_3)
{

}

E::~E()
{
	//dtor
}

E::E(const E& other): C(other.get_a(), other.get_c()), e(other.e)
{
	//copy ctor
}

void E::show_e() const
{
	cout << "class E" << get_a() << get_c() << e << endl;
}

int E::get_e() const
{
	return e;
}

void E::set_e(const int val)
{
	e = val;
}
