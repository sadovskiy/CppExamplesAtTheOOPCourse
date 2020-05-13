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

#include "c1.hpp"

C1::C1(): B1(), n(0)
{

}

C1::C1(const int n1, const int n2): B1(n1), n(n2)
{

}

C1::~C1()
{

}

C1::C1(const C1& other): B1(other), n(other.n)
{

}

void C1::show() const
{
    B1::show();
    std::cout << "C1 = " << n << std::endl;
}
