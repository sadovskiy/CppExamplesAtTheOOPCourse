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

#include <limits>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>

#include "managedb.hpp"

using namespace std;

ManageDB::ManageDB()
{

}

ManageDB::~ManageDB()
{

}

size_t ManageDB::load(const std::string filename, DataBase& db)
{
    // Количесвто строк
    size_t numRows = 0;
    // Строка прочитанная из файла и индекс элемента ";" в ней
    string strFromFile;
    string::size_type index = 0;
    // Создаём поток "inFile" на чтение
    // и ассоциируем его с файлом filename
    fstream inFile(filename.c_str(), ios_base::in);

    // Делаем проверку, открыт ли файл
    if ( !inFile.is_open() ) {
        // Если файл не открыт, то выдаём пользователю
        // соответствующее сообщение и выходим из программы
        cerr << "Ошибка открытия файла!" << endl;
        exit(1);
    }

    cout << "Чтение из файла." << endl;

    // Чтение из файла осуществляем построчно
    // через цикл, который остановится, когда будет
    // достигнут конец файла
    while (!inFile.eof()) {
        // Читаем построчно из потока "inFile" и пишем в строку "strFromFile"
        getline(inFile, strFromFile);

        // Осуществляем синтаксический разбор входных данных строки "strFromFile"

        // Определяем конец столбца в строке отделяемого символом ";"
        index = strFromFile.find(';');
        // Выделяем из строки нужный нам столбец, переводим его из string
        // в int и копируем в поле "id" стуктуры "db"
        string manufacturer = strFromFile.substr(0, index);
        // Удаляем извлечённый столбец + терминальный символ ";"
        strFromFile.erase(0, index + 1);

        // Далее действия повторяются для каждего из полей структуры "db"
        index = strFromFile.find(';');
        string model = strFromFile.substr(0, index);
        strFromFile.erase(0, index + 1);

        index = strFromFile.find(';');
        string color = strFromFile.substr(0, index);
        strFromFile.erase(0, index + 1);

        index = strFromFile.find(';');
        ComputerCase::materialType material;
        switch (atoi(strFromFile.substr(0, index).c_str())) {
            case 0: material = ComputerCase::NOmt;
                break;
            case 1: material = ComputerCase::steel;
                break;
            case 2: material = ComputerCase::aluminium;
                break;

            default: std::cout << "Нет такого материала." << endl;
                break;
        }
        strFromFile.erase(0, index + 1);

        index = strFromFile.find(';');
        ComputerCase::typeType type;
                switch (atoi(strFromFile.substr(0, index).c_str())) {
                case 0: type = ComputerCase::NOtp;
                    break;
                case 1: type = ComputerCase::DeskTop;
                    break;
                case 2: type = ComputerCase::FootPrint;
                    break;
                case 3: type = ComputerCase::SlimLine;
                    break;
                case 4: type = ComputerCase::UltraSlimLine;
                    break;
                case 5: type = ComputerCase::MiniTower;
                    break;
                case 6: type = ComputerCase::MidiTower;
                    break;
                case 7: type = ComputerCase::BigTower;
                    break;
                case 8: type = ComputerCase::SuperFullTower;
                    break;
                default: std::cout << "Нет такого типа корпуса." << endl;
                    break;
                }
        strFromFile.erase(0, index + 1);

        index = strFromFile.find(';');
        ComputerCase::formFactorType formFactor;
                switch (atoi(strFromFile.substr(0, index).c_str())) {
                case 0: formFactor = ComputerCase::NOff;
                    break;
                case 1: formFactor = ComputerCase::XT;
                    break;
                case 2: formFactor = ComputerCase::AT;
                    break;
                case 3: formFactor = ComputerCase::BabyAT;
                    break;
                case 4: formFactor = ComputerCase::ATX;
                    break;
                case 5: formFactor = ComputerCase::SSI_CEB;
                    break;
                case 6: formFactor = ComputerCase::microATX;
                    break;
                case 7: formFactor = ComputerCase::MiniATX;
                    break;
                case 8: formFactor = ComputerCase::FlexATX;
                    break;
                case 9: formFactor = ComputerCase::MiniITX;
                    break;
                case 10: formFactor = ComputerCase::NanoITX;
                    break;
                case 11: formFactor = ComputerCase::PicoITX;
                    break;
                case 12: formFactor = ComputerCase::MobileITX;
                    break;
                case 13: formFactor = ComputerCase::NeoITX;
                    break;
                case 14: formFactor = ComputerCase::BTX;
                    break;
                case 15: formFactor = ComputerCase::MicroBTX;
                    break;
                case 16: formFactor = ComputerCase::PicoBTX;
                    break;
                case 17: formFactor = ComputerCase::DTX;
                    break;
                case 18: formFactor = ComputerCase::MiniDTX;
                    break;
                case 19: formFactor = ComputerCase::ETX;
                    break;
                case 20: formFactor = ComputerCase::CoreExpress;
                    break;
                case 21: formFactor = ComputerCase::Extended_ATX;
                    break;
                case 22: formFactor = ComputerCase::Enhanced_Extended_ATX;
                    break;
                case 23: formFactor = ComputerCase::LPX;
                    break;
                case 24: formFactor = ComputerCase::MiniLPX;
                    break;
                case 25: formFactor = ComputerCase::PC_104;
                    break;
                case 26: formFactor = ComputerCase::NLX;
                    break;
                case 27: formFactor = ComputerCase::UTX;
                    break;
                case 28: formFactor = ComputerCase::WTX;
                    break;
                case 29: formFactor = ComputerCase::SWTX;
                    break;
                case 30: formFactor = ComputerCase::HPTX;
                    break;
                case 31: formFactor = ComputerCase::XTX;
                    break;
                default: std::cout << "Нет такого форм-фактора материнской платы." << endl;
                    break;
                }
        strFromFile.erase(0, index + 1);

        index = strFromFile.find(';');
        float metalThickness = atof(strFromFile.substr(0, index).c_str());
        strFromFile.erase(0, index + 1);

        index = strFromFile.find(';');
        ComputerCase::unit _525InchBay = atoi(strFromFile.substr(0, index).c_str());
        strFromFile.erase(0, index + 1);

        index = strFromFile.find(';');
        ComputerCase::unit _35InchBay = atoi(strFromFile.substr(0, index).c_str());
        strFromFile.erase(0, index + 1);

        index = strFromFile.find(';');
        ComputerCase::unit _35InchBayIn = atoi(strFromFile.substr(0, index).c_str());
        strFromFile.erase(0, index + 1);

        index = strFromFile.find(';');
        ComputerCase::unit PCISlots = atoi(strFromFile.substr(0, index).c_str());
        strFromFile.erase(0, index + 1);

        index = strFromFile.find(';');
        bool possibilityOfWaterCooling = false;
        if (atoi(strFromFile.substr(0, index).c_str()))
            possibilityOfWaterCooling = true;
        strFromFile.erase(0, index + 1);

        index = strFromFile.find(';');
        bool featurePSU = false;
        if (atoi(strFromFile.substr(0, index).c_str()))
            featurePSU = true;
        strFromFile.erase(0, index + 1);

        index = strFromFile.find(';');
        float Depth = atof(strFromFile.substr(0, index).c_str());
        strFromFile.erase(0, index + 1);

        index = strFromFile.find(';');
        float Width = atof(strFromFile.substr(0, index).c_str());
        strFromFile.erase(0, index + 1);

        index = strFromFile.find(';');
        float Height = atof(strFromFile.substr(0, index).c_str());
        strFromFile.erase(0, index + 1);

        // Записываем все прочитанные данные в базу
        db.add( manufacturer,
                model,
                color,
                material,
                type,
                formFactor,
                metalThickness,
                _525InchBay,
                _35InchBay,
                _35InchBayIn,
                PCISlots,
                possibilityOfWaterCooling,
                featurePSU,
                Depth,
                Width,
                Height);

        // Считаем количество строк в файле
        numRows++;
    }

    cout << "Прочитано строк: " << numRows << endl;

    // Закрываем поток "inFile"
    inFile.close();

    return numRows;
}

