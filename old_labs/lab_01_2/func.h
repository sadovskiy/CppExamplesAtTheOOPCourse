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

#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

// Максимальное количество записей в массиве
#define NUM 100

// Структура для хранения базы данных телефонных номеров
// в виде массива
typedef struct
{
    int  id;
    int  telephone;
    char name[80];
    char t_plan[50];
    char adress[100];
} tbase;

// Глобальный массив "db" для структур
// сделан по заданию
//tbase db[NUM];

// Прототипы функций
void   f1(const size_t num_s, const tbase* db);
size_t f2(tbase* db);
void   print(const size_t num_s, const tbase* const db);
void   about(void);
void   press_any_key(void);

#endif // FILE_H_INCLUDED
