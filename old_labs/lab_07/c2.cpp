/*
 *
 * Copyright (C) 2012 Dept. Information Systems, Technology and Automation in Civil Engineering (ISTAC),
 * Moscow State University of Civil Engineering (MSUCE or MGSU)
 *
 * Written by Sadovskiy B. S.
 *
 *
 * Права на программу (С) 2012 Кафедра информационных систем, технологий и автоматизации в строительстве (ИСТАС),
 * Московский Государственный строительный университет (МГСУ)
 *
 * Написана Садовским Б. С.
 *
 */

#include "c2.hpp"

C2::C2(): C1(), B2(), B3(), n(0)
{

}

C2::C2(const int n1, const int n2, const int n3): C1(n1, n2), B2(n1), B3(n1), n(n3)
{

}

C2::~C2()
{

}

C2::C2(const C2& other): C1(other), B2(other), B3(other), n(other.n)
{

}

void C2::show_C2() const
{
    // Вызовы методов классов выше по иерархии
    C1::show_C1();
    B2::show_B2();
    B3::show_B3();
    std::cout << "C2 = " << n << std::endl;
}
