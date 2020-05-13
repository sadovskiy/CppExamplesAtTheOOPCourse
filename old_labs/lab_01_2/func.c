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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "func.h"

void f1(const size_t num_s, const tbase* db)
{
    // Создаём массив символов "str", который инициализируем
    // строкой константой. Символьный массив нужен для записи в файл
//    char str[100] = "Привет мир!";

    // Создаём поток для записи в файл
    FILE* out = NULL;

    // Асcоциируем поток "out" с файлом "tele.db", при этом открыв
    // этот файл на запись, и проверяем открылся ли он
    if (!(out = fopen("tele.db", "w"))) {
        // Если он не открылся, пишем предупреждающее сообщение
        // в специальный поток "stderr"
        fprintf(stderr,"Error: File not open!\n");
        // и выходим из программы
        exit(EXIT_FAILURE);
    }

    // Пишем в поток "out" наше сообщение
//    fprintf(out, "%s", str);

    // Сохраняем записи из БД в файл
    for (register size_t i = 0; i < num_s; i++)
        fprintf(out, "%d;%d;%s;%s;%s\n", db[i].id, db[i].telephone, db[i].name, db[i].t_plan, db[i].adress);

    fprintf(out, "%d;%d;%s;%s;%s", db[num_s].id, db[num_s].telephone, db[num_s].name, db[num_s].t_plan, db[num_s].adress);

    // и выводим на экран сообщение пользователю
    // об усппешном завершении операции
    printf("File is recorded.\n"); // "Файл записан."

    // Закрываем поток
    fclose(out);
}

size_t f2(tbase* db)
{
    FILE* in = NULL;
    // Создаём символьный массив, как в предыдущей функции
    char str[100];
    // Создаём указатель для временного хранения строки
    char* p = NULL;
    // Создаём переменную для хранения количества записей в базе, прочитанных из файла
    size_t num_s = 0;

    // По аналогии с открытием файла в функции f2()
    if (!(in = fopen("tele.db", "r"))) {
        fprintf(stderr,"Error: File not open!\n");
        exit(EXIT_FAILURE);
    }


    // fscanf(in, "%s", str); будет читать только первое слово до пробела,
    // поскольку нам требуется резместить прочитанные данные в структуре,
    // то нам необходимо реализовать парсер.
    for (register size_t i = 0; !feof(in); i++) {

        // fgets() читает до конца строки
        fgets(str, 100, in);
        // С помощю функции strtok() в строке "str" ищем символ-разделитель ";" и
        // в переменную "p" записывается значение из строки "str" до символа ";"
        p = strtok(str, ";");
        // Копируем значение из "p" в "db.n", но число из "p" типа char, а
        // число в "db.n" является типа int. Поэтому необходимо воспользоваться
        // функцией atoi() для преобразования данных из одного типа в другой
        db[i].id = atoi(p);
        p = strtok('\0', ";"); // или strtok(0, ";"), что тоже самое
        db[i].telephone = atoi(p);
        p = strtok('\0', ";");
        strcpy(db[i].name, p);
        p = strtok('\0', ";");
        strcpy(db[i].t_plan, p);
        // Ищем кроме ";" и удаляем перевод на новою строку "\n"
        p = strtok('\0', ";\n");
        strcpy(db[i].adress, p);
        num_s = i;
    }

    fclose(in);

    return num_s;
}

void print(const size_t num_s, const tbase* const db)
{
    // делаем проверку, не пуста ли наша база данных (массив)
    if (!num_s) {
        printf("Database is empty!\n"); // "База данных пуста\n"
        return;
    }

    // Выводим прочитанную строку на экран
    for (register size_t i = 0; i < num_s + 1; i++)
        printf("%d %d %s %s %s\n", db[i].id,
                                   db[i].telephone,
                                   db[i].name,
                                   db[i].t_plan,
                                   db[i].adress);
}

void about(void)
{
    printf("Made in ISTAC (MSUCE), author: Sadovskiy B. S.\n");
}

void press_any_key(void)
{
    // "\nНажмите любую клавишу для продолжения...\n"
    fprintf(stdout, "\nPress any key...\n");

    // Если в потоке ввода остались символы, то мы их удаляем
    while (fgetc(stdin) != '\n');

    // Ставим задержку
    getchar();
// в случае разных ОС, компилятор выберет подходящий
// способ очистки экрана
#ifdef __linux__
    system("clear");
#elif __windows__
    system("cls");
#endif
}
