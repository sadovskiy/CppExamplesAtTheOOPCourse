/*
 * Copyright (C) 2007-2020. GPL
 *
 * Written by Sadovskiy B. S.
 *
 * Права на программу (С) 2007-2020. GPL
 *
 * Написана Садовским Б. С.
 *
 * Пример моделирования с помощью класса
 *
 *
 */

#include <iostream>
#include <locale>

#include "compactdisk.hpp"

using namespace std;

int main()
{
#ifdef __linux__
    std::locale loc("ru_RU.UTF-8");
    std::locale::global(loc);
#endif

    TCompactDisk disk(L"Властелин колец. Братство кольца.",
                 TCompactDisk::standard,
                 TCompactDisk::audio_cd,
                 false);

    disk.display();
    wcout << disk;

    return 0;
}
