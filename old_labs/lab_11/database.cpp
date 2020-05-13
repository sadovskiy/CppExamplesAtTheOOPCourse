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

#include "database.hpp"

using namespace std;

// В конструкторе делаем поэлементно инициализацию массива "cc",
// забивая его значения нулями,
// пустыми строчками и значениями false
DataBase::DataBase(): cc(), nextSlot(0), numColumns(0)
{

}

// Копируем значение из другого объекта поэлементно
DataBase::DataBase(const DataBase& other): cc(other.cc), nextSlot(other.nextSlot), numColumns(other.numColumns)
{

}

DataBase::~DataBase()
{

}

// Копируем значение из другого объекта поэлементно
DataBase& DataBase::operator=(const DataBase& rhs)
{
    // Предварительно убеждаемся, что это другой объект
    if (this == &rhs) return *this;

    nextSlot = rhs.nextSlot;
    numColumns = rhs.numColumns;
    for (register size_t i = 0; i < nextSlot; i++)
        cc[i] = rhs.cc[i];

    return *this;
}

// Описываем метод добавления элемента в массив,
// при этом надо обязательно передать строку и значение
// логической переменной
ComputerCase& DataBase::add(const string newManufacturer,
                            const string newModel,
                            const string newColor,
                            const ComputerCase::materialType newMaterial,
                            const ComputerCase::typeType newType,
                            const ComputerCase::formFactorType newFormFactor,
                            const float newMetalThickness,
                            const ComputerCase::unit new_525InchBay,
                            const ComputerCase::unit new_35InchBay,
                            const ComputerCase::unit new_35InchBayIn,
                            const ComputerCase::unit newPCISlots,
                            const bool newPossibilityOfWaterCooling,
                            const bool newFeaturePSU,
                            const float newDepth,
                            const float newWidth,
                            const float newHeight)
{
    // Проверяем есть ли ещё место в массиве
    if (isFull()) {
        cerr << "Список заполнен!" << endl;
        return ccNull;
    }

    // Добавим возможность приведения в нижний регистр цвета,
    // если попадётся цвет набранный в верхнем регистре.
    string strColor(newColor);
    transform(strColor.begin(), strColor.end(), strColor.begin(), _tolower);
    // Добавляем новый элемент
    // при этом увеличиваем счётчик элементов
    // и вставляем в новый элемент переданные данные
    ComputerCase& newComputerCase = cc[nextSlot++];
    newComputerCase.setComputerCase(nextSlot,
                                    newManufacturer,
                                    newModel,
                                    strColor,
                                    newMaterial,
                                    newType,
                                    newFormFactor,
                                    newMetalThickness,
                                    new_525InchBay,
                                    new_35InchBay,
                                    new_35InchBayIn,
                                    newPCISlots,
                                    newPossibilityOfWaterCooling,
                                    newFeaturePSU,
                                    newDepth,
                                    newWidth,
                                    newHeight);

    // Зададим колличество столбцов
    numColumns = 16;

    // Возвращаем ссылку на вновь созданныей элемент
    return newComputerCase;
}

