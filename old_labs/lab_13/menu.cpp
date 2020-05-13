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

#include <iostream>
#include <limits>
#include <cstdlib>

#include "menu.hpp"

using namespace std;

Menu::Menu()
{

}

Menu::~Menu()
{

}

int Menu::exec()
{
    // Тип size_t хорошо использовать для счётчиков, итераторов,
    // помещения в него указателя и для создания переносимого кода
    // В данном случае воспользуемся им, что бы сделаем количество
    // записей в базе данных
    size_t numRows = 0;

    // Меню программы работает в бесконечном цикле пока
    // пользователем не будет выбран пункт меню "Выход".
    // Если переменной exit_menu присвоить false произойдёт
    // выход из программы.
    bool exit_menu = true;

    // Бесконечный цикл меню программы. После завершения
    // работы какого - либо пункта меню происходит возврат
    // назад в меню.
    while (exit_menu) {
        // Делаем очистку экрана перед выводом меню программы
        // В случае разных ОС компилятор выберет подходящий
        // способ очистки экрана
#ifdef __linux__
        system("clear");
#elif __windows__
        system("cls");
#endif
        // Сброс специальных битов (goodbit, eofbit, failbit, badbit) ввода для предотвращения
        // зацикливания при вводе некорректных символов пользователем
        cin.clear();

        // Выводим на экран пункты меню
        cout << "База компьютерных корпусов.\n"
                "Количество записей хранящихся в базе: " << numRows << "\n" <<
                "1) Открыть файл\n" <<
                "2) Сохранить файл\n" <<
                "3) Добавить запись в базу\n" <<
                "4) Удалить запись из базы\n" <<
                "5) Редактировать запись в базе\n" <<
                "6) Найти запись в базе\n" <<
                "7) Вывести на экран файл\n" <<
                "8) О программе\n" <<
                "9) Выход\n" << endl;

        // Ждём ввода команд пользователя
        unsigned ch = cin.get();
        // Делаем очистку перед запуском выбранного
        // пользователем пункта меню, так как меню нам больше
        // не нужно
        // В случае разных ОС компилятор выберет подходящий
        // способ очистки экрана
#ifdef __linux__
        system("clear");
#elif __windows__
        system("cls");
#endif
        switch (ch) {
            // Если выбран первый пункт открываем файл БД
            // записываем из него в нашу БД (массив "db")
            // и сохраняем в "n" количество записей в БД
            case '1':
                numRows = mandb.load("computercase.db", db);
                pressAnyKey();
                break;
            // Записываем в файл содержимое БД
            case '2':
                mandb.save("computercase.db", db, numRows);
                pressAnyKey();
                break;
            // Добавить в файл новую запись БД
            case '3':
                // если в потоке ввода остались символы, то мы их удаляем (игнорируем)
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if (numRows)
                    numRows = mandb.addManual(db);
                else
                    cout << "База не загружена!" << endl;
                pressAnyKey();
                break;
            // Удалить в БД запись
            case '4':
                // если в потоке ввода остались символы, то мы их удаляем (игнорируем)
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if (numRows)
                    if (!db.isEmpty()) numRows = mandb.delManual(db);
                    else cout << "База пуста!" << endl;
                else
                    cout << "База не загружена!" << endl;
                // Для того, чтобы не пришлось нажимать два раза клавишу Enter
                // помещаем символ переноса строки \n во входной поток
                cin.putback('\n');
                pressAnyKey();
                break;
            // Редактировать в БД запись
            case '5':
                // Если в потоке ввода остались символы, то мы их удаляем (игнорируем)
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if (numRows)
                    if (!db.isEmpty()) mandb.modManual(db);
                    else cout << "База пуста!" << endl;
                else
                    cout << "База не загружена!" << endl;
                // Для того, чтобы не пришлось нажимать два раза клавишу Enter
                // помещаем символ переноса строки \n во входной поток
                cin.putback('\n');
                pressAnyKey();
                break;
            // Поиск в БД записи
            case '6':
                // если в потоке ввода остались символы, то мы их удаляем (игнорируем)
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if (numRows)
                    if (!db.isEmpty()) mandb.findManual(db);
                    else cout << "База пуста!" << endl;
                else
                    cout << "База не загружена!" << endl;
                // Для того, чтобы не пришлось нажимать два раза клавишу Enter
                // помещаем символ переноса строки \n во входной поток
                cin.putback('\n');
                pressAnyKey();
                break;
            // Выводим содержимое БД на экран
            case '7':
                cout.flush();
// В случае разных ОС компилятор выберет подходящий
// способ очистки экрана
#ifdef __linux__
                system("clear");
#elif __windows__
                system("cls");
#endif
                if (numRows)
                    if (!db.isEmpty()) db.displayALL();
                    else cout << "База пуста!" << endl;
                else
                    cout << "База не загружена!" << endl;
                pressAnyKey();
                break;
            // Выводим информацию об авторе
            case '8':
                about();
                pressAnyKey();
                break;
            // Выходим из меню установив "exit_menu" в false.
            // При следующей проверки условия в заголовке цикла
            // будет произведён выход
            case '9':
                exit_menu = false;
                break;
        }
    }

    return 0;
}

void Menu::about()
{
    // Выводим информацию об авторе
    cout << "Автор: ст. преподаватель каф. ИСТАС Садовский Б. С." << std::endl;
}

void Menu::pressAnyKey()
{
    // Сбросим содержимое буфера вывода, если там что-нибудь есть
    cout.flush();
    cout << "\nНажмите любую клавишу для продолжения..." << std::endl;

    // Сброс специальных битов (goodbit, eofbit, failbit, badbit) ввода для предотвращения зацикливания
    // при вводе некорректных символов
    cin.clear();

    // Если в потоке ввода остались символы, то мы их удаляем (игнорируем)
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Ожидания ввода пользователя
    cin.get();

// В случае разных ОС компилятор выберет подходящий
// способ очистки экрана
#ifdef __linux__
    system("clear");
#elif __windows__
    system("cls");
#endif
}
