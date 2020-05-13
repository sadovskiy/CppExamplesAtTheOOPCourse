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

// В конструкторе делаем инициализацию списка "a",
// забивая указатели на начало/конец списка и количество элементов нулями
B::B(): first(0), last(0), nextSlot(0), numColumns(0)
{

}

// Копируем знацение из другого объекта по элементно
B::B(const B& other): first(0), last(0), nextSlot(0), numColumns(other.numColumns)
{
    for (   listA* current = other.first;
            current;
            current = current->next) {
                // Для создания нового элемента просто используем
                // метод add()
                add(current->a.getStr(), current->a.getbNum());

    }
}

// При работе с диномический выделяемой памятью в деструктор
// обязательно помещаются операторы по освобождению памяти
B::~B()
{
    // Удаление элементов начинаем с конца списка
    for (   listA* current = last;
            current;
            current = current->prior) {
            // Если элемент остался один в списке
            if (current->next == current->prior) {
                first = last = 0;
                delete current;
            }
            // Если элементы ещё есть перед текущим
            else {
                listA* prior = current->prior;
                prior->next = current->next;
                last = prior;
                delete current;
            }
    }
}

// Копируем значение из другого объекта поэлементно
B& B::operator=(const B& rhs)
{
    // Предварительно убеждаемся, что это другой объект
    if (this == &rhs) return *this;

    numColumns = rhs.numColumns;

    for (   listA* current = rhs.first;
            current;
            current = current->next) {
                add(current->a.getStr(), current->a.getbNum());

    }

    return *this;
}

// Описываем метод добавления элемента в список,
// при этом надо обязательно передать строку и значение
// логической переменной
A& B::add(const string m_str,
                    const bool m_bnum)
{
    // Создаём в динамической памяти новый элемент
    listA* newA = new listA;
    // Проверяем есть ли ещё место в папяти
    if (!newA) {
        cerr << "List is full!" << endl; // "Список заполнен!"
        return aNull;
    }

    // Вставляем преданные значения для нового элемента
    // при этом увеличиваем счётчик элементов
    newA->a.setNum(nextSlot++);
    newA->a.setStr(m_str);
    newA->a.setbNum(m_bnum);
    // Так как отсчёт начинается с нуля передаём счётчику "n" на единицу меньше
    newA->n = nextSlot;

    // Включаем новый элемент в конец списка
    newA->next = 0;
    newA->prior = last;

    if (!first)
        first = newA;
    else
        last->next = newA;
    last = newA;

    numColumns = 3;

    // возвращаем ссылку на вновь созданныей элемент
    return newA->a;
}

// Метод редактирования элемента в списке.
// Первый аргумент отвечает за порядковый номер элемента
// в списке, а второй за выбранныей пользователем значениеi,
// подлежащее редактированию
A& B::mod(const size_t numSlot, const int picked, const string& newString)
{
    // Создаём переменную, которая в случае, если элемент не найден,
    // будет выдавать сообщение и завершать метод поиска
    bool findSuccess = false;

    listA* current = 0;
    // Ищем элемент в списке
    for (current = first; current; current = current->next)
        if(current->n == numSlot){
            // Если находим то сохраняем
            // флаг, об успешном поиске
            findSuccess = true;
            break;
        }

    // Если элемент не найден, то выводим сообщение и выходим из метода
    if (!findSuccess) {
        cout << "Item not found!" << endl; // "Запись не найдена!"
        return aNull;
    }

    // Переходим к выбранному из 3-х значений элемента в списке "a",
    // который будем изменять
    switch (picked){
        case 0:
            // и сохраняем её в элемент
            current->a.setStr(newString);
            break;
        case 1: {
            // Для конвертации из строки в число, используем строковые потоки
            istringstream ist(newString);
            int newNum;
            ist >> newNum;
            current->a.setNum(newNum);
        }
            break;
        case 2:
                current->a.setbNum((bool)atoi(newString.c_str()));
            break;
        // В случае, если было передано некорректное значение
        // выдаём пользователю предупреждение
        // "Такого значения нет в \"A\"!"
        default: cout << "This value is not in \"A\"!" << endl;
            break;
    }

    // При выходе делаем возврат изменённого значения
    return current->a;
}

