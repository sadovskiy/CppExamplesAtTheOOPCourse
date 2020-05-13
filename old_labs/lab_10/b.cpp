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

#include <algorithm>
#include <cctype>
#include <limits>
#include <sstream>

#include "b.hpp"

using namespace std;

// В конструкторе делаем поэлементно инициализацию массива "a",
// забивая его значения нулями,
// пустыми строчками и значениями false
B::B(): nextSlot(0)
{
    for (register size_t i = 0; i < Max; i++) {
        a[i].setNum(0);
        a[i].setStr("");
        a[i].pbNum();
    }
}

// Копируем значение из другого объекта поэлементно
B::B(const B& other): nextSlot(other.nextSlot)
{
    for (register size_t i = 0; i < nextSlot; i++) {
        a[i].setNum(i);
        a[i].setStr(other.a[i].getStr());
        a[i].setbNum(other.a[i].getbNum());
    }
}

B::~B()
{

}

// Копируем значение из другого объекта поэлементно
B& B::operator=(const B& rhs)
{
    // Предварительно убеждаемся, что это другой объект
    if (this == &rhs) return *this;

    nextSlot = rhs.nextSlot;
    for (register size_t i = 0; i < nextSlot; i++) {
        a[i].setNum(i);
        a[i].setStr(rhs.a[i].getStr());
        a[i].setbNum(rhs.a[i].getbNum());
    }

    return *this;
}

// Описываем метод добавления элемента в массив,
// при этом надо обязательно передать строку и значение
// логической переменной
A& B::add(const string m_str, const bool m_bnum)
{
    // Проверяем, есть ли ещё место в массиве
    if (isFull()) {
        cerr << "List is full!" << endl; // "Список заполнен!"
        return aNull;
    }
    // Добавляем новый элемент
    // при этом увеличиваем счётчик элементов
    // и вставляем в новый элемент переданные данные
    A& newA = a[nextSlot++];
    newA.setNum(nextSlot);
    newA.setStr(m_str);
    newA.setbNum(m_bnum);

    // Возвращаем ссылку на вновь созданный элемент
    return newA;
}

// Метод редактирования элемента в массиве.
// Первый аргумент отвечает за порядковый номер элемента
// в массиве, а второй за выбранное пользователем значение,
// подлежащее редактированию
A& B::mod(const size_t numSlot, const int picked, const string& newString)
{
    // Создаём переменную, которая в случае, если элемент не найден,
    // будет выдавать сообщение и завершать метод поиска
    bool findSuccess = false;
    // Индекс найденного элемента
    int findIndex = 0;

    // Ищем элемент в массиве
    for (register size_t i = 0; i < nextSlot; i++)
        if((size_t)a[i].getNum() == numSlot){
            // Если находим, то сохраняем его индекс и сохраняем
            // флаг об успешном поиске
            findIndex = i - 1;
            findSuccess = true;
            break;
        }

    // Если элемент не найден, то выводим сообщение и выходим из метода
    if (!findSuccess) {
        cout << "Item not found!" << endl; // "Запись не найдена!"
        return aNull;
    }

    // Переходим к выбранному из 3-х значений элемента в массиве "a",
    // который будем изменять
    switch (picked - 1){
        case 0: {
            a[findIndex].setStr(newString);
        }
            break;
        case 1: {
            // Для конвертации из строки в число, используем строковые потоки
            istringstream ist(newString);
            int newNum;
            ist >> newNum;
            a[findIndex].setNum(newNum);
        }
            break;
        case 2: {
            a[findIndex].setbNum((bool)atoi(newString.c_str()));
        }
            break;
        // В случае, если было передано некорректное значение
        // выдаём пользователю предупреждение
        // "Такого значения нет в \"A\"!"
        default: cout << "This value is not in \"A\"!" << endl;
            break;
    }

    // При выходе делаем возврат изменённого значения
    return a[findIndex];
}

// Описание метода поиска по индексу
A& B::find(const size_t numSlot)
{
    for (register size_t i = 0; i < nextSlot; i++)
        if((size_t)a[i].getNum() == numSlot){
            return a[i];
        }
    cout << "Data not found!" << endl; // "Данные не найдены!"
    return aNull;
}

