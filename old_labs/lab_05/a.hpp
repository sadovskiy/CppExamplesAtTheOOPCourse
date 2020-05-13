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

#ifndef A_H
#define A_H

#include <iostream>
#include <cstring>

class A
{
        // Внутренние закрытые переменные класса "A"
        int* ptr_a;
        char* ptr_ch;
    public:
        // Конструкторы по умолчанию
        A();
        // Параметризированные конструкторы
        A(const int n);
        A(const char* str);
        A(const int n, const char* str);

        // Конструктор копирования
        A(const A& other);

        // Деструктор по умолчанию
        ~A();

        // Операция присваивания
        A& operator=(const A& other);

        // Методы по работе с данными класса
        void intSet(const int n);
        int intGet() const;
        void chSet(const char* str);
        char* chGet() const;
        void show() const;
};

#endif // A_H