// Метод редактирования элемента в массиве.
// Первый аргумент отвечает за порядковый номер элемента
// в массиве, второй - за выбранное пользователем значение
// подлежащее редактированию, а третий - это новое значение,
// которое будет записано в соответствующее поле "cc"
ComputerCase& DataBase::mod(const size_t numSlot, const int picked, const string& newString)
{
    // Создаём переменную, которая в случае если элемент не найден
    // будет выдавать сообщение и завершать метод поиска
    bool findSuccess = false;
    // Индекс найденного элемента
    int findIndex = 0;

    // Ищем элемент в массиве
    for (register size_t i = 0; i < nextSlot; i++)
        if(i == numSlot){
            // Если находим, то сохраняем его индекс и сохраняем
            // флаг об успешном поиске
            findIndex = i - 1;
            findSuccess = true;
            break;
        }

    // Если элемент не найден, то выводим сообщение и выходим из метода
    if (!findSuccess) {
        cout << "Запись с такими данными не найдена!" << endl;
        return ccNull;
    }

    // Переходим к выбранному из 3-х значений элемента  в массиве "cc",
    // который будем изменять
    switch (picked) {
        case 0:
            cc[findIndex].SetManufacturer(newString);
            break;
        case 1:
            cc[findIndex].SetModel(newString);
            break;
        case 2:
            cc[findIndex].SetColor(newString);
            break;
        case 3: {
            ComputerCase::materialType newMaterial;

            // Для конвертации из строки в число используем строковые потоки
            istringstream ist(newString);
            int n;
            ist >> n;
            switch (n)
            {
                case 0: newMaterial = ComputerCase::NOmt;
                    break;
                case 1: newMaterial = ComputerCase::steel;
                    break;
                case 2: newMaterial = ComputerCase::aluminium;
                    break;
                default: cout << "Нет такого материала." << endl;
                    break;
            }

            cc[findIndex].SetMaterial(newMaterial);
            }
            break;
        case 4: {
            ComputerCase::typeType newType;

            istringstream ist(newString);
            int n;
            ist >> n;
            switch (n)
            {
                case 0: newType = ComputerCase::NOtp;
                    break;
                case 1: newType = ComputerCase::DeskTop;
                    break;
                case 2: newType = ComputerCase::FootPrint;
                    break;
                case 3: newType = ComputerCase::SlimLine;
                    break;
                case 4: newType = ComputerCase::UltraSlimLine;
                    break;
                case 5: newType = ComputerCase::MiniTower;
                    break;
                case 6: newType = ComputerCase::MidiTower;
                    break;
                case 7: newType = ComputerCase::BigTower;
                    break;
                case 8: newType = ComputerCase::SuperFullTower;
                    break;
                default: cout << "Нет такого типа системного блока." << endl;
                    break;
            }

            cc[findIndex].SetType(newType);
            }
            break;
        case 5: {
            ComputerCase::formFactorType newFormFactor;

            istringstream ist(newString);
            int n;
            ist >> n;

            switch (n) {
                case 0: newFormFactor = ComputerCase::NOff;
                    break;
                case 1: newFormFactor = ComputerCase::XT;
                    break;
                case 2: newFormFactor = ComputerCase::AT;
                    break;
                case 3: newFormFactor = ComputerCase::BabyAT;
                    break;
                case 4: newFormFactor = ComputerCase::ATX;
                    break;
                case 5: newFormFactor = ComputerCase::SSI_CEB;
                    break;
                case 6: newFormFactor = ComputerCase::microATX;
                    break;
                case 7: newFormFactor = ComputerCase::MiniATX;
                    break;
                case 8: newFormFactor = ComputerCase::FlexATX;
                    break;
                case 9: newFormFactor = ComputerCase::MiniITX;
                    break;
                case 10: newFormFactor = ComputerCase::NanoITX;
                    break;
                case 11: newFormFactor = ComputerCase::PicoITX;
                    break;
                case 12: newFormFactor = ComputerCase::MobileITX;
                    break;
                case 13: newFormFactor = ComputerCase::NeoITX;
                    break;
                case 14: newFormFactor = ComputerCase::BTX;
                    break;
                case 15: newFormFactor = ComputerCase::MicroBTX;
                    break;
                case 16: newFormFactor = ComputerCase::PicoBTX;
                    break;
                case 17: newFormFactor = ComputerCase::DTX;
                    break;
                case 18: newFormFactor = ComputerCase::MiniDTX;
                    break;
                case 19: newFormFactor = ComputerCase::ETX;
                    break;
                case 20: newFormFactor = ComputerCase::CoreExpress;
                    break;
                case 21: newFormFactor = ComputerCase::Extended_ATX;
                    break;
                case 22: newFormFactor = ComputerCase::Enhanced_Extended_ATX;
                    break;
                case 23: newFormFactor = ComputerCase::LPX;
                    break;
                case 24: newFormFactor = ComputerCase::MiniLPX;
                    break;
                case 25: newFormFactor = ComputerCase::PC_104;
                    break;
                case 26: newFormFactor = ComputerCase::NLX;
                    break;
                case 27: newFormFactor = ComputerCase::UTX;
                    break;
                case 28: newFormFactor = ComputerCase::WTX;
                    break;
                case 29: newFormFactor = ComputerCase::SWTX;
                    break;
                case 30: newFormFactor = ComputerCase::HPTX;
                    break;
                case 31: newFormFactor = ComputerCase::XTX;
                    break;
                default: cout << "Нет такого форм-фактора материнской платы." << endl;
                    break;
                }

            cc[findIndex].SetFormFactor(newFormFactor);
        }
            break;
        case 6:
            cc[findIndex].SetMetalThickness(atof(newString.c_str()));
            break;
        case 7:
            cc[findIndex].Set525InchBay(atoi(newString.c_str()));
            break;
        case 8:
            cc[findIndex].Set35InchBay(atoi(newString.c_str()));
            break;
        case 9:
            cc[findIndex].Set35InchBayIn(atoi(newString.c_str()));
            break;
        case 10:
            cc[findIndex].SetPCISlots(atoi(newString.c_str()));
            break;
        case 11:
            cc[findIndex].SetPossibilityOfWaterCooling((bool)atoi(newString.c_str()));
            break;
        case 12:
            cc[findIndex].SetFeaturePSU(atoi(newString.c_str()));
            break;
        case 13:
            cc[findIndex].SetDepth(atof(newString.c_str()));
            break;
        case 14:
            cc[findIndex].SetWidth(atof(newString.c_str()));
        break;
        case 15:
            cc[findIndex].SetHeight(atof(newString.c_str()));
            break;
        // В случае, если было передано некорректное значение, выдаём пользователю сообщение
        default: cout << "Такого значения нет в Компьютерном корпусе!" << endl;
            break;
    }

    // При выходе делаем возврат изменённого значения
    return cc[findIndex];
}


