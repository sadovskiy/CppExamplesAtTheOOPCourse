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

#ifndef MENU_H
#define MENU_H

#include "database.hpp"
#include "managedb.hpp"

// Класс Menu описывающей работу меню программы
class Menu
{
        // Создаём базу данных
        DataBase db;
        // Создаём манипулятор базы
        ManageDB mandb;
    public:
        Menu();
        ~Menu();
        // Основное меню программы
        int exec();
        // Об авторе
        void about();
        // Пауза после вывода на экран сообщений меню и
        // результатов работы программы
        void pressAnyKey();
};

#endif // MENU_H
