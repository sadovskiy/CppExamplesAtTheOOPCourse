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

#include "compactdisk.hpp"

using namespace std;

// Конструктор по умолчанию задаёт базовые свойства
TCompactDisk::TCompactDisk():
    recordNameDisk(),
    physicalSizeDisk(standard),
    mediaTypeDisk(audio_cd),
    recordable(false),
    feature(false)
{
    //ctor
}

// Конструктор копирования переносит значения свойств из другого
// объекта класса TCompactDisk
TCompactDisk::TCompactDisk(const TCompactDisk &other):
    recordNameDisk(other.recordNameDisk)
  , physicalSizeDisk(other.physicalSizeDisk)
  , mediaTypeDisk(other.mediaTypeDisk)
  , recordable(other.recordable)
  , feature(other.feature)
{

}

// Перегруженный конструктор даёт возможность
// задать свойства при создании объекта
TCompactDisk::TCompactDisk(const wstring &recNameDisk,
                           const physicalSize &pSize,
                           const mediaType &mType,
                           const bool &rec):
    recordNameDisk(recNameDisk),
    physicalSizeDisk(pSize),
    mediaTypeDisk(mType),
    recordable(rec),
    feature(true)
{

}

// Деструктор по умолчанию
TCompactDisk::~TCompactDisk()
{
    //dtor
}

void TCompactDisk::display() const
{
    wcout << L"1| Название CD:		" << getNameDisk() << endl;
    wcout << L"2| Размер диска:	"     << getPhysicalSize() << L" см." << endl;

    // Для вывода данных удобных для восприятия человеком
    std::wstring cd = L"";
    switch (getMediaType()){
    case 0: cd = L"Аудио компакт диск"; break;
    case 1: cd = L"Фото компакт диск"; break;
    case 2: cd = L"Видео компакт диск"; break;
    case 3: cd = L"Компьютерный компакт диск"; break;
    case 4: cd = L"Записываемый компакт диск"; break;
    case 5: cd = L"Перезаписываемый компакт диск"; break;
    }

    wcout << L"3| Тип диска:		" << cd << endl;
    std::wstring rc = L"";
    if (getRec()) rc = L"да";
    else rc = L"Нет";
    wcout << L"4| Перезаписываемый:	" << rc << endl;
    std::wstring ftr = L"";
    if (getFeature()) ftr = L"да";
    else ftr = L"Нет";
    wcout << L"5| Имеется в наличии:	" << ftr << endl;
}

void TCompactDisk::setMediaType(const mediaType mType)
{
    mediaTypeDisk = mType;
    if (mediaTypeDisk == cdrw)
        recordable = true;
}

wostream& operator<<(wostream & os, const TCompactDisk & dsk)
{
    os << L"1| Название CD:		" << dsk.getNameDisk() << endl;
    os << L"2| Размер диска:	" << dsk.getPhysicalSize() << L" см." << endl;
    std::wstring cd = L"";
    switch (dsk.getMediaType()){
    case 0:	cd = L"Аудио компакт диск"; break;
    case 1:	cd = L"Фото компакт диск"; break;
    case 2:	cd = L"Видео компакт диск"; break;
    case 3:	cd = L"Компьютерный компакт диск"; break;
    case 4:	cd = L"Записываемый компакт диск"; break;
    case 5:	cd = L"Перезаписываемый компакт диск"; break;
    }

    os << L"3| Тип диска:		" << cd << endl;
    std::wstring rc = L"";
    if (dsk.getRec()) rc = L"да";
    else rc = L"Нет";
    os << L"4| Перезаписываемый:	" << rc  << endl;
    std::wstring ftr = L"";
    if (dsk.getFeature()) ftr = L"да";
    else ftr = L"Нет";
    os << L"5| Имеется в наличии:	" << ftr << endl;

    return os;
}
