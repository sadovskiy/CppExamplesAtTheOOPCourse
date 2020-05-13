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

#ifndef C2_H
#define C2_H

#include "c1.hpp"
#include "b2.hpp"
#include "b3.hpp"

// Создаём класс наследник "С2" с множественным наследованием
class C2 : public C1, public B2, public B3
{
        int n;
    public:
        C2();
        C2(const int n1, const int n2, const int n3);
        C2(const C2& other);
        ~C2();

        int getn_C2() const { return n; }
        void setn_C2(const int val) { n = val; }
        void show_C2() const;
};

#endif // C2_H
