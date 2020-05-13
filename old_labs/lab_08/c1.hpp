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

#ifndef C1_H
#define C1_H

#include "b1.hpp"

class C1 : public B1
{
        int n;
    public:
        C1();
        C1(const int n1, const int n2);
        C1(const C1& other);
        virtual ~C1();

        // Используем переопределённые методы, как виртуальные за
        // счёт объявления их в классе выше по иерархии
        int getn() const { return n; }
        void setn(const int val) { n = val; }
        void show() const;
};

#endif // C1_H
