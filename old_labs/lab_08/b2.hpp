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

#ifndef B2_H
#define B2_H

#include <iostream>

class B2
{
        int n;
    public:
        B2();
        B2(const int n1);
        B2(const B2& other);
        virtual ~B2();

        int getn() const { return n; }
        void setn(const int val) { n = val; }
        void show() const {std::cout << "B2 = " << n << std::endl;}
};

#endif // B2_H
