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

#ifndef FILE_H
#define FILE_H

#include "database.hpp"

// Класс ManageDB позволяющий управлять базой данных
class ManageDB
{
    public:
        ManageDB();
        ~ManageDB();
        // Загрузка данных из файла в базу
        size_t load(const std::string filename, DataBase& db);
        // Запись данных в файл из базы
		bool save(const std::string filename, DataBase& db, const size_t numRows);
		// Добавление нового элемента в базу
        size_t addManual(DataBase& db);
        // Редактирование существующего элемента в базе
		bool modManual(DataBase& db);
		// Поиск элемента в базе
        bool findManual(DataBase& db);
        // Удаление элемента из базы
		size_t delManual(DataBase& db);
};

#endif // FILE_H
