#ifndef D_H
#define D_H

#include "b.h"
#include "c.h"

class D: public B, public C
{
		int d;
	public:
		D();
		D(const int val_1, const int val_2, const int val_3);
		D(const D& other);
		virtual ~D();
		void show_d() const;
		int get_d() const;
		void set_d(const int val);
};

#endif // D_H
