#ifndef A_H
#define A_H

#include <iostream>

class A
{
		int a;
	public:
		A();
		A(const int val);
		A(const A& other);
		virtual ~A();
		void show_a() const;
		int get_a() const;
		void set_a(const int val);
};

#endif // A_H
