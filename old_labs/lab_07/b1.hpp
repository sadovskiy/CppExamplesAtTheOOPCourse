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

// Создаём базовый класс "B1"
class B1
{
        // Одна переменная
        int n;
    public:
        B1();
        B1(const int n1);
        B1(const B1& other);
        ~B1();

        // Создаём методы по работе с данными класса.
        // В конце имени каждого метода пишем название класса,
        // чтобы не было его переопределений в классах наследниках
        int getn_B1() const { return n; }
        void setn_B1(const int val) { n = val; }
        void show_B1() const {std::cout << "B1 = " << n << std::endl;}
};

#endif // B1_H
