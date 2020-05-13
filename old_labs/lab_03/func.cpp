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

// Функции, в которые передаётся объект класса "А"
// сначала через указатель,
void f1(A* const a2)
{
    // Изменяем некоторые данные
    a2->intSet(20);
    a2->floatSet(4.2);
    a2->charSet('h');
    a2->stringSet("test1");
}

// а затем через ссылку
void f2(A& a3)
{
    // Изменяем некоторые данные
    a3.intSet(40);
    a3.floatSet(8.1);
    a3.charSet('t');
    a3.stringSet("test2");
}