bool ManageDB::save(const std::string filename, DataBase& db, const size_t numRows)
{
    // Создаём поток "outFile" на запись
    // и ассоциируем его с файлом filename
    fstream outFile(filename.c_str(), ios_base::out);

    // Делаем проверку открыт ли файл
    if ( !outFile.is_open() ) {
        // Если файл не открыт, то выдаём пользователю
        // сообщение и выходим из программы
        cerr << "Ошибка открытия файла!" << endl;
        exit(1);
    }

    cout << "Запись в файл." << endl;

    // Записываем в файл по строчно данные из структуры "db"
    // каждая строка при этом оканчивается символом переноса
    // на следующую строку "\n"
    for (size_t i = 0; i < numRows - 1; i++) {
        ComputerCase& outcc = db.get(i);
        outFile << outcc.GetManufacturer() << ";"
                << outcc.GetModel() << ";"
                << outcc.GetColor() << ";"
                << outcc.GetMaterial() << ";"
                << outcc.GetType() << ";"
                << outcc.GetFormFactor() << ";"
                << outcc.GetMetalThickness() << ";"
                << outcc.Get525InchBay() << ";"
                << outcc.Get35InchBay() << ";"
                << outcc.Get35InchBayIn() << ";"
                << outcc.GetPCISlots() << ";"
                << outcc.GetPossibilityOfWaterCooling() << ";"
                << outcc.GetFeaturePSU() << ";"
                << outcc.GetDepth() << ";"
                << outcc.GetWidth() << ";"
                << outcc.GetHeight() << ";" << endl;
    }
    // Записываем последнюю строчку без символа переноса "\n" курсора.
    ComputerCase& outcc = db.get(numRows - 1);
    outFile << outcc.GetManufacturer() << ";"
            << outcc.GetModel() << ";"
            << outcc.GetColor()  << ";"
            << outcc.GetMaterial() << ";"
            << outcc.GetType() << ";"
            << outcc.GetFormFactor() << ";"
            << outcc.GetMetalThickness() << ";"
            << outcc.Get525InchBay() << ";"
            << outcc.Get35InchBay() << ";"
            << outcc.Get35InchBayIn() << ";"
            << outcc.GetPCISlots() << ";"
            << outcc.GetPossibilityOfWaterCooling() << ";"
            << outcc.GetFeaturePSU() << ";"
            << outcc.GetDepth() << ";"
            << outcc.GetWidth() << ";"
            << outcc.GetHeight() << ";";

    // Закрываем поток "outFile"
    outFile.close();

    return true;
}

