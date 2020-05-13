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

#ifndef SIMPLE_CLASS_H
#define SIMPLE_CLASS_H

#include <iostream>

// Создаём наш класс A по заданию из
// методических указаний лабораторной работы №3
class A
{
    // Уровень доступа для наших данных можно не ставить,
    // так как он по умолчанию является privet,
    // что нам как раз подходит (по заданию требуется соблюдать принцип инкапсуляции)
        int n;
        float fn;
        char ch;
        std::string str;

    // Создаём открытый интерфейс
    public:
        // Прототип конструктора по умолчанию
        A();
        // Прототип параметризованного конструктора
        A(const int n1, const float fn1, const char ch1, const std::string str1);

        // Прототип конструктора копирования
        A(const A& other);
        // Прототип перегруженной операции присваивания
        A& operator=(const A& other);

        // Прототип деструктора по умолчанию
        ~A();

        // Прототип метода (функции-члена) для задания
        // закрытых данных (переменная "n") класса
        int intGet() const;

        // Прототип метода (функции-члена)
        // для чтения закрытых данных (переменная "n") класса
        void intSet(const int n1);


        // и так далее для остальных переменных
        float floatGet() const;
        void floatSet(const float fn1);

        char charGet() const;
        void charSet(const char ch1);

        std::string stringGet() const;
        void stringSet(const std::string str1);

        // Вывод на экран содержимого закрытых данных класса
        void print() const;
};

#endif // SIMPLE_CLASS_H
