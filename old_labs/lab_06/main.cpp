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

#include <iostream>
#include "computercase.hpp"

int main()
{
    // Создадим две константы, более подходящих в нашем случае,
    // чем использование ключевых слов true и false
    const bool yes = true;
    const bool no = false;
    // Создадим объект - корпус компьютера и одновременно проверим работу
    // параметризованного конструктора для инициализации данных
    ComputerCase cCase1("Thermaltake",
                        "Element T VK90001N2Z",
                        "black",
                        ComputerCase::steel,
                        ComputerCase::MidiTower,
                        ComputerCase::ATX,
                        0.8,
                        3,
                        6,
                        1,
                        5,
                        yes,
                        no,
                        525,
                        210,
                        480);
    // Выведем на экран наш объект, то есть распечатаем содержимое всех его данных
    cCase1.printAllPropertys();

    // Создадим объект "корпус компьютера 2" и одновременно проверим работу
    // конструктора копирования
    ComputerCase cCase2(cCase1);
    // Сделаем контрольную распечатку на экран содержимого объекта
    cCase2.printAllPropertys();

    // Создадим объект "корпус компьютера 3" и одновременно проверим работу
    // конструктора по умолчанию
    ComputerCase cCase3;
    // Проверим работу перегруженного оператора присваивания
    cCase3 = cCase2;
    // Сделаем контрольную распечатку на экран содержимого объекта
    cCase3.printAllPropertys();

    // Создадим объект "корпус компьютера 4"
    ComputerCase cCase4;
    // Проверим работу методов по записи/извлечения данных по
    // отдельности
    cCase4.SetManufacturer(cCase1.GetManufacturer());
    cCase4.SetModel(cCase1.GetModel());
    cCase4.SetColor(cCase1.GetColor());
    cCase4.SetMaterial(cCase1.GetMaterial());
    cCase4.SetType(cCase1.GetType());
    cCase4.SetFormFactor(cCase1.GetFormFactor());
    cCase4.SetMetalThickness(cCase1.GetMetalThickness());
    cCase4.Set525InchBay(cCase1.Get525InchBay());
    cCase4.Set35InchBay(cCase1.Get35InchBay());
    cCase4.Set35InchBayIn(cCase1.Get35InchBayIn());
    cCase4.SetPCISlots(cCase1.GetPCISlots());
    cCase4.SetPossibilityOfWaterCooling(cCase1.GetPossibilityOfWaterCooling());
    cCase4.SetFeaturePSU(cCase1.GetFeaturePSU());
    cCase4.SetDepth(cCase1.GetDepth());
    cCase4.SetWidth(cCase1.GetWidth());
    cCase4.SetHeight(cCase1.GetHeight());

    // Сделаем контрольную распечатку на экран содержимого объекта,
    // чтобы проверить правильность копирования
    cCase4.printAllPropertys();

    // Создадим объект "корпус компьютера 5"
    ComputerCase cCase5;
    // Проверим работу метода "записи всех данных"
    cCase5.setComputerCase( "Lian Li",
                            "PC-Q11W",
                            "white",
                            ComputerCase::aluminium,
                            ComputerCase::MiniTower,
                            ComputerCase::MiniITX,
                            0.6,
                            1,
                            0,
                            1,
                            2,
                            no,
                            no,
                            260,
                            200,
                            326);

    // Проверим работу перегруженного метода "поместить в поток"
    std::cout << cCase5;

    return 0;
}
