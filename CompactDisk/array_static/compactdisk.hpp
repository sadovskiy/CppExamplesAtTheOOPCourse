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

#ifndef COMPACTDISK_H
#define COMPACTDISK_H

#include <iostream>
#include <string>

class TCompactDisk
{
public:
    // Создаём новые типы данных: phisicalSize, mediaType
    // и константы: mini_cd, standard, audio_cd, photo_cd,
    // video_cd, cd_rom, cdr, cdrw
    enum physicalSize {mini_cd = 8,  // мини диск
                       standard = 12}; // стандартный диск
    enum mediaType {audio_cd = 0, // аудио диск
                    photo_cd,   // фото диск
                    video_cd,   // видео диск
                    cd_rom,     // компьютерный
                    cdr,        // записываемый
                    cdrw};      // перезаписываемый

private:
    // Свойства CD-диска (данные)
    short           numDisk;    // номер диска
    std::wstring    recordNameDisk;  // название диска
    physicalSize    physicalSizeDisk; // размер в сантиметрах
    mediaType       mediaTypeDisk; // тип диска
    bool            recordable; // записываемый диск
    bool            feature;    // имеется в наличии

public:
    TCompactDisk();
    TCompactDisk(const TCompactDisk &other);
    TCompactDisk(const std::wstring &recNameDisk, // задаётся имя диска
                 const physicalSize &pSize,   // задаётся размер диска
                 const mediaType &mType,    // задаётся тип диска
                 const bool &rec);
    ~TCompactDisk();

    void display()  const;              // отобразить на экран данные
    void toPlace()  {feature = true;}  // положить компакт диск
    void toTake()   {feature = false;}  // взять компакт диск

    // Изменение свойств CD-диска (методы)
    // Функции начинающиеся с приставки "set" задают свойства CD-диска.
    // Функции начинающиеся с "get" позволяют узнать свойства CD-диска.
    // Они необходимы так как доступ напрямую к свойствам запрещён
    void                 setNumDisk(const short num) {numDisk = num;}
    short                getNumDisk() const {return numDisk;}

    void                 setNameDisk(const std::wstring &recNameDisk) {recordNameDisk = recNameDisk;}
    std::wstring         getNameDisk() const {return recordNameDisk;}

    void                 setPhysicalSize(const physicalSize pSize) {physicalSizeDisk = pSize;}
    physicalSize         getPhysicalSize() const {return physicalSizeDisk;}

    void                 setMediaType(const mediaType mType);
    mediaType            getMediaType() const {return mediaTypeDisk;}

    void                 setRec(const bool rec) {recordable = rec;}
    bool                 getRec() const {return recordable;}

    void                 setFeature(const bool Ftr) {feature = Ftr;}
    bool                 getFeature() const {return feature;}

    // Для вывода с помощью cout
    friend std::wostream& operator<<(std::wostream & os, const TCompactDisk & dsk);
};


#endif // COMPACTDISK_H
