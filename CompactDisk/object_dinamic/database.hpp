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

#ifndef DATABASE_H
#define DATABASE_H

#include "compactdisk.hpp"

class DataBase
{
        struct Node // структура используется для создания двусвязного списка
        {
            TCompactDisk disk; 	// хранение данных о компакт дисках
            struct Node *next; // следующий диск
            struct Node *prior;// предыдущий диск
        };
        Node *firstDisk; 	// первый диск
        Node *lastDisk;	// последний диск
        mutable unsigned long countSlots; // количество дисков
    public:
        DataBase();
        ~DataBase();
        DataBase(			const DataBase& other);
        DataBase& operator=(const DataBase& other);

        // добавить диск
        TCompactDisk& addDisk(	const std::wstring &recNameDisk,
                            const TCompactDisk::physicalSize pSize,
                            const TCompactDisk::mediaType mType);

        TCompactDisk& modDisk(const int numSlot, const int menu);	// изменить данные о диске
        TCompactDisk* findDisk(const int numSlot);					// найти диск по номеру
        TCompactDisk* findDisk(const std::wstring &nameDisk);	// найти диск по имени
        int		 findDisk(const TCompactDisk& tdisk);		// найти диск по адресу
        TCompactDisk* takeDisk(const int numSlot);					// взять диск из базы
        TCompactDisk* placeDisk(const int numSlot);				// положить диск в базу
        bool delDisk(int numSlot);						// удалить диск

        void displayALL() const;					// вывести на монитор всю базу дисков
        void displayCurrent(const int numSlot) const;		// вывести на монитор конкретный диск из базы

        bool isEmpty() const;					// проверка пуста ли база
        bool isFull() const;					// проверка заполнена ли база
        unsigned long itemCount() const;		// пересчёт дисков в базе
        unsigned long statItemCount() const;	// количество дисков в баззе

        TCompactDisk& getDisk() const;
};

#endif // DATABASE_H
