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

// В конструкторе делаем поэлеметно инициализацию массива "cc",
// забивая его значения нулями,
// пустыми строчками и значениями false
DataBase::DataBase(): first(0), last(0), nextSlot(0), numColumns(0)
{

}

// Копируем знацение из другого объекта по элементно
DataBase::DataBase(const DataBase& other): first(0), last(0), nextSlot(0), numColumns(other.numColumns)
{
    for (   ComputerCaseList* current = other.first;
            current;
            current = current->next) {
                // Для создания нового элемента просто используем
                // метод add()
                add(current->cc.GetManufacturer(),
                    current->cc.GetModel(),
                    current->cc.GetColor(),
                    current->cc.GetMaterial(),
                    current->cc.GetType(),
                    current->cc.GetFormFactor(),
                    current->cc.GetMetalThickness(),
                    current->cc.Get525InchBay(),
                    current->cc.Get35InchBay(),
                    current->cc.Get35InchBayIn(),
                    current->cc.GetPCISlots(),
                    current->cc.GetPossibilityOfWaterCooling(),
                    current->cc.GetFeaturePSU(),
                    current->cc.GetDepth(),
                    current->cc.GetWidth(),
                    current->cc.GetHeight());

    }
}

DataBase::~DataBase()
{
    // Удаление элементов начинаем с конца списка
    for (   ComputerCaseList* current = last;
            current;
            current = current->prior) {
            // Если элемент остался один в списке
            if (current->next == current->prior) {
                first = last = 0;
                delete current;
                cout << "Удалён последний элемент в списке.\n";
                cout << "База пуста!" << endl;
            }
            // Если элементы ещё есть перед текущим
            else {
                ComputerCaseList* prior = current->prior;
                prior->next = current->next;
                last = prior;
                int n = current->n;
                    delete current;
                cout << "Удалён элемент: " << n << "." << endl;
            }
    }
}

