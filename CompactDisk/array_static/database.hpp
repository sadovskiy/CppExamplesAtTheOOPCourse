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

#ifndef DATABASE_H
#define DATABASE_H

#include "compactdisk.hpp"

const unsigned short MaxDisks = 100; // максимальное количество дисков в базе

class DataBase
{
        TCompactDisk disk[MaxDisks];
        int nextSlot;
    public:
        DataBase();
        virtual ~DataBase();
        DataBase(const DataBase& other);
        DataBase& operator=(const DataBase& other);

        TCompactDisk& addDisk(const std::wstring recNameDisk,
                            const TCompactDisk::physicalSize pSize,
                            const TCompactDisk::mediaType mType,
                            const bool rec);
        TCompactDisk& modDisk(int numSlot, const int menu);
        TCompactDisk& findDisk(int numSlot);
        TCompactDisk& takeDisk(int numSlot);
        TCompactDisk& placeDisk(int numSlot);
        TCompactDisk& findDisk(const std::wstring nameDisk);

        bool delDisk(int numSlot);

        void displayALL() const;
        void displayCurrent(int numSlot) const;

        bool isFull() const;
        bool isEmpty() const;

};

#endif // DATABASE_H
