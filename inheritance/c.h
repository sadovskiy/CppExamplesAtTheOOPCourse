#ifndef C_H
#define C_H

#include "a.h"

class C: public A
{
		int c;
	public:
		C();
		C(const int val_1, const int val_2);
		C(const C& other);
		virtual ~C();
		void show_c() const;
		int get_c() const;
		void set_c(const int val);
};

#endif // C_H