// Копируем значение из другого объекта поэлементно
DataBase& DataBase::operator=(const DataBase& rhs)
{
    // Предварительно убеждаемся, что это другой объект
    if (this == &rhs) return *this;

    numColumns = rhs.numColumns;

    for (   ComputerCaseList* current = rhs.first;
            current;
            current = current->next) {
                // Для создания нового элемента просто используем
                // метод add()
                add(current->cc.GetManufacturer(),
                    current->cc.GetModel(),
                    current->cc.GetColor(),
                    current->cc.GetMaterial(),
                    current->cc.GetType(),
                    current->cc.GetFormFactor(),
                    current->cc.GetMetalThickness(),
                    current->cc.Get525InchBay(),
                    current->cc.Get35InchBay(),
                    current->cc.Get35InchBayIn(),
                    current->cc.GetPCISlots(),
                    current->cc.GetPossibilityOfWaterCooling(),
                    current->cc.GetFeaturePSU(),
                    current->cc.GetDepth(),
                    current->cc.GetWidth(),
                    current->cc.GetHeight());

    }

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
    // Создаём в динамической памяти новый элемент
    ComputerCaseList* newComputerCase = new ComputerCaseList;
    // Проверяем есть ли ещё место в папяти
    if (!newComputerCase) {
        cerr << "Список заполнен!" << endl;
        return ccNull;
    }

    // Добавим возможность приведения в нижний регистр цвета
    // если попадётся цвет набранный в верхнем регистре.
    string strColor(newColor);
    transform(strColor.begin(), strColor.end(), strColor.begin(), _tolower);

    // Добавляем новый элемент
    // при этом увеличиваем счётчик элементов
    // и вставляем в новый элемент преданные данные
    newComputerCase->n = nextSlot++;
    newComputerCase->cc.setComputerCase(newComputerCase->n,
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

//    // Так как отсчёт начинается с нуля передаём счётчику "n" на единицу меньше
//    newComputerCase->n = nextSlot;

    // Включаем новый элемент в конец списка
    newComputerCase->next = 0;
    newComputerCase->prior = last;

    if (!first)
        first = newComputerCase;
    else
        last->next = newComputerCase;
    last = newComputerCase;

    // Зададим колличество столбцов
    numColumns = 16;

    // Возвращаем ссылку на вновь созданныей элемент
    return newComputerCase->cc;
}


// Метод редактирования элемента в массиве.
// Первый аргумент отвечает за порядковый номер элемента
// в массиве, второй - за выбранное пользователем значение
// подлежащее редактированию, а третий - это новое значение
// которое будет записано в соответствующее поле "cc"
ComputerCase& DataBase::mod(const size_t numSlot, const int picked, const string& newString)
{
    // Создаём переменную, которая в случае если элемент не найден
    // будет выдавать сообщение и зафершать метод поиска
    bool findSuccess = false;

    ComputerCaseList* current = 0;
    // Ищем элемент в списке
    for (current = first; current; current = current->next)
        if(current->n == numSlot){
            // Если находим, то сохраняем
            // флаг, об успешном поиске
            findSuccess = true;
            break;
        }

    // Если элемент не найден, то выводим сообщение и выходим из метода
    if (!findSuccess) {
        cout << "Запись с такими данными не найдена!" << endl;
        return ccNull;
    }

    // Переходим к выбранному из 16 значений элемента в списке "ComputerCaseList",
    // который будем изменять
    switch (picked) {
        case 0:
            current->cc.SetManufacturer(newString);
            break;
        case 1:
            current->cc.SetModel(newString);
            break;
        case 2:
            current->cc.SetColor(newString);
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

            current->cc.SetMaterial(newMaterial);
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

            current->cc.SetType(newType);
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

            current->cc.SetFormFactor(newFormFactor);
            }
            break;
        case 6:
            current->cc.SetMetalThickness(atof(newString.c_str()));
            break;
        case 7:
            current->cc.Set525InchBay(atoi(newString.c_str()));
            break;
        case 8:
            current->cc.Set35InchBay(atoi(newString.c_str()));
            break;
        case 9:
            current->cc.Set35InchBayIn(atoi(newString.c_str()));
            break;
        case 10:
            current->cc.SetPCISlots(atoi(newString.c_str()));
            break;
        case 11:
            current->cc.SetPossibilityOfWaterCooling((bool)atoi(newString.c_str()));
            break;
        case 12:
            current->cc.SetFeaturePSU(atoi(newString.c_str()));
            break;
        case 13:
            current->cc.SetDepth(atof(newString.c_str()));
            break;
        case 14:
            current->cc.SetWidth(atof(newString.c_str()));
            break;
        case 15:
            current->cc.SetHeight(atof(newString.c_str()));
            break;
        // В случае, если было передано некорректное значение, выдаём пользователю сообщение
        default: cout << "Такого значения нет в Компьютерном корпусе!" << endl;
            break;
    }

    // При выходе делаем возврат изменённого значения
    return current->cc;
}


// Описание метода поиска по индексу
ComputerCase& DataBase::find(const size_t numSlot)
{
    for (ComputerCaseList* current = first; current; current = current->next)
        if (current->n == numSlot)
            return current->cc;

    cout << "Данные не найдены!" << endl;

    return ccNull;
}

// Описание метода поиска по индексу константный вариант
const ComputerCase& DataBase::find(const size_t numSlot) const
{
    for (ComputerCaseList* current = first; current; current = current->next)
        if (current->n == numSlot)
            return current->cc;

    cout << "Данные не найдены!" << endl;

    return ccNull;
}

// Описание метода поиска по производителю.
// При нахождении в массиве нескольких элементов с одинаковой строкой
// найдётся только первая из них.
ComputerCase& DataBase::findByManufacturer(const std::string _manufacturer)
{
    for (ComputerCaseList* current = first; current; current = current->next)
        if (current->cc.GetManufacturer() == _manufacturer)
            return current->cc;

    cout << "Такой производитель не найден!" << endl;

    return ccNull;
}

