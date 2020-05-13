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

#include "database.hpp"

DataBase::DataBase(): nextSlot(0)
{
    //ctor
}

DataBase::~DataBase()
{
    //dtor
}

DataBase::DataBase(const DataBase& other): nextSlot(other.nextSlot)
{
    //copy ctor
}

DataBase& DataBase::operator=(const DataBase& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    nextSlot = rhs.nextSlot;
    return *this;
}

TCompactDisk& DataBase::addDisk(const std::wstring recNameDisk,
                    const TCompactDisk::physicalSize pSize,
                    const TCompactDisk::mediaType mType,
                    const bool rec)
{
    if (nextSlot >= MaxDisks) {
        std::wcerr << L"База заполнена!" << std::endl;
        ;
    }

    TCompactDisk& cdNew = disk[nextSlot++];
    cdNew.setNumDisk(nextSlot);
    cdNew.setNameDisk(recNameDisk);
    cdNew.setPhysicalSize(pSize);
    cdNew.setMediaType(mType);
    cdNew.setRec(rec);
    cdNew.toPlace();

    return cdNew;
}

TCompactDisk& DataBase::modDisk(int numSlot, const int menu)
{
    bool success = false;
    int numSuccessfull = 0;
    for (int i = 0; i < nextSlot; i++)
        if(disk[i].getNumDisk() == numSlot){
            numSuccessfull = i;
            success = true;
        }

    if (!success) {
        std::wcout << L"Диск не найден!" << std::endl;
        return disk[0];
    }
    std::wstring newName;
    TCompactDisk::physicalSize newSize = TCompactDisk::standard;
    int sw = 0;

    TCompactDisk::mediaType newMediaType;
    switch (menu){

        case 0:

            std::wcin >> newName;
            disk[numSuccessfull].setNameDisk(newName);
        break;
        case 1:
            std::wcin >> sw;
            if (sw) newSize = TCompactDisk::mini_cd;
            disk[numSuccessfull].setPhysicalSize(newSize);
        break;
        case 2:

            switch (sw){
                case 0:	newMediaType = TCompactDisk::audio_cd; break;
                case 1:	newMediaType = TCompactDisk::photo_cd; break;
                case 2:	newMediaType = TCompactDisk::video_cd; break;
                case 3:	newMediaType = TCompactDisk::cd_rom; break;
                case 4:	newMediaType = TCompactDisk::cdr; break;
                case 5:	newMediaType = TCompactDisk::cdr; break;
            }
            disk[numSuccessfull].setMediaType(newMediaType);
        break;
        case 3:
            bool newRecordable = false;
            std::wcin >> sw;
            if (sw) newRecordable = true;
            disk[numSuccessfull].setRec(newRecordable);
        break;

    }

    return disk[numSuccessfull];
}

TCompactDisk& DataBase::findDisk(int numSlot)
{
    for (int i = 0; i < nextSlot; i++)
        if(disk[i].getNumDisk() == numSlot){
            return disk[i];
        }
    std::wcout << L"Диск не найден!" << std::endl;
    return disk[0];
}

TCompactDisk& DataBase::findDisk(const std::wstring nameDisk)
{
    for (int i = 0; i < nextSlot; i++)
        if(disk[i].getNameDisk() == nameDisk)
            return disk[i];
    std::wcout << L"Диск не найден!" << std::endl;
    return disk[0];
}

TCompactDisk& DataBase::takeDisk(int numSlot)
{
    for (int i = 0; i < nextSlot; i++)
        if(disk[i].getNumDisk() == numSlot){
            disk[i].toTake();
            return disk[i];
        }
    std::wcout << L"Диск не найден!" << std::endl;
    return disk[0];
}

TCompactDisk& DataBase::placeDisk(int numSlot)
{
    for (int i = 0; i < nextSlot; i++)
        if(disk[i].getNumDisk() == numSlot){
            disk[i].toPlace();
            return disk[i];
        }
    std::wcout << L"Диск не найден!" << std::endl;
    return disk[0];
}

bool DataBase::delDisk(int numSlot)
{
    bool success = false;
    int numSuccessfull = 0;
    for (int i = 0; i < nextSlot; i++)
        if(disk[i].getNumDisk() == numSlot){
            numSuccessfull = disk[i].getNumDisk();
            for (int j = i; j < nextSlot; j++) {
                disk[j].setNumDisk(disk[j + 1].getNumDisk());
                disk[j].setNameDisk(disk[j + 1].getNameDisk());
                disk[j].setPhysicalSize(disk[j + 1].getPhysicalSize());
                disk[j].setMediaType(disk[j + 1].getMediaType());
                disk[j].setRec(disk[j + 1].getRec());
            }
            success = true;
            break;
        }
    if (success) {
        nextSlot--;
        std::wcout << L"Диск № " << numSuccessfull << L" удалён успешно." << std::endl;
        return true;
    }
    return false;
}

void DataBase::displayALL() const
{
    for (int i = 0; i < nextSlot; i++)
        disk[i].display();
}
void DataBase::displayCurrent(int numSlot) const
{
    bool success = false;
    for (int i = 0; i < nextSlot; i++)
        if(disk[i].getNumDisk() == numSlot){
            disk[i].display();
            success = true;
        }
    if (!success) std::wcout << L"Диск не найден!" << std::endl;
}

bool DataBase::isFull() const
{
    if (nextSlot == MaxDisks) return true;
    else return false;
}
bool DataBase::isEmpty() const
{
    if (nextSlot) return true;
    else return false;
}