// Описание метода поиска по индексу
ComputerCase& DataBase::find(const size_t numSlot)
{
    for (register size_t i = 0; i < nextSlot; i++)
        if (i == numSlot)
            return cc[i];

    cout << "Данные не найдены!" << endl;

    return ccNull;
}

// Описание метода поиска по индексу константный вариант
const ComputerCase& DataBase::find(const size_t numSlot) const
{
    for (register size_t i = 0; i < nextSlot; i++)
        if (i == numSlot)
            return cc[i];

    cout << "Данные не найдены!" << endl;

    return ccNull;
}

// Описание метода поиска по производителю.
// При нахождении в массиве нескольких элементов с одинаковой строкой
// найдётся только первая из них.
ComputerCase& DataBase::findByManufacturer(const std::string _manufacturer)
{
    for (register size_t i = 0; i < nextSlot; i++)
        if(cc[i].GetManufacturer() == _manufacturer)
            return cc[i];

    cout << "Такой производитель не найден!" << endl;

    return ccNull;
}

// Описание метода поиска по модели.
// При нахождении в массиве нескольких элементов с одинаковой строкой
// найдётся только первая из них.
ComputerCase& DataBase::findByModel(const std::string _model)
{
    for (register size_t i = 0; i < nextSlot; i++)
        if(cc[i].GetModel() == _model)
            return cc[i];

    cout << "Такая модель не найдена!" << endl;

    return ccNull;
}

// Описание метода, выдающего ссылку элемента из массива
// по индексу без перебора всего массива
ComputerCase& DataBase::get(const size_t numSlot)
{
    return cc[numSlot];
}