// Описание метода поиска по модели.
// При нахождении в массиве нескольких элементов с одинаковой строкой
// найдётся только первая из них.
ComputerCase& DataBase::findByModel(const std::string _model)
{
    for (ComputerCaseList* current = first; current; current = current->next)
        if (current->cc.GetModel() == _model)
            return current->cc;

    cout << "Такая модель не найдена!" << endl;

    return ccNull;
}

// Описание метода, выдающего ссылку элемента из массива
// по индексу без перебора всего массива
ComputerCase& DataBase::get(const size_t numSlot)
{
    return find(numSlot);
}

// Описание метода выдающего ссылку элемента из массива
// по индексу без перебора всего массива
const ComputerCase& DataBase::get(const size_t numSlot) const
{
    return find(numSlot);
}

// Описание метода последовательно возвращающего ссылку
// на элемент в списке. При каждом новом вызове осуществляется
// последовательный обход по столбцам (значениям) и
// когда все столбцы перебраны, осуществляется переход на новый
// элемент списка. При этом каждый раз возвращается ссылка на текущий
// элемент списка
ComputerCase& DataBase::get()
{
    static size_t index = 0;
    static ComputerCaseList* current = first;
    ComputerCase* ccTemp = 0;

    if (current) {
        if (index == numColumns) {
            current = current->next;
            index = 0;
        }
        index++;
        ccTemp = &(current->cc);
    }
    else {
        current = first;
        index++;
        ccTemp = &(current->cc);
    }
    if (!current->next && index == numColumns) {
        current = 0;
        index = 0;
    }

    return *ccTemp;
}

// Описание метода удаления элемента по его индексу
bool DataBase::del(const size_t numSlot)
{
    // При удалении ищем удаляемый элемент и сдвигаем элементы после
    // этого элемента на его место
    bool findSuccess = false;
    int findIndex = 0;

    for (ComputerCaseList* current = first; current; current = current->next)
        if(current->n == numSlot){
                // Если элемент не является последним или первым
                if (current->next && current->prior) {
                    ComputerCaseList* next = current->next;
                    ComputerCaseList* prior = current->prior;
                    next->prior = current->prior;
                    prior->next = current->next;
                }
                else
                    // Если элемент один в списке
                    if (current->next == current->prior) {
                        first = last = 0;
                        findIndex = current->n + 1;
                        delete current;
                        findSuccess = true;
                        break;
                    }
                    else {
                        // Если элемент первый
                        if (current == first) {
                            ComputerCaseList* next = current->next;
                            next->prior = current->prior;
                            first = next;
                        }
                        // Если элемент последний
                        if (current == last ) {
                            ComputerCaseList* prior = current->prior;
                            prior->next = current->next;
                            last = prior;
                        }
                    }
                // Сохраняем индекс удаляемого элемента,
                // удаляем и отмечаем успешное удаление
                findIndex = current->n + 1;
                delete current;
                findSuccess = true;
                break;
        }

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
            recalcIndex();
        // Если в потоке ввода остались символы, то мы их удаляем (игнорируем)
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return true;
    }

    return false;
}

// Метод производит перерасчёт индексов в списке
void DataBase::recalcIndex(const size_t numSlot)
{
    ComputerCaseList* current = first;
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
void DataBase::displayALL() const
{
    for (ComputerCaseList* current = first; current; current = current->next) {
        current->cc.printAllPropertys();
        cout << "---" << endl;
    }
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

// Описание метода, проверяющего заполнен ли список
// при использовании динамической памяти список является бесконечным
// по этом можно проверить можно ли ещё выделить памяти.
bool DataBase::isFull() const
{
    ComputerCaseList* n = 0;
    n = new ComputerCaseList;
    if (n) {
        delete n;
        return true;
    }
    else {
        delete n;
        return false;
    }
}

// Описание метода, проверяющего пуст ли список "cc"
bool DataBase::isEmpty() const
{
    return (bool)(first == 0);
}

// Описание метода, проверяющего оди ли элемент в списке "cc"
bool DataBase::isFirstLast() const
{
    if (first)
        return (bool)(first == last);
    else
        return false;
}