size_t ManageDB::addManual(DataBase& db)
{
    // Добавление новой записи в базу данных
    std::cout << "Введите наименование производителя корпуса: ";
    string newManufacturer;
    getline(cin, newManufacturer);

    std::cout << "Введите наименование модели корпуса: ";
    string newModel;
    getline(cin, newModel);

    std::cout << "Введите цвет корпуса: ";
    string newColor;
    getline(cin, newColor);

    std::cout << "1) сталь" << endl;
    std::cout << "2) алюминий" << endl;
    std::cout << "Выберите из приведённых вариантов материал корпуса: ";
    ComputerCase::materialType newMaterial;
    unsigned mater = 0;
    std::cin >> mater;

    switch (mater) {
    case 0: newMaterial = ComputerCase::NOmt;
        break;
    case 1: newMaterial = ComputerCase::steel;
        break;
    case 2: newMaterial = ComputerCase::aluminium;
        break;
    default: std::cout << "Нет такого материала." << endl;
        break;
    }

    std::cout << "1) DeskTop" << endl;
    std::cout << "2) FootPrint" << endl;
    std::cout << "3) SlimLine" << endl;
    std::cout << "4) UltraSlimLine" << endl;
    std::cout << "5) MiniTower" << endl;
    std::cout << "6) MidiTower" << endl;
    std::cout << "7) BigTower" << endl;
    std::cout << "8) SuperFullTower" << endl;
    std::cout << "Выберите из приведённых вариантов тип корпуса: ";
    ComputerCase::typeType newType;
    int tp = 0;
    std::cin >> tp;

    switch (tp) {
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
        default: std::cout << "Нет такого типа корпуса." << endl;
            break;
    }

    std::cout << "1) XT      " << "11) PicoITX    " << "21) Extended_ATX         " << "31) XTX" << endl;
    std::cout << "2) AT      " << "12) MobileITX  " << "22) Enhanced_Extended_ATX" << endl;
    std::cout << "3) BabyAT  " << "13) NeoITX     " << "23) LPX                  " << endl;
    std::cout << "4) ATX     " << "14) BTX        " << "24) MiniLPX              " << endl;
    std::cout << "5) SSI_CEB " << "15) MicroBTX   " << "25) PC_104               " << endl;
    std::cout << "6) microATX" << "16) PicoBTX    " << "26) NLX                  " << endl;
    std::cout << "7) MiniATX " << "17) DTX        " << "27) UTX                  " << endl;
    std::cout << "8) FlexATX " << "18) MiniDTX    " << "28) WTX                  " << endl;
    std::cout << "9) MiniITX " << "19) ETX        " << "29) SWTX                 " << endl;
    std::cout << "10) NanoITX" << "20) CoreExpress" << "30) HPTX                 " << endl;
    std::cout << "Выберите из приведённых вариантов форм-фактор корпуса: ";
    ComputerCase::formFactorType newFormFactor;
    int ff = 0;
    std::cin >> ff;

    switch (ff)
    {
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
        default: std::cout << "Нет такого форм-фактора материнской платы" << endl;
            break;
    }

    std::cout << "Введите толщину металла (мм) корпуса: ";
    float newMetalThickness;
    std::cin >> newMetalThickness;

    std::cout << "Введите количество 5,25 дюймовых внешних отсеков в корпусе: ";
    ComputerCase::unit new_525InchBay;
    std::cin >> new_525InchBay;

    std::cout << "Введите количество 3,5 дюймовых внешних отсеков в корпусе: ";
    ComputerCase::unit new_35InchBay;
    std::cin >> new_35InchBay;

    std::cout << "Введите количество 3,5 дюймовых внутренних отсеков в корпусе: ";
    ComputerCase::unit new_35InchBayIn;
    std::cin >> new_35InchBayIn;

    std::cout << "Введите количество разъёмов под слоты PCI: ";
    ComputerCase::unit newPCISlots;
    std::cin >> newPCISlots;

    std::cout << "Укажите возможность водяного охлаждения: ";
    bool newPossibilityOfWaterCooling;
    std::cin >> newPossibilityOfWaterCooling;

    std::cout << "Укажите наличие в комплекте блока питания: ";
    bool newFeaturePSU;
    std::cin >> newFeaturePSU;

    std::cout << "Введите глубину корпуса: ";
    float newDepth;
    std::cin >> newDepth;

    std::cout << "Введите ширину корпуса: ";
    float newWidth;
    std::cin >> newWidth;

    std::cout << "Введите высоту корпуса: ";
    float newHeight;
    std::cin >> newHeight;

    // Записываем все полученные от пользователя данные в базу
    db.add(newManufacturer,
        newModel,
        newColor,
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

    return db.getNumSlots();
}

bool ManageDB::modManual(DataBase& db)
{
    // Пользователю выводится меню, после просмотра которого,
    // пользователь выберает подходящий ему вариант
    std::cout << "Введите номер той записи в БД, которую хотите исправить: ";
    unsigned short numdb;
    string str;
    str = cin.get();
    istringstream ist(str);
    ist >> numdb;
    if (numdb > db.getNumSlots()) {
        cout << "Такой записи нет." << endl;
        // Если в потоке ввода остались символы, то мы их удаляем (игнорируем)
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return false;
    }
    std::cout << "Можно отредактировать следующие данные о системном блоке компьютера: \n";
    std::cout << "1) Наименование производителя.\n";
    std::cout << "2) Наименование модели.\n";
    std::cout << "3) Цвет.\n";
    std::cout << "4) Материал.\n";
    std::cout << "5) Тип.\n";
    std::cout << "6) Форм-фактор.\n";
    std::cout << "7) Толщину металла (мм) корпуса.\n";
    std::cout << "8) Количество 5,25 дюймовых внешних отсеков.\n";
    std::cout << "9) Количество 3,5 дюймовых внешних отсеков.\n";
    std::cout << "10) Количество 3,5 дюймовых внутренних отсеков.\n";
    std::cout << "11) Количество разъёмов под слоты PCI.\n";
    std::cout << "12) Возможность водяного охлаждения.\n";
    std::cout << "13) Наличие в комплекте блока питания.\n";
    std::cout << "14) Глубину.\n";
    std::cout << "15) Ширину.\n";
    std::cout << "16) Высоту." << endl;

    // Если в потоке ввода остались символы, то мы их удаляем (игнорируем)
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Введите номер раздела записи, который хотите исправить: ";
    unsigned short nump;
    str = cin.get();
    istringstream ist2(str);
    ist2 >> nump;

    switch (nump) {
        case 1:
            std::cout << "Введите наименование производителя системного блока: ";
            break;
        case 2:
            std::cout << "Введите наименование модели: ";
            break;
        case 3:
            std::cout << "Введите цвет корпуса: ";
            break;
        case 4:
            std::cout << "1) сталь" << endl;
            std::cout << "2) алюминий" << endl;
            std::cout << "Выберите из приведённых вариантов материал корпуса: ";
            break;
        case 5:
            std::cout << "1) DeskTop" << endl;
            std::cout << "2) FootPrint" << endl;
            std::cout << "3) SlimLine" << endl;
            std::cout << "4) UltraSlimLine" << endl;
            std::cout << "5) MiniTower" << endl;
            std::cout << "6) MidiTower" << endl;
            std::cout << "7) BigTower" << endl;
            std::cout << "8) SuperFullTower" << endl;
            std::cout << "Выберите из приведённых вариантов тип корпуса: ";
            break;
        case 6:
            std::cout << "1) XT       " << "11) PicoITX     " << "21) Extended_ATX          " << "31) XTX" << endl;
            std::cout << "2) AT       " << "12) MobileITX   " << "22) Enhanced_Extended_ATX " << endl;
            std::cout << "3) BabyAT   " << "13) NeoITX      " << "23) LPX                   " << endl;
            std::cout << "4) ATX      " << "14) BTX         " << "24) MiniLPX               " << endl;
            std::cout << "5) SSI_CEB  " << "15) MicroBTX    " << "25) PC_104                " << endl;
            std::cout << "6) microATX " << "16) PicoBTX     " << "26) NLX                   " << endl;
            std::cout << "7) MiniATX  " << "17) DTX         " << "27) UTX                   " << endl;
            std::cout << "8) FlexATX  " << "18) MiniDTX     " << "28) WTX                   " << endl;
            std::cout << "9) MiniITX  " << "19) ETX         " << "29) SWTX                  " << endl;
            std::cout << "10) NanoITX " << "20) CoreExpress " << "30) HPTX                  " << endl;
            std::cout << "Выберите из приведённых вариантов форм-фактор корпуса: ";
            break;
        case 7:
            std::cout << "Введите толщину металла (мм) корпуса: ";
            break;
        case 8:
            std::cout << "Введите количество 5,25 дюймовых внешних отсеков: ";
            break;
        case 9:
            std::cout << "Введите количество 3,5 дюймовых внешних отсеков: ";
            break;
        case 10:
            std::cout << "Введите количество 3,5 дюймовых внутренних отсеков: ";
            break;
        case 11:
            std::cout << "Введите количество разъёмов под слоты PCI: ";
            break;
        case 12:
            std::cout << "Укажите возможность водяного охлаждения: ";
            break;
        case 13:
            std::cout << "Укажите наличие в комплекте блока питания: ";
            break;
        case 14:
            std::cout << "Введите глубину корпуса: ";
            break;
        case 15:
            std::cout << "Введите ширину корпуса: ";
            break;
        case 16:
            std::cout << "Введите высоту корпуса: ";
            break;
    }

    // Если в потоке ввода остались символы, то мы их удаляем (игнорируем)
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    string newString;
    // Ввод пользователем нового значения
    getline(cin, newString);

    db.mod(numdb - 1, nump - 1, newString);

    return true;
}

size_t ManageDB::delManual(DataBase& db)
{
    unsigned num = 0;
    if (db.isFirstLast()) {
        std::cout << "Удалён последний элемент!" << endl;
        db.del(0);
        return db.getNumSlots();
    }
    std::cout << "Введите номер удаляемой записи: ";
    string str;
    str = cin.get();
    istringstream ist(str);
    ist >> num;

    // Если в потоке ввода остались символы, то мы их удаляем (игнорируем)
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (!db.del(num - 1)) std::cout << "Не удалось удалить запись из базы!" << endl;

    return db.getNumSlots();
}

bool ManageDB::findManual(DataBase& db)
{
    std::cout << "1) Поиск по производителю.\n";
    std::cout << "2) Поиск по наименованию модели." << endl;
    std::cout << "Выберите из вариантов по которому хотите осуществить поиск: ";

    unsigned short num;
    string str;
    str = cin.get();
    istringstream ist(str);
    ist >> num;
    ComputerCase ccFinded;
    // Если в потоке ввода остались символы, то мы их удаляем (игнорируем)
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (num) {
    case 1:
        std::cout << "Введите наименование производителя системного блока: " << endl;
        getline(cin, str);
        ccFinded = db.findByManufacturer(str);
        break;

    case 2:
        std::cout << "Введите наименование модели системного блока: " << endl;
        getline(cin, str);
        ccFinded = db.findByModel(str);
        break;

    default:
        std::cout << "Ведён не корректный вариант поиска!" << endl;
        return false;
        break;
    }

    // При удачном поиске выводим найденый элемент на экран
    if (!ccFinded.isEmpty()) {
        std::cout << "Вот информация по системному блоку, который вы искали.";
        ccFinded.printAllPropertys();
        return true;
    }
    else
        return false;
}

