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
// Подключаем для использования функции exit()
// и макросов EXIT_SUCCESS(EXIT_FAILURE)
#include <stdlib.h>

#include "func.h"

void f1(void)
{
    // Создаём массив символов "str", который инициализируем
    // строкой константой. Символьный массив (строка) нужен для записи в файл
//    char str[100] = "Привет мир!";
    char str[100] = "Hello, World!";
    // Создаём поток для записи в файл
    FILE* out = NULL;

    // Асcоциируем поток "out" с файлом db.txt, при этом открыв
    // этот файл на запись, и проверяем, открылся ли он
    if (!(out = fopen("db.txt", "w"))) {
        // Если он не открылся, пишем предупреждающее сообщение
        // в специальный поток ошибок "stderr"
        fprintf(stderr,"Error: File not open!\n"); // "Ошибка: файл не открыт!\n"
        // и выходим из программы
        exit(EXIT_FAILURE);
    }

    // Выводим пользователю сообщение о начале записи
    printf("Starting writing to the file.\n"); // "Начинаем записывать в файл.\n"

    // и пишем в поток "out" наше сообщение
    fprintf(out, "%s", str);

    // и выводим на экран сообщение пользователю
    // об усппешном завершении операции
    printf("Finished writing to the file.\n"); // "Закончили записывать в файл.\n"

    // Закрываем поток
    fclose(out);
}

void f2(void)
{
    // Создаём символьный массив, как в предыдущей функции
    char str[100];
    FILE* in = NULL;

    if (!(in = fopen("db.txt", "r"))) {
        fprintf(stderr,"Error: File not open!\n"); // "Ошибка: файл не открыт!\n"
        exit(EXIT_FAILURE);
    }

    // Выводим пользователю сообщение о начале чтения
    printf("Starting reading from the file.\n"); // "Начинаем читать из файла.\n"

    // fscanf(in, "%s", str); будет читать только первое слово до пробела

    // fgets() читает до конца строки
    fgets(str, 100, in);
    // Выводим прочитанную строку на экран
    printf("Loaded from file: %s\n", str); // "Загружено из файла: %s\n"

    // и сообщаем пользователю об окончании чтения
    printf("Finished reading from the file.\n"); // "Закончили читать из файла.\n"

    fclose(in);
}
