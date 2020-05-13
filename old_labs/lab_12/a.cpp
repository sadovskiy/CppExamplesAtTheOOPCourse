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

#include "a.hpp"

// Опишем оставшиеся методы класса "А"
A::A(): str(""), num(0), bnum(false)
{

}

A::A(const std::string val1, const int val2, const bool val3): str(val1), num(val2), bnum(val3)
{

}

A::A(const A& other): str(other.str), num(other.num), bnum(other.bnum)
{

}

A::~A()
{

}

A& A::operator=(const A& rhs)
{
    if (this == &rhs) return *this;

    str = rhs.str;
    num = rhs.num;
    bnum = rhs.bnum;

    return *this;
}

void A::display() const
{
    std::cout   << "str: " << str << "\n"
                << "num: " << num << "\n";

    // Так как простой вывод логической переменной будет
    // отображать цифру 0 или 1, а надо более подходящие "true"
    // или "false", то придётся использовать условный оператор if () для вывода на экран
    // более подходящего сообщения
    if (bnum)
        std::cout << "bnum: true" << std::endl;
    else
        std::cout << "bnum: false" << std::endl;
}

bool A::isEmpty() const
{
    return num;
}