// Описание метода выдающего ссылку элемента из массива
// по индексу без перебора всего массива
const ComputerCase& DataBase::get(const size_t numSlot) const
{
    return cc[numSlot];
}

// Описание метода удаления элемента по его индексу
bool DataBase::del(const size_t numSlot)
{
    // При удалении ищем удаляемый элемент и сдвигаем элементы после
    // этого элемента на его место
    bool findSuccess = true;
    int findIndex = numSlot;

    // Выводим сообщение об успешном удалении
    if (findSuccess) {
        nextSlot--;
        cout << "Данные № " << findIndex << " удалены успешно." << endl;
        // Пересчёт индексов после удаления элемента
        cout << "После удаления элемента индексы в базе данных устарели,\n"
             << "Пересчитать их? (y/n)" << endl;

        char ch = cin.get();

        // После удаления надо пересчитать индексы
        if (ch == 'y')
            recalcIndex(numSlot);
        // Если в потоке ввода остались символы, то мы их удаляем (игнорируем)
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return true;
    }

    return false;
}

// Метод производит перерасчёт индексов в списке
void DataBase::recalcIndex(const size_t numSlot)
{
    for (register size_t j = numSlot; j < nextSlot; j++) {
        cc[j].SetManufacturer(cc[j + 1].GetManufacturer());
        cc[j].SetModel(cc[j + 1].GetModel());
        cc[j].SetColor(cc[j + 1].GetColor());
        cc[j].SetMaterial(cc[j + 1].GetMaterial());
        cc[j].SetType(cc[j + 1].GetType());
        cc[j].SetFormFactor(cc[j + 1].GetFormFactor());
        cc[j].SetMetalThickness(cc[j + 1].GetMetalThickness());
        cc[j].Set525InchBay(cc[j + 1].Get525InchBay());
        cc[j].Set35InchBay(cc[j + 1].Get35InchBay());
        cc[j].Set35InchBayIn(cc[j + 1].Get35InchBayIn());
        cc[j].SetPCISlots(cc[j + 1].GetPCISlots());
        cc[j].SetPossibilityOfWaterCooling(cc[j + 1].GetPossibilityOfWaterCooling());
        cc[j].SetFeaturePSU(cc[j + 1].GetFeaturePSU());
        cc[j].SetDepth(cc[j + 1].GetDepth());
        cc[j].SetWidth(cc[j + 1].GetWidth());
        cc[j].SetHeight(cc[j + 1].GetHeight());
        cout << j << " ";
    }

    cout << "\nИндексы пересчитаны." << endl;
}

// Метод описывает вывод на экран всех элементов
void DataBase::displayALL() const
{
    for (register size_t i = 0; i < nextSlot; i++)
        cc[i].printAllPropertys();
}

// Метод, описывающий вывод на экран элемента по его индексу
void DataBase::displayCurrent(const size_t numSlot) const
{
    // Так как в константном методе запрещено вызывать не константные методы,
    // нам пришлось выше перегрузить метод find()
    const ComputerCase& tmp = find(numSlot);
    tmp.printAllPropertys();
}

// Описание метода, возвращающего текущее количество элементов в базе
size_t DataBase::getNumSlots() const
{
    return nextSlot;
}

// Описание метода, возвращающего текущее количество значений (полей) в элементе (записи)
size_t DataBase::getNumColumns() const
{
    return numColumns;
}

// Описание метода, проверяющего заполнен ли массив "cc"
bool DataBase::isFull() const
{
    // Для краткости проверяем условия в операторе return
    return (bool)(nextSlot == Max);
}

// Описание метода, проверяющего пуст ли массив "cc"
bool DataBase::isEmpty() const
{
    return (bool)(nextSlot == 0);
}

// Описание метода, проверяющего оди ли элемент в массиве "cc"
bool DataBase::isFirstLast() const
{
    if (nextSlot == 0)
        return true;
    else
        return false;
}

