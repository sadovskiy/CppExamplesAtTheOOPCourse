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

#ifndef B3_H
#define B3_H

#include <iostream>

class B3
{
        int n;
    public:
        B3();
        B3(const int n1);
        B3(const B3& other);
        virtual ~B3();

        int getn() const { return n; }
        void setn(const int val) { n = val; }
        void show() const {std::cout << "B3 = " << n << std::endl;}
};

#endif // B3_H
