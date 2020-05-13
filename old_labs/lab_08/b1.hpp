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

#ifndef B1_H
#define B1_H

#include <iostream>

class B1
{
        int n;
    public:
        B1();
        B1(const int n1);
        B1(const B1& other);
        // Если есть хоть одна виртуальная функция,
        // то все существующии деструкторы должны быть виртуальными
        virtual ~B1();

        // Создаём виртуальные функции используя переопределённые методы
        virtual int getn() const { return n; }
        virtual void setn(const int val) { n = val; }
        virtual void show() const {std::cout << "B1 = " << n << std::endl;}
};

#endif // B1_H
