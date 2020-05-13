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

#ifndef FUNC_HPP_INCLUDED
#define FUNC_HPP_INCLUDED

#include <iostream>

// Максимальное количество записей в базе 100
#define NUM 100

// Структура для хранения базы телефонных номеров.
typedef struct
{
    unsigned short id;
    unsigned int telephone;
    std::string name;
    std::string t_plan;
    std::string adress;
} TBase;

// Структура для хранения базы телефонных номеров в бинарном виде.
typedef struct
{
    unsigned short id;
    unsigned int telephone;
    char name[50];
    char t_plan[50];
    char adress[100];
} TBaseBin;

// глобальный массив "db" для структур.
//TBase db[NUM];

// Прототипы функций
size_t readStr(TBase(& db)[NUM]);
void   writeStr(const size_t n, const TBase* const db);
size_t readBin(TBase* db);
void   writeBin(const size_t n, const TBase* const db);
void   print(const size_t n, const TBase* const db);
void   about();
void   pressAnyKey();

#endif // FUNC_HPP_INCLUDED
