#ifndef B_H
#define B_H

#include "a.h"

class B: public A
{
		int b;
	public:
		B();
		B(const int val_1, const int val_2);
		B(const B& other);
		virtual ~B();
		void show_b() const;
		int get_b() const;
		void set_b(const int val);
};

#endif // B_H