// Описание метода поиска по индексу,
// который в случае успеха возвращает ссылку на элемент
// в случае если элемент не нашолся то ссулку на пустой элемент
A& B::find(const size_t numSlot)
{
    for (listA* current = first; current; current = current->next)
        if ((size_t)current->a.getNum() == numSlot)
            return current->a;

    cout << "Data not found!" << endl; // "Данные не найдены!"
    return aNull;
}

// Описание метода поиска по индексу вариант возвращающий константу
const A& B::find(const size_t numSlot) const
{
    for (listA* current = first; current; current = current->next)
        if ((size_t)current->a.getNum() == numSlot)
            return current->a;

    cout << "Data not found!" << endl; // "Данные не найдены!"
    return aNull;
}

// Описание метода поиска по строке
// При нахождении в списке нескольких элементов с одинаковой строкой,
// находится будет только первая из них.
A& B::find(const string str)
{
    for (listA* current = first; current; current = current->next)
        if (current->a.getStr() == str)
            return current->a;

    cout << "Data not found!" << endl; // "Данные не найдены!"
    return aNull;
}

// Описание метода изменение логической переменной, по её индексу на true
A& B::tdata(const size_t numSlot)
{
    // Так как метод поиска у нас уже есть, то можно воспользоваться им
    // а не писать реализацию поиска заново
    A& tmp = find(numSlot);
    // В найденом элементе устанавливаем значение true
    if (&tmp != &aNull)
        tmp.tbNum();

    return tmp;
}

// Описание метода изменения логической переменной по её индексу на false
A& B::pdata(const size_t numSlot)
{
    A& tmp = find(numSlot);
    if (&tmp != &aNull)
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
    for (listA* current = first; current; current = current->next)
        if(current->n == numSlot){
                // Если элемент не является последним или первым
                if (current->next && current->prior) {
                    listA* next = current->next;
                    listA* prior = current->prior;
                    next->prior = current->prior;
                    prior->next = current->next;
                }
                else
                    // Если элемент один в списке
                    if (current->next == current->prior) {
                        first = last = 0;
                        findIndex = current->n;
                        delete current;
                        findSuccess = true;
                        break;
                    }
                    else {
                        // Если элемент первый
                        if (current == first) {
                            listA* next = current->next;
                            next->prior = current->prior;
                            first = next;
                        }
                        // Если элемент последний
                        if (current == last ) {
                            listA* prior = current->prior;
                            prior->next = current->next;
                            last = prior;
                        }
                    }
                // Сохраняем индекс удаляемого элемента,
                // удаляем и отмечаем успешное удаление
                findIndex = current->n;
                delete current;
                findSuccess = true;
                break;
        }

    // Выводим сообщение об успешном удалении
    if (findSuccess) {
        nextSlot--;
        // cout << "Данные № " << findIndex << " удалены успешно." << endl;
        cout << "Data # " << findIndex << " successfully deleted." << endl;
        // Пересчёт индексов после удаления элемента

        recalcIndex();

        return true;
    }

    return false;
}

// Метод производит перерасчёт индексов в списке
void B::recalcIndex(const size_t numSlot)
{
    listA* current = first;
    register size_t i = 0;
    if (!numSlot) cout << "Recalculating indexes first" << endl;

    while (current) {
            current->n = i++;
            cout << current->n << " ";
            current = current->next;
        }
    cout << "\nИндексы пересчитаны." << endl;
}

// Метод описывает вывод на экран всех элементов
void B::displayALL() const
{
    for (listA* current = first; current; current = current->next) {
        current->a.display();
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

// Описание метода возвращающего текущее количество элементов в базе
size_t B::getNumSlots() const
{
    return nextSlot;
}


// Описание метода возвращающего текущее количество значений (полей) в элементе (записи)
size_t B::getNumColumns() const
{
    return numColumns;
}

// Описание метода проверяющего заполнен ли список "a"
// при использовании динамической памяти список является бесконечным
// по этом можно проверить можно ли ещё выделить памяти.
bool B::isFull() const
{
    listA* n = 0;
    n = new listA;
    if (n) {
        delete n;
        return true;
    }
    else {
        delete n;
        return false;
    }
}

// Описание метода проверяющего пуст ли список "a"
bool B::isEmpty() const
{
    return (bool)(first == 0);
}


