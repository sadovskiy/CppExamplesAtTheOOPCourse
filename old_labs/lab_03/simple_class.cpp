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

#include "simple_class.hpp"

// Используем для доступа к объектам стандартной системы ввода/вывода
using namespace std;

// Инициализируем переменные в заголовке (список инициализаторов) реализации конструктора по умолчанию
A::A(): n(0), fn(0), ch('\0'), str("")
{

}

// Инициализируем переменные в заголовке реализации параметризованного конструктора
A::A(const int n1,
     const float fn1,
     const char ch1,
     const string str1): n(n1),
                         fn(fn1),
                         ch(ch1),
                         str(str1)
{

}

// Реализация пустого деструктора по умолчанию
A::~A()
{

}

// Инициализируем переменные в заголовке реализации конструктора копирования
A::A(const A& other):   n(other.n),
                        fn(other.fn),
                        ch(other.ch),
                        str(other.str)
{

}

A& A::operator=(const A& rhs)
{
    if (this == &rhs) return *this;

    n   = rhs.n;
    fn  = rhs.fn;
    ch  = rhs.ch;
    str = rhs.str;

    return *this;
}


// Далее ряд реализаций методов, извлекающих/записывающих данные для каждой переменной класса "А"
// Таким образом, мы в нашем синтетическом примере реализуем принцип инкапсуляции.
int A::intGet() const // В реализации функции intGet() например, делаем возврат переменной "n" класса.
{                       // Чтобы подчеркнуть неизменяемость переменной, делаем функцию read-only
    return n;
}

// В реализации функции intSet(const int n1) задаём новое
// значение переменной класса "n" через присваивание
void A::intSet(const int n1)
{
    n = n1;
}

float A::floatGet() const
{
    return fn;
}

void A::floatSet(const float fn1)
{
    fn = fn1;
}

char A::charGet() const
{
    return ch;
}

void A::charSet(const char ch1)
{
    ch = ch1;
}

string A::stringGet() const
{
    return str;
}

void A::stringSet(const string str1)
{
    str = str1;
}

// Выводим на экран значение всех переменных класса в реализации функции print()
void A::print() const
{
    cout << "n   = " << n << "\n"
         << "fn  = " << fn << "\n"
         << "ch  = " << ch << "\n"
         << "str = " << str << endl;
         // endl - переносит на новую строку курсор
         // и выталкивает содержимое буфера вывода,
         // если в нём что-нибудь есть.
}
