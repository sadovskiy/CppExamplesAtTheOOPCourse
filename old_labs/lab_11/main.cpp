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

#include <locale>

#include "menu.hpp"

// В файле main.cpp мы только создаём объект меню
// и передаём ему управление
int main()
{
    // Установка русской локали
    setlocale(LC_ALL,"ru_RU.UTF-8");
    // Чтобы использовать в десятичных дробях
    // в качестве разделителя точку
    setlocale(LC_NUMERIC, "C");
    // Создаём меню
    Menu menu;

    // Передаём управление меню
    return menu.exec();
}
