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

#ifndef DATABASE_H
#define DATABASE_H

// Подкючаем .h файл, в котором находится интерфейс
// класса "ComputerCase"
#include "computercase.hpp"

// Создаём константу указания размера для
// автоматического массива агрегированного
// в классе "DataBase"
const size_t Max = 20;

// Класс является моделью базы данных
class DataBase
{
        // Создаём элемент списка из ComputerCaseList
        // через агрегацию
        class ComputerCaseList
        {
            public:
            // Порядковый номер элемента в списке
            size_t n;
            // Элемент, в котором хранятся наши данные
            ComputerCase cc;
            ComputerCaseList* next;
            ComputerCaseList* prior;
        };

        // Указатели на начало и конец списка
        ComputerCaseList* first;
        ComputerCaseList* last;

        // Переменная, отвечающая за текущее количество
        // элементов в массиве "cc"
        size_t nextSlot;
        // Переменная, отвечающая за количество данных
        // внутри одного элемента
        size_t numColumns;
        // Пустой элемент для возврата по ссылке, если подходящего
        // элемента не нашлось
        ComputerCase ccNull;
    public:
        DataBase();
        DataBase(const DataBase& other);
        ~DataBase();

        DataBase& operator=(const DataBase& other);

        // Метод добавления элемента в "DataBase"
        ComputerCase& add(  const std::string _manufacturer,
                            const std::string _model,
                            const std::string _color,
                            const ComputerCase::materialType _material,
                            const ComputerCase::typeType _type,
                            const ComputerCase::formFactorType _formFactor,
                            const float _metalThickness,
                            const ComputerCase::unit __525InchBay,
                            const ComputerCase::unit __35InchBay,
                            const ComputerCase::unit __35InchBayIn,
                            const ComputerCase::unit _PCISlots,
                            const bool _possibilityOfWaterCooling,
                            const bool _featurePSU,
                            const float _Depth,
                            const float _Width,
                            const float _Height);
        // Метод редактирования элемента в "DataBase"
        ComputerCase& mod(const size_t numSlot, const int picked, const std::string& newString);
        // Метод поиска элемента в "DataBase" по номеру
        ComputerCase& find(const size_t numSlot);
        const ComputerCase& find(const size_t numSlot) const;
        // Метод поиска элемента в "DataBase" по производителю и названию
        ComputerCase& findByManufacturer(const std::string _manufacturer);
        ComputerCase& findByModel(const std::string _model);

        // Метод, возвращающий ссылку на элемент списка по его индексу
        ComputerCase& get(const size_t numSlot);
        const ComputerCase& get(const size_t numSlot) const;

        // Метод, возвращающий ссылку на последний вызывавшийся элемент списка
        // с перебором по значениям элемента
        ComputerCase& get();

        // Метод удаление элемента из "DataBase"
        bool del(const size_t numSlot);

        // Метод вывода не экран всех имеющихся элементов в "DataBase"
        void displayALL() const;
        // Метод вывода на экран одного элемента по его номеру
        void displayCurrent(const size_t numSlot) const;

        // Метод возвращающий количество элементов в базе данных
        size_t getNumSlots() const;
        // Метод возвращающий количество значений (полей) в элементе (записи)
        size_t getNumColumns() const;

        // Метод пересчёта индексов в списке
        void recalcIndex(const size_t numSlot = 0);

        // Метод проверки заполнен ли массива "DataBase"
        bool isFull() const;
        // Метод проверки пустой ли массив "DataBase"
        bool isEmpty() const;
        // Метод проверки состоит ли список из одного элемента
        bool isFirstLast() const;
};

#endif // DATABASE_H
