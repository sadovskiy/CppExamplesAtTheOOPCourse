#include "a.h"
#include "b.h"
#include "c.h"
#include "d.h"
#include "e.h"

using namespace std;

int main()
{
	A *ptr;
	A a(1);
	B b(1, 2);
	C c(3, 4);
	D d(1, 2, 3);
	d.show_d();
	ptr = (B *) &d; // требуется определить класс
	ptr->show_a();

    return 0;
}
