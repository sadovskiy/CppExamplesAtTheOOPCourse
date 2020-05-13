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

int main()
{
    // Создаём объект (при этом вызывается конструктор по умолчанию)
    A a1;

    // Проводим инициализацию объекта
    // по отдельности каждого из параметров класса
    a1.intSet(10);
    a1.floatSet(5.7);
    a1.charSet('a');
    a1.stringSet("test");

    // Выводим на экран только что заданные данные
    a1.print();

    // Создаём объект (вызывается конструктор по умолчанию)
    A b;

    // Копируем данные из одного объекта в другой поэлементно
    b.intSet(a1.intGet());
    b.floatSet(a1.floatGet());
    b.charSet(a1.charGet());
    b.stringSet(a1.stringGet());

    // Выводим на экран только что заданные данные
    b.print();

    // Передаём объект в функцию через указатель
    f1(&a1);
    // Передаём объект в функцию как параметр
    f2(b);

    // Выводим на экран значения каждого из локальных объектов
    a1.print();
    b.print();

    return 0;
}
