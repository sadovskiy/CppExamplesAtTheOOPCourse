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

#include "file.hpp"

using namespace std;

// Реализуем инициализацию данных в
// конструкторе по умолчанию
// через список инициализаторов
A::A(): strSlot("")
{

}

// Тоже самое для конструктора с параметром (параметризованного конструктора)
A::A(const string str): strSlot(str)
{

}

// Тоже самое для конструктора копирования
A::A(const A& a): strSlot(a.strSlot)
{

}

A::~A()
{

}

A& A::operator=(const A& rhs)
{
    // Делаем проверку. Является ли объект, из которого
    // копируются данные тем же самым объектом, в который копируются?
    // Если да, то необходимости в копировании нет, и мы выходим из метода
    if (this == &rhs)
        return *this;

    // Копируем поэлементно
    strSlot = rhs.strSlot;

    // Выходим из метода с передачей указателя
    return *this;
}

A A::operator+(const A& rhs)
{
    // Создаём временную строку, в которую помещаем результат конкатенации
    string tmpStr = strSlot + " " + rhs.strSlot + "!";

    return tmpStr;
}

// Для реализации возможности вывода вида "cout << a;"
// необходимо сделать функцию из двух аргументов.
// Первый аргумент - это поток вывода, а второй, то что надо вывести
void operator<<(ostream& os, const A& rhs)
{
    // Помещаем в поток вывода
    os << rhs.strSlot << endl;
}


string A::getStr() const
{
    return strSlot;
}

void A::setStr(const string str)
{
    strSlot = str;
}

void A::show() const
{
    cout << strSlot << endl;
}
