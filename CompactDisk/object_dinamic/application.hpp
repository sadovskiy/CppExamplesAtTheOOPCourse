/*
 * Copyright (C) 2007-2020. GPL
 *
 * Written by Sadovskiy B. S.
 *
 * Права на программу (С) 2007-2020. GPL
 *
 * Написана Садовским Б. С.
 *
 * Пример работы с моделью размещённой в динамической памяти 
 * и с динамическим меню
 *
 *
 */

#ifndef APPLICATION_H
#define APPLICATION_H

#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cstdarg>
#include <wchar.h>
#include <cstdlib>

#include "compactdisk.hpp"
#include "database.hpp"

#define BACK_SUCCESS 	10 // успешное возвращение из подпункта меню
#define BACK_FAILURE 	11 // ошибка возвращения из подпункта меню
#define EXIT_MENU		3 // выход из меню
#define BACK			4 // назад из пункта меню
#define EXIT			5 // выход из программы
#define STOP			6 // остановка выхода из подменю

class Application
{
        DataBase database; // база хранящая данные в виде двусвязного списка
        std::wstring nameDataBase; // имя базы данных и одновременно имя её файла


    public:
        Application();
        ~Application();
        bool exec();	// сюда передаётся управление программой
        unsigned int displayMenu(	const unsigned short count, // выводит на экран меню и
                        int (Application::*pf)()); // передаёт управление пользователю

        int itemsMenu(const unsigned short count, int (Application::*pf)(), ...); // составляет список пунктов меню
                                            // и функций которые будут вызываться
                                            // при выборе пользователем пункта в меню,
                                            // который соответствует этой функции
        int file();	// файловые операции
        int loadfile(); // загрузить БД из файла
        int savefile(); // сохранить БД в файл

        int changefile(); // сменить имя БД

        int manageDB(); // операции с записями БД
        int addDB();	// добавить запись
        int modDB();	// изменить существующую запись
        int delDB();	// удалить запись
        int findNumDB();	// найти запись по её порядковому номеру
        int findNameDB();	// найти запись по её имени
        int takeDB();		// положить компакт-диск в БД
        int placeDB();		// извлечь компакт-диск из БД

        int display();	// отобразить всё содержимое БД на экран

        int backApp();	// вернуться назад из подменю
        int exitApp();	// выйти из программы

    // закрываем возможность копирования приложения
    private:
        Application(const Application& other);
        Application& operator=(const Application& other);
};

#endif // APPLICATION_H
