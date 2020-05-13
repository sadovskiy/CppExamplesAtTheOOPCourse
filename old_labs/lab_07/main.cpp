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

#include "c3.hpp"

int main()
{
    // Создаём объекты классов, чем больше аргументов конструктора,
    // тем ниже класс в иерархии
    B1 b1(100);
    B2 b2(100);
    B3 b3(100);
    C1 c1(100, 200);
    C2 c2(100, 200, 300);
    C3 c3(100, 200, 300, 400);

    // для пробы вызываем один метод show_C3() класса "C3"
    c3.show_C3();

    // Создаём указатель типа "B1"
    B1* ptr = 0;

    // Передаём адресс переменной
    ptr = &c3;

    // Вызываем метод
    ptr->show_B1();

    return 0;
}
