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

#include "database.hpp"

DataBase::DataBase(): firstDisk(0), lastDisk(0), countSlots(0)
{
    //ctor
}

DataBase::~DataBase()
{
    // в деструкторе удаляем БД из ОП
    for (	Node *current = lastDisk;
            current;
            current = current->prior) {
        if (current->next == current->prior) {
            firstDisk = lastDisk = 0;
            delete current;
        }
        else {
            Node *prior = current->prior;
            prior->next = current->next;
            lastDisk = prior;
            delete current;
        }
    }
}

DataBase::DataBase(const DataBase& other): firstDisk(0), lastDisk(0), countSlots(0)
{
    // в конструкторе копирования предусматриваем возможность создания копии БД
    Node *current = other.firstDisk;
    while (current) {
        TCompactDisk& DB = addDisk(current->disk.getNameDisk(),
                                   current->disk.getPhysicalSize(),
                                   current->disk.getMediaType());
        if (!current->disk.getFeature()) DB.toTake();
        current = current->next;
    }
}

DataBase& DataBase::operator=(const DataBase& rhs)
{
    // в операторе присваивания также предусматриваем возможность создания копии БД
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    Node *current = rhs.firstDisk;
    while (current) {
        TCompactDisk& DB = addDisk(current->disk.getNameDisk(),
                                   current->disk.getPhysicalSize(),
                                   current->disk.getMediaType());
        if (!current->disk.getFeature()) DB.toTake();
        current = current->next;
    }
    return *this;
}

TCompactDisk& DataBase::addDisk(const std::wstring &recNameDisk,
                                const TCompactDisk::physicalSize pSize,
                                const TCompactDisk::mediaType mType)
{
    Node *cdNew = new Node;
    if (!cdNew) {
        std::wcerr << L"База заполнена!" << std::endl;
        // !!!! замена sleep()
        return cdNew->disk;
    }
    countSlots++;
    cdNew->disk.setNumDisk(countSlots);
    cdNew->disk.setNameDisk(recNameDisk);
    cdNew->disk.setPhysicalSize(pSize);
    cdNew->disk.setMediaType(mType);
    cdNew->disk.toPlace();

    cdNew->next = 0;
    cdNew->prior = lastDisk;
    if (!firstDisk)
        firstDisk = cdNew;
    else
        lastDisk->next = cdNew;
    lastDisk = cdNew;

    return cdNew->disk;
}

TCompactDisk& DataBase::modDisk(const int num, const int menu) // num - номер записи которая редактируется
{											// menu - параметр определяющий какая часть записи редактируется
    bool success = false;
    Node *current = firstDisk;
    while (current) {
        if(current->disk.getNumDisk() == num){
            success = true;
            break;
        }
        current = current->next;
    }
    if (!success) {
        std::wcout << L"Диск не найден!" << std::endl;
        // !!!! замена sleep()
        return current->disk;
    }
    std::wstring newName;
    TCompactDisk::physicalSize newSize = TCompactDisk::standard;
    int sw = 0;

    TCompactDisk::mediaType newMediaType;
    switch (menu){
    case 0:
        std::wcout << L"Укажите название диска" << std::endl;
        std::wcin >> newName;
        current->disk.setNameDisk(newName);
        break;
    case 1:
        std::wcout << L"Укажите размер диска" << std::endl;
        std::wcin >> sw;
        if (sw) newSize = TCompactDisk::mini_cd;
        current->disk.setPhysicalSize(newSize);
        break;
    case 2:
        std::wcout << L"Укажите тип диска" << std::endl;
        switch (sw){
        case 0:	newMediaType = TCompactDisk::audio_cd; break;
        case 1:	newMediaType = TCompactDisk::photo_cd; break;
        case 2:	newMediaType = TCompactDisk::video_cd; break;
        case 3:	newMediaType = TCompactDisk::cd_rom; break;
        case 4:	newMediaType = TCompactDisk::cdr; break;
        case 5:	newMediaType = TCompactDisk::cdr; break;
        }
        current->disk.setMediaType(newMediaType);
        break;
    }

    return current->disk; // возвращаем ссылку на исправленную запись
}

TCompactDisk* DataBase::findDisk(const int numSlot) // поиск диска(записи) по порядковому номеру
{
    Node *current = firstDisk;
    while (current) {
        if(current->disk.getNumDisk() == numSlot)
            return & current->disk; // если диск найден то выходим здесь и возвращаем указатель на него
        current = current->next;
    }
    std::wcout << L"Диск не найден!" << std::endl;

    return 0;
}

