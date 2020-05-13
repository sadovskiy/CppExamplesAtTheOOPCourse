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

#include <cstdlib>

#include "func.hpp"

using namespace std;

int main()
{
    // Тип size_t хорошо использовать для счётчиков, итераторов,
    // помещения в него указателя и для создания переносимого кода
    size_t n = 0;

    // Локальная база данных "db"
    TBase db[NUM];

    // Меню программы работает в бесконечном цикле,
    // пока пользователем не будет выбран пункт меню "Выход".
    // Если переменной "exit_menu" присвоить false, произойдёт
    // выход из программы.
    // По умолчанию делаем его равным true
    bool exit_menu = true;

    // Бесконечный цикл меню программы. После завершения
    // работы какого либо пункта меню, происходит возврат
    // назад в меню.
    while (exit_menu) {

        // Выводим на экран список пунктов меню
//        cout << "Телефонная база\n" <<
//                "1) Открыть файл\n" <<
//                "2) Сохранить файл\n" <<
//                "3) Открыть бинарный файл\n" <<
//                "4) Сохранить бинарный файл\n" <<
//                "5) Вывести на экран файл\n" <<
//                "6) О программе\n" <<
//                "7) Выход\n" << endl;
        cout << "Telephone Database\n" <<
                "1) Open Database File\n" <<
                "2) Save Database File\n" <<
                "3) Open Binary Database File\n" <<
                "4) Save Binary Database File\n" <<
                "5) Print Database\n" <<
                "6) About\n" <<
                "7) Exit\n" << endl;

        // Ждём ввода команд пользователя
        unsigned ch = cin.get();
        // Делаем очистку перед запуском выбранного
        // пользователем пункта меню.
        // В случае разных ОС, компилятор выберет подходящий
        // способ очистки экрана
#ifdef __linux__
        system("clear");
#elif __windows__
        system("cls");
#endif
        switch (ch) {
            // Если выбран первый пункт, то открываем файл Базы Данных (БД)
            // записываем из него в нашу БД (массив "db")
            // и сохраняем в "n" количество записей в БД
            case '1':
                n = readStr(db);
                pressAnyKey();
                break;
            // Записываем в файл содержимое БД
            case '2':
                writeStr(n, db);
                pressAnyKey();
                break;
            // Записываем из бинарного файла содержимое БД
            case '3':
                n = readBin(db);
                pressAnyKey();
                break;
            // Записываем в бинарный файл содержимое БД
            case '4':
                writeBin(n, db);
                pressAnyKey();
                break;
            // Выводим содержимое БД на экран
            case '5':
                print(n, db);
                pressAnyKey();
                break;
            case '6':
            // Выводим информацию об авторе
                about();
                pressAnyKey();
                break;
            // Выходим из меню, установив "exit_menu" в "false".
            // При следующей проверке условия, в заголовке цикла while(),
            // будет произведён выход
            case '7':
                exit_menu = false;
                break;
			// Если введённый пользователем символ,
			// не соответствует имеющимся в меню пунктам,
			// то ему выводится соответствующее сообщение
			default: cerr << "Error: Сommand is not"         // "Ошибка: команда не"
                          << "defined in the menu!" << endl; // "определена в меню!\n"
                break;
        }
    }

    return 0;
}
