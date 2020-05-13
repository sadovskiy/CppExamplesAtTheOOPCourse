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
#include "func.hpp"

int main()
{
    // Создаём объект "a1"
    A a1;

    // Вызов метода отображения данных show(),
    // описанного в классе, в данном
    // случае, печатает пустые значения
    a1.show();

    // Вызываем перегруженные функции,
    // в первом случае по значению,
    // во втором случае через указатель
    f1(a1);
    f2(&a1);

    // Результат выводим на экран
    std::cout << a1.intGet() << endl;
    std::cout << a1.chGet() << endl;

    return 0;
}
