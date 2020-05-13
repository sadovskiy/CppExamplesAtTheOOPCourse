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

// Создаём базовый класс 3
class B3
{
        // Одна переменная
        int n;
    public:
        B3();
        B3(const int n1);
        B3(const B3& other);
        ~B3();

        // Создаём методы по работе с данными класса.
        // В конце имени каждого метода пишем название класса,
        // чтобы не было его переопределений в классах наследниках
        int getn_B3() const { return n; }
        void setn_B3(const int val) { n = val; }
        void show_B3() const {std::cout << "B3 = " << n << std::endl;}
};

#endif // B3_H
