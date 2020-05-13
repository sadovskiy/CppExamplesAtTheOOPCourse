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

#include "application.hpp"

using namespace std;

Application::Application(): database(), nameDataBase(L"")
{
    // в конструкторе указываем имя БД или выходим
    bool done = false;
    while (!done) {
        int ch = 0;
        system("clear");
        wcout << L"--------------------------------------------------------------------------------" <<endl;
        wcout << L"Задайте имя базы данных." << endl;
        wcout << L"--------------------------------------------------------------------------------" << endl;
        wcout << L"Укажите номер пункта меню:" << endl << endl;
        wcout << L"1) Задать имя базы данных." << endl;
        wcout << L"2) Выход." << endl;
        ch = wcin.get();
        switch (ch) {
        case '1':
            wcout << L"Введите имя базы данных: ";
            wcin >> nameDataBase;
            done = true;
            break;
        case '2':
            exit(EXIT_SUCCESS);
            break;
        default:
            wcerr << L"Неизвестный пункт меню!" << endl;
            cin.clear();

        }
    }
}

Application::~Application()
{
    //dtor
}

Application::Application(const Application& other): database(other.database)
{
    //copy ctor
}

Application& Application::operator=(const Application& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

bool Application::exec()
{
    return itemsMenu(	5, // сколько всего пунктов меню и вызовов функций соответственно
                        &Application::changefile,
                        &Application::file,
                        &Application::manageDB,
                        &Application::display,
                        &Application::exitApp);
}

unsigned int Application::displayMenu(	const unsigned short count,
                                        int (Application::*pf)())
{
    int i = 0;
    wchar_t selection;

    wcout << L"--------------------------------------------------------------------------------" <<endl;
    wcout << L"Главное меню программы." << endl;
    wcout << L"--------------------------------------------------------------------------------" << endl;
    wcout << L"База данных: " << nameDataBase << endl;
    wcout << L"--------------------------------------------------------------------------------" << endl;
    wcout << L"Укажите номер пункта меню." << endl << endl;

    wchar_t mainitems[][100] = {L"1) Изменить имя БД.",
                                L"2) Управление файлом БД.",
                                L"3) Управление БД.",
                                L"4) Вывести на экран данные.",
                                L"5) Выход."};

    wchar_t fileitems[][100] = {L"1) Загрузить данные в БД из файла.",
                                L"2) Сохранить данные из БД в файл.",
                                L"3) Назад."};

    wchar_t edititems[][100] = {L"1) Добавить запись.",
                                L"2) Редактировать запись.",
                                L"3) Удалить запись.",
                                L"4) Поиск записи.(по номеру)",
                                L"5) Поиск записи.(по названию)",
                                L"6) Взять диск из БД.",
                                L"7) Положить диск в БД.",
                                L"8) Назад."};
    // далее определяется какое меню отобразить по первому пункту этого меню
    if (&Application::changefile == pf) {
        while (i < count) {
            wcout << mainitems[i] << endl;
            i++;
        }
    }
    if (&Application::loadfile == pf)
        while (i < count) {
            wcout << fileitems[i] << endl;
            i++;
        }
    if (&Application::addDB == pf)
        while (i < count) {
            wcout << edititems[i] << endl;
            i++;
        }

    wcin >> selection; // передача управления пользователю

    wchar_t *endString = 0;

    int n = 0;

    n = wcstol(&selection, &endString, 3);

    return n;
}

int Application::itemsMenu(const unsigned short count, int (Application::*pf)(), ...)
{
    // Список номеров меню
    struct itemList
    {
        unsigned int item;	// номер пункта меню
        int (Application::*pfunction)();// указатель на вызываемую функцию
        itemList *next;
    };

    itemList *first = 0;
    itemList *last = 0;
    // Для первого пункта меню получаем его номер и функцию которую надо вызвать
    int i = 0;
    int done = true;
    va_list aptr;
    va_start(aptr, pf);
    itemList *newItem = new itemList;
    newItem->item = i;
    newItem->next = 0;
    newItem->pfunction = pf;
    first = last = newItem;
    i++;
    // Для всех остальных пунктов
    while (i < count) {
        int (Application::*pfunction)();
        pfunction = va_arg(aptr, int (Application::*)());
        if (!pfunction) break;
        itemList *newItem = new itemList;
        newItem->item = i;
        newItem->next = 0;
        newItem->pfunction = pfunction;
        last->next = newItem;
        last = newItem;
        i++;
    }

    // цикл самого меню
    bool notItem = true; // если введены не корректные данные пользователем
    while (!((done == EXIT_MENU)||(done == EXIT_SUCCESS))) {
        system("clear");
        unsigned int item = displayMenu(i, pf);

        for (	itemList *currentItem = first;
                currentItem;
                currentItem = currentItem->next)
            if (currentItem->item == (item - 1)) {
                int n = (this->*currentItem->pfunction)();

                if (n == BACK_SUCCESS) // если вызванная функция требует возврата из подменю
                    done = EXIT_MENU;
                if (n == EXIT_SUCCESS) // если функция требует закрытия программы
                    done = EXIT_SUCCESS;
                if (n == STOP) // если функция требует остаться в подменю
                    done = STOP;

                notItem = false; // данные были введены корректно
                break;
            }
        if (notItem) {
            wcerr << L"Нет такого пункта в меню!" << endl;
            // FIXME: заменить sleep()
        }
    }

    // удаление меню
    for (	itemList * current = first, * next;
            current;
            current = next) {
        next = current->next;
        delete current;
    }

    va_end(aptr);
    if (done == EXIT_MENU)
        done = STOP;

    return done;
}

int Application::changefile() // изменяем имя БД
{
    wcout << L"Введите имя базы данных: ";
    wcin >> nameDataBase;

    wcout << L"Имя базы данных изменено на: " << nameDataBase << endl;
    // FIXME: заменить sleep()

    return STOP;
}

int Application::file() // создаём подменю управления файлом БД
{
    return itemsMenu(3, &Application::loadfile,
                     &Application::savefile,
                     &Application::backApp);
}

int Application::loadfile() // загрузка базы
{
    wstring nameDB = nameDataBase + L".db";
    char* ascii = new char[wcslen(nameDB.c_str()) + 1];
    wcstombs( ascii, nameDB.c_str(), wcslen(nameDB.c_str()) );

    wfstream oDBf(ascii, ios_base::in);

    if (!oDBf.is_open()) {
        wcerr << L"Не удалось открыть Файл!" << endl;
        // FIXME: заменить sleep()
        return EXIT_FAILURE;
    }

    int lbegin;
    int lend;
    int i = 0;
    lbegin = lend = 0;


    wstring str;
    while (!oDBf.eof()) {
        TCompactDisk& new_cd =  database.addDisk(L"", TCompactDisk::standard, TCompactDisk::audio_cd); // база уже существует
        // и мы просто создаём в ней пустую запись
        // поскольку файл текстовой то нужно 			// и сохраняем в эту запись данные из файла
        // делать перевод из текста в данные			// пока файл не закончится читая его построчно
        str = L"";
        getline(oDBf, str);
        lend = str.find_first_of(L";");
        new_cd.setNameDisk(str.substr(lbegin, lend));
        str.erase(lbegin, lend + 1);

        lend = str.find_first_of(L";");
        if (str.substr(lbegin, lend) == L"12")
            new_cd.setPhysicalSize(TCompactDisk::standard);
        else
            if (str.substr(lbegin, lend) == L"8")
                new_cd.setPhysicalSize(TCompactDisk::mini_cd);
            else {
                wcerr << L"Ошибка ввода в PhsicalSize!" << endl;
                wcerr << L"В поле 2 строке " << i
                      << L" находятся значение: " << str.substr(lbegin, lend)
                      << endl;
                // FIXME: заменить sleep()
            }
        str.erase(lbegin, lend + 1);

        lend = str.find_first_of(L";");
        if (str.substr(lbegin, lend) == L"0")
            new_cd.setMediaType(TCompactDisk::audio_cd);
        else
            if (str.substr(lbegin, lend) == L"1")
                new_cd.setMediaType(TCompactDisk::photo_cd);
            else
                if (str.substr(lbegin, lend) == L"2")
                    new_cd.setMediaType(TCompactDisk::video_cd);
                else
                    if (str.substr(lbegin, lend) == L"3")
                        new_cd.setMediaType(TCompactDisk::cd_rom);
                    else
                        if (str.substr(lbegin, lend) == L"4")
                            new_cd.setMediaType(TCompactDisk::cdr);
                        else
                            if (str.substr(lbegin, lend) == L"5")
                                new_cd.setMediaType(TCompactDisk::cdrw);
                            else {
                                wcerr << L"Ошибка ввода в MediaType!" << endl;
                                wcerr << L"В поле 3 строке " << i
                                      << L" находятся значение: " << str.substr(lbegin, lend)
                                      << endl;
                                // FIXME: заменить sleep()
                            }
        str.erase(lbegin, lend + 1);

        lend = str.find_first_of(L";");
        if (str.substr(lbegin, lend) == L"1")
            new_cd.setFeature(true);
        else
            if (str.substr(lbegin, lend) == L"0")
                new_cd.setFeature(false);
            else {
                wcerr << L"Ошибка ввода в Feature!" << endl;
                wcerr << L"В поле 4 строке " << i
                      << L" находятся значение: " << str.substr(lbegin, lend)
                      << endl;
                // FIXME: заменить sleep()
            }
        i++;
        new_cd.setNumDisk(i);
    }

    oDBf.close();
    return BACK_SUCCESS;
}

int Application::savefile() // сохранение базы
{
    wstring nameDB = nameDataBase + L".db";
    char *ascii = new char[wcslen(nameDB.c_str()) + 1];
    wcstombs( ascii, nameDB.c_str(), wcslen(nameDB.c_str()) );

    wfstream iDBf(ascii, ios_base::out);

    if (!iDBf.is_open()) {
        wcerr << L"Не удалось открыть Файл!" << endl;
        // FIXME: заменить sleep()
        return EXIT_FAILURE;
    }
    //    ascii.lithe();
    unsigned int i = 1;
    while (i < database.statItemCount()) {
        TCompactDisk& tempcd = database.getDisk(); // каждый раз получаем следующий в списке диск
        iDBf << tempcd.getNameDisk() << L";"
             << tempcd.getPhysicalSize() << L";"
             << tempcd.getMediaType() << L";"
             << tempcd.getFeature() << endl;
        i++;
    }
    TCompactDisk& tempcd = database.getDisk(); // каждый раз получаем следующий в списке диск
    iDBf << tempcd.getNameDisk() << L";"
         << tempcd.getPhysicalSize() << L";"
         << tempcd.getMediaType() << L";"
         << tempcd.getFeature();

    iDBf.close();

    return BACK_SUCCESS;
}

int Application::manageDB()
{
    // вызываем подменю управления записью в базе компакт-дисков
    return itemsMenu(	8,
                        &Application::addDB,
                        &Application::modDB,
                        &Application::delDB,
                        &Application::findNumDB,
                        &Application::findNameDB,
                        &Application::takeDB,
                        &Application::placeDB,
                        &Application::backApp);
}

int Application::addDB() // добавить запись о компакт-диске
{
    wstring name, data;
    TCompactDisk::physicalSize ps;
    TCompactDisk::mediaType mt;
    wcout << L"Введите название диска" << endl;
    wcin >> name;
    wcout << L"Введите размер диска" << endl;
    wcin >> data;
    if (data == L"12")
        ps = TCompactDisk::standard;
    else
        if (data == L"8")
            ps = TCompactDisk::mini_cd;
        else {
            wcerr << L"Ошибка ввода в MediaType!" << endl;
            wcerr << L"В поле data"
                  << L" находятся значение: " << data
                  << endl;
            // FIXME: заменить sleep()
            return EXIT_FAILURE;
        }

    wcout << L"Укажите тип диска." << endl;
    wcout << L"0 - аудио диск" << endl;
    wcout << L"1 - фото диск" << endl;
    wcout << L"2 - видео диск" << endl;
    wcout << L"3 - компьютерный диск" << endl;
    wcout << L"4 - записываемый диск" << endl;
    wcout << L"5 - перезаписываемый диск" << endl;
    wcin >> data;

    if (data == L"0")
        mt = TCompactDisk::audio_cd;
    else
        if (data == L"1")
            mt = TCompactDisk::photo_cd;
        else
            if (data == L"2")
                mt = TCompactDisk::video_cd;
            else
                if (data == L"3")
                    mt = TCompactDisk::cd_rom;
                else
                    if (data == L"4")
                        mt = TCompactDisk::cdr;
                    else
                        if (data == L"5")
                            mt = TCompactDisk::cdrw;
                        else {
                            wcerr << L"Ошибка ввода в MediaType!" << endl;
                            wcerr << L"В поле data"
                                  << L" находятся значение: " << data
                                  << endl;
                            // FIXME: заменить sleep()
                            return EXIT_FAILURE;
                        }

    TCompactDisk& newcd = database.addDisk(name, ps, mt);
    wcout << L"В базу был успешно добавлен диск: " << endl;
    newcd.display();
    // FIXME: заменить sleep()

    return BACK_SUCCESS;
}

int Application::modDB() // изменение существующей записи
{
    int num, menu;
    wcout << L"Введите номер диска" << endl;
    wcin >> num;
    wcout << L"Укажите данные которые следует заменить" << endl;
    wcout << L"0 - Название диска" << endl;
    wcout << L"1 - Размер диска" << endl;
    wcout << L"2 - Тип диска" << endl;
    wcin >> menu;

    database.modDisk(num, menu);

    return BACK_SUCCESS;
}

int Application::delDB() // удаление записи
{
    int num;
    wcout << L"Введите номер удаляемого диска." << endl;
    wcin >> num;

    bool done = database.delDisk(num); // используем функцию удаления из БД
    if (done) {
        wcout << L"Был успешно удалён диск под номером: " << num << endl;
        // FIXME: заменить sleep()
    }
    else {
        wcout << L"Диск не найден!" << endl;
        // FIXME: заменить sleep()
    }

    return BACK_SUCCESS;
}

int Application::findNumDB() // поиск диска по номеру
{
    int num;

    wcout << L"Введите номер разыскиваемого диска." << endl;
    wcin >> num;

    // если диск найден то возвращается указатель на него или ноль в противном случае
    TCompactDisk * finded = database.findDisk(num);
    if (finded)
        finded->display();
    else {
        // FIXME: заменить sleep()
        return BACK_FAILURE;
    }

    return BACK_SUCCESS;
}

int Application::findNameDB() // поиск диска по названию
{
    wstring num;
    wcout << L"Введите название разыскиваемого диска." << endl;
    wcin >> num;

    // если диск найден то возвращается указатель на него или ноль в противном случае
    TCompactDisk * finded = database.findDisk(num);
    if (finded)
        finded->display();
    else {
        // FIXME: заменить sleep()
        return BACK_FAILURE;
    }

    return BACK_SUCCESS;
}

int Application::takeDB() // диск забрали
{
    int num;
    wcout << L"Введите номер диска который хотите забрать." << endl;
    wcin >> num;

    // если диск найден то возвращается указатель на него или ноль в противном случае
    TCompactDisk * taked = database.takeDisk(num);
    if (taked)
        taked->display();
    else {
        // FIXME: заменить sleep()
        return BACK_FAILURE;
    }

    return BACK_SUCCESS;
}

int Application::placeDB() // диск вернули
{
    int num;
    wcout << L"Введите номер диска который хотите вернуть." << endl;
    wcin >> num;
    TCompactDisk * placed = database.placeDisk(num);
    if (placed)
        placed->display();
    else {
        // FIXME: заменить sleep()
        return EXIT_FAILURE;
    }

    return BACK_SUCCESS;
}

int Application::display() // выводим содержимое нашей базы
{
    system("clear");
    database.displayALL();
    wchar_t ch;
    wcout << L"Для продолжения нажмите любую клавишу..." << endl;
    wcin >> ch;

    return STOP;
}

int Application::exitApp() // если выходим из приложения возвращаем соответствующий код
{
    return EXIT_SUCCESS;
}

int Application::backApp() // если выходим из подменю возвращаем соответствующий код
{
    return BACK_SUCCESS;
}
