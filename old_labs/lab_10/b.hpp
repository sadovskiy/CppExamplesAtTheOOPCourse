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

#ifndef B_H
#define B_H

// Подключаем .h файл, в котором находится интерфейс
// класса "A"
#include "a.hpp"

// Создаём константу указания размера для
// автоматического массива агрегированного
// в классе "B"
const unsigned Max = 20;

// Класс является моделью базы данных
class B
{
        // Создаём массив из элементов "a"
        // через агрегацию
        A a[Max];
        // Переменная, отвечающая за текущее количество
        // элементов в массиве "a"
        size_t nextSlot;
        // Переменная, отвечающая за количество данных
        // внутри одного элемента
        size_t numColumns;
        // Пустой элемент для возврата по ссылке, если подходящего
        // элемента не нашлось
        A aNull;
    public:
        B();
        B(const B& other);
        ~B();

        B& operator=(const B& other);

        // Метод добавления элемента в "a"
        A& add( const std::string m_str,
                const bool m_bnum);

        // Метод редактирования элемента в "a"
        A& mod(const size_t numSlot, const int picked, const std::string& newString);
        // Метод поиска элемента в "a" по номеру
        A& find(const size_t numSlot);
        // Метод поиска элемента в "a" по номеру константный вариант
        const A& find(const size_t numSlot) const;
        // Метод поиска элемента в "a" по названию
        A& find(const std::string m_str);
        // Метод, изменяющий значение булевой переменной в "a"
        // на true по его номеру
        A& tdata(const size_t numSlot);
        // Метод, изменяющий значение булевой переменной в "a"
        // на false по его номеру
        A& pdata(const size_t numSlot);

        // Метод, возвращающий ссылку на элемент списка по его индексу
        A& get(const size_t numSlot);
        const A& get(const size_t numSlot) const;

        // Метод, возвращающий ссылку на последний вызывавшийся элемент списка
        // с перебором по значениям элемента
        A& get();

        // Метод удаление элемента из "a"
        bool del(const size_t numSlot = 0);

        // Метод вывода на экран всех имеющихся элементов в "a"
        void displayALL() const;
        // Метод вывода на экран одного элемента по его номеру
        void displayCurrent(const size_t numSlot) const;

        // Метод, возвращающий количество элементов в базе данных
        size_t getNumSlots() const;
        // Метод, возвращающий количество значений (полей) в элементе (записи)
        size_t getNumColumns() const;

        // Метод пересчёта индексов в списке
        void recalcIndex(const size_t numSlot);

        // Метод проверки - заполнен ли массива "a"
        bool isFull() const;
        // Метод проверки - пустой ли массив "a"
        bool isEmpty() const;
        // Метод проверки состоит ли список из одного элемента
        bool isFirstLast() const;
};

#endif // B_H
