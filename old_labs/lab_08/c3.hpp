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

#ifndef C3_H
#define C3_H

#include "c2.hpp"

class C3 : public C2
{
        int n;
    public:
        C3();
        C3(const int n1, const int n2, const int n3, const int n4);
        C3(const C3& other);
        virtual ~C3();

        int getn() const { return n; }
        void setn(const int val) { n = val; }
        void show() const;
};

#endif // C3_H
