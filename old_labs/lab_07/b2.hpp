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

// Создаём базовый класс "B2"
class B2
{
        // Одна переменная
        int n;
    public:
        B2();
        B2(const int n1);
        B2(const B2& other);
        ~B2();

        // Создаём методы по работе с данными класса.
        // В конце имени каждого метода пишем название класса,
        // чтобы не было его переопределений в классах наследниках
        int getn_B2() const { return n; }
        void setn_B2(const int val) { n = val; }
        void show_B2() const {std::cout << "B2 = " << n << std::endl;}
};

#endif // B2_H
