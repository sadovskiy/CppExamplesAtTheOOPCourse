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

#include "c3.hpp"

C3::C3(): C2(), n(0)
{

}

C3::C3(const int n1, const int n2, const int n3, const int n4): C2(n1, n2, n3), n(n4)
{

}

C3::~C3()
{

}

C3::C3(const C3& other): C2(other), n(other.n)
{

}

void C3::show_C3() const
{
    C2::show_C2();
    std::cout << "C3 = " << n << std::endl;
}
