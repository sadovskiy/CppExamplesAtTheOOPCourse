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

#ifndef FILE_HPP_INCLUDED
#define FILE_HPP_INCLUDED

#include <iostream>
#include <string>

// Создаём класс A для работы со строками
class A
{
        // Закрытая переменная
        string strSlot;
    public:
        // Далее все методы открытые
        // Конструктор по умолчанию класса А
        A();
        // Параметризованный конструктор
        A(const string str);
        // Конструктор копирования
        A(const A& a);
        // Деструктор по умолчанию
        ~A();

        // перегруженные операции
        A& operator=(const A& rhs);
        A  operator+(const A& rhs);

        // Для реализации операции поместить в поток
        // нельзя использовать метод (функцию-член) класса А,
        // по этому приходится определить дружественную функцию
        friend void operator<<(ostream& os, const A& rhs);

        // Методы по извлечению данных, добавлению и выводу на экран
        string getStr() const;
        void   setStr(const string str);
        void   show() const;
};


#endif // FILE_HPP_INCLUDED