TCompactDisk* DataBase::findDisk(const std::wstring &nameDisk) // поиск по имени
{
    Node *current = firstDisk;
    while (current) {
        if(current->disk.getNameDisk() == nameDisk)
            return & current->disk;	// если диск найден то выходим здесь и возвращаем указатель на него
        current = current->next;
    }
    std::wcout << L"Диск не найден!" << std::endl;

    return 0;
}

int DataBase::findDisk(const TCompactDisk& tdisk) // поиск по ссылке
{
    return tdisk.getNumDisk(); 	// возвращаем порядковый номер диска по ссылке на него
}

TCompactDisk* DataBase::takeDisk(const int numSlot) // если диск забрали то отмечаем это в БД (поиск по номеру)
{
    Node *current = firstDisk;
    while (current) {
        if(current->disk.getNumDisk() == numSlot){
            current->disk.toTake();  // собственно отмечаем факт изъятия диска
            return &current->disk; // после выходим здесь и возвращаем указатель на него
        }
        current = current->next;
    }

    std::wcout << L"Диск не найден!" << std::endl;

    return 0;
}

TCompactDisk* DataBase::placeDisk(const int numSlot) // если диск вернули то отмечаем этот факт в БД (поиск также по номеру)
{
    Node *current = firstDisk;
    while (current) {
        if(current->disk.getNumDisk() == numSlot){
            current->disk.toPlace(); // собственно отмечаем факт возвращения диска
            return & current->disk; // после выходим здесь и возвращаем указатель на него
        }
        current = current->next;
    }
    std::wcout << L"Диск не найден!" << std::endl;

    return 0;
}

bool DataBase::delDisk(const int numSlot) // удаляем информацию о компакт-диске из БД (и здесь поиск по номеру)
{
    bool success = false;
    int numSuccessfull = 0;
    for (	Node *current = firstDisk;
            current;
            current = current->next)
        if(current->disk.getNumDisk() == numSlot){
            numSuccessfull = current->disk.getNumDisk(); // получение номера найденного диска
            if (current->next && current->prior) { // если диск в середине
                Node *next = current->next;
                next->prior = current->prior;
                Node *prior = current->prior;
                prior->next = current->next;
                delete current;
            }
            else
                if (current->next == current->prior) {// если вообще последний диск в БД
                    firstDisk = lastDisk = 0;
                    delete current;
                }
                else {
                    if (current == firstDisk) { // если диск первый
                        Node *next = current->next;
                        next->prior = current->prior;
                        firstDisk = next;
                    }
                    if (current == lastDisk ) { // если диск последний
                        Node *prior = current->prior;
                        prior->next = current->next;
                        lastDisk = prior;
                    }
                    delete current;
                }
            success = true; // успешно удалили!
            break;
        }
    if (success) {
        countSlots--;
        std::wcout << L"Диск № " << numSuccessfull << L" удалён успешно." << std::endl;
        return true;
    }
    return false;
}

void DataBase::displayALL() const // выводим всю БД на экран
{
    if (!firstDisk) std::wcout << L"База данных не открыта!" << std::endl;
    for (	Node *current = firstDisk;
            current;
            current = current->next)
        current->disk.display();
}
void DataBase::displayCurrent(const int numSlot) const // выводим один диск на экран
{
    bool isSuccess = false;
    for (	Node *current = firstDisk;
            current;
            current = current->next)
        if(current->disk.getNumDisk() == numSlot){
            current->disk.display();
            isSuccess = true;
        }
    if (!isSuccess) std::wcout << L"Диск не найден!" << std::endl;
}

bool DataBase::isEmpty() const
{
    return firstDisk == 0;
}

bool DataBase::isFull() const // проверяем можно ли ещё добавить запись
{
    Node *newSlot = new Node;
    bool full;
    if (newSlot)
        full = false;
    else
        full = true;
    delete newSlot;
    return full;
}

unsigned long DataBase::itemCount() const // узнаём количество записей в БД
{
    // пересчитывая записи всего списка
    unsigned long count = 0;
    for (Node *current = firstDisk; current; current = current->next)
        count++;
    countSlots = count;

    return count;
}

unsigned long DataBase::statItemCount() const // узнаём количество записей из переменной countSlots
{						// работает быстрее но есть опасность неверно указанного количества записей
    return countSlots;
}

TCompactDisk& DataBase::getDisk() const // получение ссылки на диск (при каждом вызове возвращается указатель на следующий диск в списке)
{
    static Node *static_current = firstDisk; // при первом вызове получаем первый диск а при
    Node *current = static_current;	// последующих вызовах следующий диск по списку

    if (static_current->next) // если ещё есть диски в списке
        static_current = static_current->next; // собственно переходим к следующему диску в списке
    else
        static_current = firstDisk; // если список закончился опять устанавливаем static_current на его начало

    return current->disk;
}
