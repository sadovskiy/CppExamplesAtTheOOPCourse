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

#ifndef COMPUTERCASE_H
#define COMPUTERCASE_H

#include <iostream>

// Класс "ComputerCase" является моделью системного блока компьютера
class ComputerCase
{
    public:
        // Создаём тип данных "materialType" - тип материала корпуса системного блока
        enum materialType {NOmt, steel, aluminium};
        // Создаём тип данных "typeType" - тип корпуса системного блока
        enum typeType {
                    NOtp,
                    DeskTop,
                    FootPrint,
                    SlimLine,
                    UltraSlimLine,
                    MiniTower,
                    MidiTower,
                    BigTower,
                    SuperFullTower};
        // Создаём тип данных "formFactorType" - форм-фактор материнской платы,
        // устанавливаемой в системный блок
        enum formFactorType {
                            NOff,
                            XT,
                            AT,
                            BabyAT,
                            ATX,
                            SSI_CEB,
                            microATX,
                            MiniATX,
                            FlexATX,
                            MiniITX,
                            NanoITX,
                            PicoITX,
                            MobileITX,
                            NeoITX,
                            BTX,
                            MicroBTX,
                            PicoBTX,
                            DTX,
                            MiniDTX,
                            ETX,
                            CoreExpress,
                            Extended_ATX,
                            Enhanced_Extended_ATX,
                            LPX,
                            MiniLPX,
                            PC_104,
                            NLX,
                            UTX,
                            WTX,
                            SWTX,
                            HPTX,
                            XTX};
        // Создадим новый тип данных для единиц измерения "unit"
        typedef unsigned int unit;
        // Зададим 16 свойств описывающих наш системный блок
    private:
        size_t No;
        std::string manufacturer;        // Производитель
        std::string model;               // Модель системного блока
        std::string color;               // Основной цвет
        materialType material;      // Материал корпуса
        typeType type;              // Тип копуса
        formFactorType formFactor;  // Форм-фактор
        float metalThickness;       // Толщина металла (мм)
        unit _525InchBay;           // Количество 5,25 дюймовых отсеков внешних
        unit _35InchBay;            // Количество 3,5 дюймовых отсеков внешних
        unit _35InchBayIn;          // Количество 3,5 дюймовых отсеков внутренних
        unit PCISlots;              // Количество разъёмов под слоты PCI
        bool possibilityOfWaterCooling; // Возможность водяного охлаждения
        bool featurePSU;            // Наличие в комплекте блока питания
        float Depth;                // Глубина
        float Width;                // Ширина
        float Height;               // Высота
    public:
        ComputerCase();
        ~ComputerCase();
        ComputerCase(const ComputerCase& other);
        ComputerCase(const size_t _No,
                     const std::string _manufacturer,
                     const std::string _model,
                     const std::string _color,
                     const materialType _material,
                     const typeType _type,
                     const formFactorType _formFactor,
                     const float _metalThickness,
                     const unit __525InchBay,
                     const unit __35InchBay,
                     const unit __35InchBayIn,
                     const unit _PCISlots,
                     const bool _possibilityOfWaterCooling,
                     const bool _featurePSU,
                     const float _Depth,
                     const float _Width,
                     const float _Height);

        ComputerCase& operator=(const ComputerCase& other);

        // Ниже приведены методы манипулирования данными.

        // Записываем все данные, вызвав один метод
        void setComputerCase(   const size_t _No,
                                const std::string _manufacturer,
                                const std::string _model,
                                const std::string _color,
                                const materialType _material,
                                const typeType _type,
                                const formFactorType _formFactor,
                                const float _metalThickness,
                                const unit __525InchBay,
                                const unit __35InchBay,
                                const unit __35InchBayIn,
                                const unit _PCISlots,
                                const bool _possibilityOfWaterCooling,
                                const bool _featurePSU,
                                const float _Depth,
                                const float _Width,
                                const float _Height);

        // Далее перечислены методы записывающие и читающие
        // данные по отдельности
        void SetNo(const size_t _No);
        size_t GetNo() const;

        void SetManufacturer(const std::string _manufacturer);
        std::string GetManufacturer() const;

        void SetModel(const std::string _model);
        std::string GetModel() const;

        void SetColor(const std::string _color);
        std::string GetColor() const;

        void SetMaterial(const materialType _material);
        materialType GetMaterial() const;

        void SetType(const typeType _type);
        typeType GetType() const;

        void SetFormFactor(const formFactorType _formFactor);
        formFactorType GetFormFactor() const;

        void SetMetalThickness(const float _metalThickness);
        float GetMetalThickness() const;

        void Set525InchBay(const unit __525InchBay);
        unit Get525InchBay() const;

        void Set35InchBay(const unit __35InchBay);
        unit Get35InchBay() const;

        void Set35InchBayIn(const unit __35InchBayIn);
        unit Get35InchBayIn() const;

        void SetPCISlots(const unit _PCISlots);
        unit GetPCISlots() const;

        void SetPossibilityOfWaterCooling(const bool _possibilityOfWaterCooling);
        bool GetPossibilityOfWaterCooling() const;

        void SetFeaturePSU(const bool _featurePSU);
        bool GetFeaturePSU() const;

        void SetDepth(const float _Depth);
        float GetDepth() const;

        void SetWidth(const float _Width);
        float GetWidth() const;

        void SetHeight(const float _Height);
        float GetHeight() const;

        void printAllPropertys() const;

        friend std::ostream& operator<<(std::ostream& os, const ComputerCase& cc);

        // Метод проверки "пуст ли объект"
        bool isEmpty() const;
};

#endif // COMPUTERCASE_H
