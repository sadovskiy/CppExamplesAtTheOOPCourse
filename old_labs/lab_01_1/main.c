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
// Подключаем для использования функции system()
// и макросов EXIT_SUCCESS(EXIT_FAILURE)
#include <stdlib.h>

#include "func.h"

int main(void)
{
//   scanf("%s", str); по заданию в пункте 1 части №2
    while (1) {
        // Делаем очистку экрана, вызвав в MS Windows программу cls.
        // В случае GNU/Linux надо использовать программу clear.
        // В следующей лабораторной работе будет показано
        // как это сделать для обоих систем
        system("cls");

        // Выводим меню пользователю
        // "Простая Си программа чтения/записи в файл.\n"
        // "1 - Прочитать из файла.\n"
        // "2 - Записать в файл.\n"
        // "q - Выход.\n"
        printf("Simple the C programm read/write in file.\n");
    	printf("1 - Read from file.\n");
    	printf("2 - Write in file.\n");
    	printf("q - Exit.\n");

        // Ждём выбора пользователя
        switch (getchar())
        {
            // Передаём управление на выбранный пользователем пункт меню
        	case '1' : f2();
        		break;
        	case '2' : f1();
        		break;
        	case 'q' : return EXIT_SUCCESS; // EXIT_SUCCESS эквивалентно "0"
        		break;

            default  : fprintf(stderr, "Error: Сommand is not "   // "Ошибка: команда не"
                                       "defined in the menu!\n"); // "определена в меню!\n"
                break;
        }

        // Отбрасываем нажатую пользователем клавишу '\n' в switch (getchar())
        fgetc(stdin);

        // Пауза с ожиданием нажатия клавиши '\n' (Enter), чтобы пользователь мог
        // прочитать сообщения выданные в switch (getchar())
        fgetc(stdin);
    }

//    printf("%s", str); надо написать по заданию в пункте 1 части №2

    // По стандарту положено возвращать "0" в ОС,
    // что говорит об успешном завершении программы
    return EXIT_SUCCESS; // EXIT_SUCCESS эквивалентно "0"
}
