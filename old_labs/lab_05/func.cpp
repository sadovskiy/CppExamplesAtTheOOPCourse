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

#include "func.hpp"

void f1(A a)
{
    // По заданию вводим данные
    a.intSet(100);
    a.chSet("Hello, world!"); // "Привет мир!"
}

void f2(A* const b)
{
    // По заданию вводим данные
    b->intSet(20);
    b->chSet("Пока.");
}
