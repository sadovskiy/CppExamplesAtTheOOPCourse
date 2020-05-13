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

// Создаём класс наследник "C1" от базового "B1".
// Общедоступное наследование даёт доступ к public
// и protected данным и методам
class C1 : public B1
{
        int n;
    public:
        C1();
        C1(const int n1, const int n2);
        C1(const C1& other);
        ~C1();

        int getn_C1() const { return n; }
        void setn_C1(const int val) { n = val; }
        void show_C1() const;
};

#endif // C1_H
