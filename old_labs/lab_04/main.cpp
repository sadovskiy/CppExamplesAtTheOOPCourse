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

#include "file.hpp"
#include "func.hpp"

int main()
{
    // Создаём объект (переменную) "a1" и n
    A a1("Привет");
    int n = 10;

    // Выбор порядка вызова функций осуществляется
    // компилятором по типу аргумента
    print(&a1);
    print(&n);


    return 0;
}
