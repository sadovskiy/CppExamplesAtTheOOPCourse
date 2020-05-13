/*
 * Copyright (C) 2007-2020. GPL
 *
 * Written by Sadovskiy B. S.
 *
 * Права на программу (С) 2007-2020. GPL
 *
 * Написана Садовским Б. С.
 *
 * Пример работы с моделью размещённой в статическом массиве
 *
 *
 */

#include <iostream>
#include <locale>

#include "compactdisk.hpp"
#include "database.hpp"

using namespace std;

int main()
{
#ifdef __linux__
    std::locale loc("ru_RU.UTF-8");
    std::locale::global(loc);
#endif
    DataBase myDB;

    myDB.addDisk(L"Властилин колец. Братство кольца", TCompactDisk::standard, TCompactDisk::video_cd, false);
    myDB.addDisk(L"Болванка", TCompactDisk::standard, TCompactDisk::cdrw, true);
    myDB.addDisk(L"Linux Gentoo", TCompactDisk::mini_cd, TCompactDisk::cdr, true);
    myDB.addDisk(L"Dire Straits", TCompactDisk::standard, TCompactDisk::audio_cd, true);

    if (myDB.isEmpty())
        myDB.displayALL();

    std::wcout << L"-------------" << std::endl;
    TCompactDisk& test = myDB.takeDisk(2);
    test.display();

    std::wcout << L"-------------" << std::endl;
    myDB.placeDisk(2);
    test.display();

    std::wcout << L"-------------" << std::endl;
    TCompactDisk& t = myDB.findDisk(L"fdsa");
    std::wcout << L"-------------" << std::endl;
    t.display();
    std::wcout << L"-------------" << std::endl;
    return 0;
}