// Описание метода поиска по индексу вариант возвращающий константу
const A& B::find(const size_t numSlot) const
{
    for (register size_t i = 0; i < nextSlot; i++)
        if((size_t)a[i].getNum() == numSlot){
            return a[i];
        }
    cout << "Data not found!" << endl; // "Данные не найдены!"
    return aNull;
}

// Описание метода поиска по строке
// При нахождении в массиве нескольких элементов с одинаковой строкой,
// находится будет только первая из них.
A& B::find(const string str)
{
    for (register size_t i = 0; i < nextSlot; i++)
        if(a[i].getStr() == str)
            return a[i];
    cout << "Data not found!" << endl; // "Данные не найдены!"
    return aNull;
}

// Описание метода, выдающего ссылку элемента из массива
// по индексу без перебора всего массива
A& B::get(const size_t numSlot)
{
    return a[numSlot];
}

// Описание метода изменения логической переменной по её индексу на true
A& B::tdata(const size_t numSlot)
{
    // Так как метод поиска у нас уже есть, то можно воспользоваться им,
    // а не писать реализацию поиска заново
    A& tmp = find(numSlot);
    // В найденом элементе устанавливаем значение true
    if (&tmp != a)
        tmp.tbNum();

    return tmp;
}

// Описание метода изменения логической переменной по её индексу на false
A& B::pdata(const size_t numSlot)
{
    A& tmp = find(numSlot);
    if (&tmp != a)
        tmp.pbNum();

    return tmp;
}

// Описание метода удаления элемента по его индексу
bool B::del(const size_t numSlot)
{
    // При удалении элемента из массива ищем его, удаляем и сдвигаем элементы,
    // расположенные после него на его место
    bool findSuccess = false;
    int findIndex = 0;
    for (register size_t i = 0; i < nextSlot; i++)
        if((size_t)a[i].getNum() == numSlot){
            findIndex = a[i].getNum();
            findSuccess = true;
            break;
        }

    // Выводим сообщение об успешном удалении
    if (findSuccess) {
        nextSlot--;
        // cout << "Данные № " << findIndex << " удалены успешно." << endl;
        cout << "Data # " << findIndex << " successfully deleted." << endl;

        // Пересчёт индексов после удаления элемента
        // После удаления надо пересчитать индексы
        recalcIndex(numSlot);

        return true;
    }

    return false;
}

// Метод производит перерасчёт индексов в списке
void B::recalcIndex(const size_t numSlot)
{
    for (register size_t i = 0; i < nextSlot; i++)
        if((size_t)a[i].getNum() == numSlot){
            for (register size_t j = i; j < nextSlot; j++) {
                a[j].setNum(a[j + 1].getNum());
                a[j].setStr(a[j + 1].getStr());
                a[j].setbNum(a[j + 1].getbNum());
            }
            break;
        }

    cout << "\nRecalculate indexes." << endl; // "\nИндексы пересчитаны."
}

// Метод описывает вывод на экран всех элементов
void B::displayALL() const
{
    for (register size_t i = 0; i < nextSlot; i++) {
        a[i].display();
        cout << "---" << endl;
    }
}

// Метод, описывающий вывод на экран элемента по его индексу
void B::displayCurrent(const size_t numSlot) const
{
    // Так как в константном методе запрещено вызывать не константные методы,
    // нам выше пришлось перегрузить метод find()
    const A& tmp = find(numSlot);
    tmp.display();
}

// Описание метода, возвращающего текущее количество элементов в базе
size_t B::getNumSlots() const
{
    return nextSlot;
}

// Описание метода, проверяющего заполнен ли массив "a"
bool B::isFull() const
{
    // Для краткости проверяем условия в операторе return
    return (bool)((unsigned)nextSlot == Max);
}

// Описание метода, проверяющего пуст ли массив "a"
bool B::isEmpty() const
{
    return (bool)(nextSlot == 0);
    // Так же можно проверить через a[0].isEmpty();
}

// Описание метода, проверяющего оди ли элемент в массиве "a"
bool B::isFirstLast() const
{
    if (nextSlot == 0)
        return true;
    else
        return false;
}


