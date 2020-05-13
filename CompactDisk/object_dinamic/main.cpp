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

#include <locale>

#include "application.hpp"

using namespace std;

int main()
{
#ifdef __linux__
    std::locale loc("ru_RU.UTF-8");
    std::locale::global(loc);
#endif

    Application app;

    return app.exec();
}
