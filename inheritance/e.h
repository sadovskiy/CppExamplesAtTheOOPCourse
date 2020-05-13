#ifndef E_H
#define E_H

#include "c.h"

class E: public C
{
		int e;
	public:
		E();
		E(const int val_1, const int val_2, const int val_3);
		E(const E& other);
		virtual ~E();
		void show_e() const;
		int get_e() const;
		void set_e(const int val);
};

#endif // E_H
