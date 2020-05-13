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

#include "computercase.hpp"

// В данном файле описываются различные методы (функции-члены).
// Делается это так же как и в предыдущих лабораторных работах
ComputerCase::ComputerCase():   No(0),
                                manufacturer(""),
                                model(""),
                                color(""),
                                material(),
                                type(),
                                formFactor(),
                                metalThickness(0.0),
                                _525InchBay(0),
                                _35InchBay(0),
                                _35InchBayIn(0),
                                PCISlots(0),
                                possibilityOfWaterCooling(false),
                                featurePSU(false),
                                Depth(0.0),
                                Width(0.0),
                                Height(0.0)
{

}

ComputerCase::~ComputerCase()
{

}

ComputerCase::ComputerCase(const ComputerCase& other)
{
    No                          = other.No;
    manufacturer                = other.manufacturer;
    model                       = other.model;
    color                       = other.color;
    material                    = other.material;
    type                        = other.type;
    formFactor                  = other.formFactor;
    metalThickness              = other.metalThickness;
    _525InchBay                 = other._525InchBay;
    _35InchBay                  = other._35InchBay;
    _35InchBayIn                = other._35InchBayIn;
    PCISlots                    = other.PCISlots;
    possibilityOfWaterCooling   = other.possibilityOfWaterCooling;
    featurePSU                  = other.featurePSU;
    Depth                       = other.Depth;
    Width                       = other.Width;
    Height                      = other.Height;
}

ComputerCase& ComputerCase::operator=(const ComputerCase& rhs)
{
    if (this == &rhs) return *this;
    No                          = rhs.No;
    manufacturer                = rhs.manufacturer;
    model                       = rhs.model;
    color                       = rhs.color;
    material                    = rhs.material;
    type                        = rhs.type;
    formFactor                  = rhs.formFactor;
    metalThickness              = rhs.metalThickness;
    _525InchBay                 = rhs._525InchBay;
    _35InchBay                  = rhs._35InchBay;
    _35InchBayIn                = rhs._35InchBayIn;
    PCISlots                    = rhs.PCISlots;
    possibilityOfWaterCooling   = rhs.possibilityOfWaterCooling;
    featurePSU                  = rhs.featurePSU;
    Depth                       = rhs.Depth;
    Width                       = rhs.Width;
    Height                      = rhs.Height;

    return *this;
}

ComputerCase::ComputerCase( const size_t _No,
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
                            const float _Height):   No(_No),
                                                    manufacturer(_manufacturer),
                                                    model(_model),
                                                    color(_color),
                                                    material(_material),
                                                    type(_type),
                                                    formFactor(_formFactor),
                                                    metalThickness(_metalThickness),
                                                    _525InchBay(__525InchBay),
                                                    _35InchBay(__35InchBay),
                                                    _35InchBayIn(__35InchBayIn),
                                                    PCISlots(_PCISlots),
                                                    possibilityOfWaterCooling(_possibilityOfWaterCooling),
                                                    featurePSU(_featurePSU),
                                                    Depth(_Depth),
                                                    Width(_Width),
                                                    Height(_Height)
{

}

void ComputerCase::setComputerCase( const size_t _No,
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
                                    const float _Height)
{
    No                          = _No;
    manufacturer                = _manufacturer;
    model                       = _model;
    color                       = _color;
    material                    = _material;
    type                        = _type;
    formFactor                  = _formFactor;
    metalThickness              = _metalThickness;
    _525InchBay                 = __525InchBay;
    _35InchBay                  = __35InchBay;
    _35InchBayIn                = __35InchBayIn;
    PCISlots                    = _PCISlots;
    possibilityOfWaterCooling   = _possibilityOfWaterCooling;
    featurePSU                  = _featurePSU;
    Depth                       = _Depth;
    Width                       = _Width;
    Height                      = _Height;
}

void ComputerCase::SetNo(const size_t _No)
{
    No =_No;
}

size_t ComputerCase::GetNo() const
{
    return No;
}

void ComputerCase::SetManufacturer(const std::string _manufacturer)
{
    manufacturer = _manufacturer;
}

std::string ComputerCase::GetManufacturer() const
{
    return manufacturer;
}

void ComputerCase::SetModel(const std::string _model)
{
    model = _model;
}

std::string ComputerCase::GetModel() const
{
    return model;
}

void ComputerCase::SetColor(const std::string _color)
{
    color = _color;
}

std::string ComputerCase::GetColor() const
{
    return color;
}

void ComputerCase::SetMaterial(const materialType _material)
{
    material = _material;
}

ComputerCase::materialType ComputerCase::GetMaterial() const
{
    return material;
}

void ComputerCase::SetType(const typeType _type)
{
    type = _type;
}

ComputerCase::typeType ComputerCase::GetType() const
{
    return type;
}

void ComputerCase::SetFormFactor(const formFactorType _formFactor)
{
    formFactor = _formFactor;
}

ComputerCase::formFactorType ComputerCase::GetFormFactor() const
{
    return formFactor;
}

void ComputerCase::SetMetalThickness(const float _metalThickness)
{
    metalThickness = _metalThickness;
}

float ComputerCase::GetMetalThickness() const
{
    return metalThickness;
}

void ComputerCase::Set525InchBay(const unit __525InchBay)
{
    _525InchBay = __525InchBay;
}

ComputerCase::unit ComputerCase::Get525InchBay() const
{
    return _525InchBay;
}

void ComputerCase::Set35InchBay(const unit __35InchBay)
{
    _35InchBay = __35InchBay;
}

ComputerCase::unit ComputerCase::Get35InchBay() const
{
    return _35InchBay;
}

void ComputerCase::Set35InchBayIn(const unit __35InchBayIn)
{
    _35InchBayIn = __35InchBayIn;
}

ComputerCase::unit ComputerCase::Get35InchBayIn() const
{
    return _35InchBayIn;
}

void ComputerCase::SetPCISlots(const unit _PCISlots)
{
    PCISlots = _PCISlots;
}

ComputerCase::unit ComputerCase::GetPCISlots() const
{
    return PCISlots;
}

void ComputerCase::SetPossibilityOfWaterCooling(const bool _possibilityOfWaterCooling)
{
    possibilityOfWaterCooling = _possibilityOfWaterCooling;
}

bool ComputerCase::GetPossibilityOfWaterCooling() const
{
    return possibilityOfWaterCooling;
}

void ComputerCase::SetFeaturePSU(const bool _featurePSU)
{
    featurePSU = _featurePSU;
}

bool ComputerCase::GetFeaturePSU() const
{
    return featurePSU;
}

void ComputerCase::SetDepth(const float _Depth)
{
    Depth = _Depth;
}

float ComputerCase::GetDepth() const
{
    return Depth;
}

void ComputerCase::SetWidth(const float _Width)
{
    Width = _Width;
}

float ComputerCase::GetWidth() const
{
    return Width;
}

void ComputerCase::SetHeight(const float _Height)
{
    Height = _Height;
}

float ComputerCase::GetHeight() const
{
    return Height;
}

void ComputerCase::printAllPropertys() const
{
    std::cout    << "\n--------------------------------------\n"
            << "Computer case\n"
            << "Manufacturer: " << manufacturer << "\n"
            << "Model: " << model << "\n"
            << "Color: " << color << "\n";

    switch (material)
    {
        case NOmt:      std::cout << "Material: No\n";
            break;
        case steel:     std::cout << "Material: steel\n";
            break;
        case aluminium: std::cout << "Material: aluminium\n";
            break;

        default:        std::cout << "Material: not defined!\n";
            break;
    }

    switch (type)
    {
        case NOtp:           std::cout << "Type: No\n";
            break;
        case DeskTop:        std::cout << "Type: DeskTop\n";
            break;
        case FootPrint:      std::cout << "Type: FootPrint\n";
            break;
        case SlimLine:       std::cout << "Type: SlimLine\n";
            break;
        case UltraSlimLine:  std::cout << "Type: UltraSlimLine\n";
            break;
        case MiniTower:      std::cout << "Type: MiniTower\n";
            break;
        case MidiTower:      std::cout << "Type: MidiTower\n";
            break;
        case BigTower:       std::cout << "Type: BigTower\n";
            break;
        case SuperFullTower: std::cout << "Type: SuperFullTower\n";
            break;

        default:             std::cout << "Type: not defined!\n";
            break;
    }


    switch (formFactor)
    {
        case NOff:                  std::cout << "Formfactor: No\n";
            break;
        case XT:                    std::cout << "Formfactor: XT\n";
            break;
        case AT:                    std::cout << "Formfactor: AT\n";
            break;
        case BabyAT:                std::cout << "Formfactor: BabyAT\n";
            break;
        case ATX:                   std::cout << "Formfactor: ATX\n";
            break;
        case SSI_CEB:               std::cout << "Formfactor: SSI_CEB\n";
            break;
        case microATX:              std::cout << "Formfactor: microATX\n";
            break;
        case MiniATX:               std::cout << "Formfactor: MiniATX\n";
            break;
        case FlexATX:               std::cout << "Formfactor: FlexATX\n";
            break;
        case MiniITX:               std::cout << "Formfactor: MiniITX\n";
            break;
        case NanoITX:               std::cout << "Formfactor: NanoITX\n";
            break;
        case PicoITX:               std::cout << "Formfactor: PicoITX\n";
            break;
        case MobileITX:             std::cout << "Formfactor: MobileITX\n";
            break;
        case NeoITX:                std::cout << "Formfactor: NeoITX\n";
            break;
        case BTX:                   std::cout << "Formfactor: BTX\n";
            break;
        case MicroBTX:              std::cout << "Formfactor: MicroBTX\n";
            break;
        case PicoBTX:               std::cout << "Formfactor: PicoBTX\n";
            break;
        case DTX:                   std::cout << "Formfactor: DTX\n";
            break;
        case MiniDTX:               std::cout << "Formfactor: MiniDTX\n";
            break;
        case ETX:                   std::cout << "Formfactor: ETX\n";
            break;
        case CoreExpress:           std::cout << "Formfactor: CoreExpress\n";
            break;
        case Extended_ATX:          std::cout << "Formfactor: Extended_ATX\n";
            break;
        case Enhanced_Extended_ATX: std::cout << "Formfactor: Enhanced_Extended_ATX\n";
            break;
        case LPX:                   std::cout << "Formfactor: LPX\n";
            break;
        case MiniLPX:               std::cout << "Formfactor: MiniLPX\n";
            break;
        case PC_104:                std::cout << "Formfactor: PC_104\n";
            break;
        case NLX:                   std::cout << "Formfactor: NLX\n";
            break;
        case UTX:                   std::cout << "Formfactor: UTX\n";
            break;
        case WTX:                   std::cout << "Formfactor: WTX\n";
            break;
        case SWTX:                  std::cout << "Formfactor: SWTX\n";
            break;
        case HPTX:                  std::cout << "Formfactor: HPTX\n";
            break;
        case XTX:                   std::cout << "Formfactor: XTX\n";
            break;

        default:                    std::cout << "Formfactor: not defined!\n";
            break;
    }



    std::cout       << "Metall: " << metalThickness << "\n"
                    << "5,25 Inch Bay: " << _525InchBay << "\n"
                    << "3,5 Inch Bay: " << _35InchBay << "\n"
                    << "3,5 Inch Bay inernal: " << _35InchBayIn << "\n"
                    << "PCI slots: " << PCISlots << "\n";
    if (possibilityOfWaterCooling)
        std::cout   << "WaterCooling: yes" << "\n";
    else
        std::cout   << "WaterCooling: no" << "\n";
    if (featurePSU)
        std::cout   << "PSU: yes" << "\n";
    else
        std::cout   << "PSU: no" << "\n";

    std::cout       << "Depth: "  << Depth  << "\n"
                    << "Width: "  << Width  << "\n"
                    << "Height: " << Height << std::endl;
}

std::ostream& operator<<(std::ostream& os, const ComputerCase& cc)
{
   os    << "\n--------------------------------------\n"
            << "Computer case\n"
            << "Manufacturer: " << cc.manufacturer << "\n"
            << "Model: " << cc.model << "\n"
            << "Color: " << cc.color << "\n";

    switch (cc.material)
    {
        case ComputerCase::NOmt:        os << "Material: No\n";
            break;
        case ComputerCase::steel:       os << "Material: steel\n";
            break;
        case ComputerCase::aluminium:   os << "Material: aluminium\n";
            break;

        default:                        os << "Material: not defined!\n";
            break;
    }

    switch (cc.type)
    {
        case ComputerCase::NOtp:            os << "Type: No\n";
            break;
        case ComputerCase::DeskTop:         os << "Type: DeskTop\n";
            break;
        case ComputerCase::FootPrint:       os << "Type: FootPrint\n";
            break;
        case ComputerCase::SlimLine:        os << "Type: SlimLine\n";
            break;
        case ComputerCase::UltraSlimLine:   os << "Type: UltraSlimLine\n";
            break;
        case ComputerCase::MiniTower:       os << "Type: MiniTower\n";
            break;
        case ComputerCase::MidiTower:       os << "Type: MidiTower\n";
            break;
        case ComputerCase::BigTower:        os << "Type: BigTower\n";
            break;
        case ComputerCase::SuperFullTower:  os << "Type: SuperFullTower\n";
            break;

        default:                            os << "Type: not defined!\n";
            break;
    }


    switch (cc.formFactor)
    {
        case ComputerCase::NOff:                    os << "Formfactor: No\n";
            break;
        case ComputerCase::XT:                      os << "Formfactor: XT\n";
            break;
        case ComputerCase::AT:                      os << "Formfactor: AT\n";
            break;
        case ComputerCase::BabyAT:                  os << "Formfactor: BabyAT\n";
            break;
        case ComputerCase::ATX:                     os << "Formfactor: ATX\n";
            break;
        case ComputerCase::SSI_CEB:                 os << "Formfactor: SSI_CEB\n";
            break;
        case ComputerCase::microATX:                os << "Formfactor: microATX\n";
            break;
        case ComputerCase::MiniATX:                 os << "Formfactor: MiniATX\n";
            break;
        case ComputerCase::FlexATX:                 os << "Formfactor: FlexATX\n";
            break;
        case ComputerCase::MiniITX:                 os << "Formfactor: MiniITX\n";
            break;
        case ComputerCase::NanoITX:                 os << "Formfactor: NanoITX\n";
            break;
        case ComputerCase::PicoITX:                 os << "Formfactor: PicoITX\n";
            break;
        case ComputerCase::MobileITX:               os << "Formfactor: MobileITX\n";
            break;
        case ComputerCase::NeoITX:                  os << "Formfactor: NeoITX\n";
            break;
        case ComputerCase::BTX:                     os << "Formfactor: BTX\n";
            break;
        case ComputerCase::MicroBTX:                os << "Formfactor: MicroBTX\n";
            break;
        case ComputerCase::PicoBTX:                 os << "Formfactor: PicoBTX\n";
            break;
        case ComputerCase::DTX:                     os << "Formfactor: DTX\n";
            break;
        case ComputerCase::MiniDTX:                 os << "Formfactor: MiniDTX\n";
            break;
        case ComputerCase::ETX:                     os << "Formfactor: ETX\n";
            break;
        case ComputerCase::CoreExpress:             os << "Formfactor: CoreExpress\n";
            break;
        case ComputerCase::Extended_ATX:            os << "Formfactor: Extended_ATX\n";
            break;
        case ComputerCase::Enhanced_Extended_ATX:   os << "Formfactor: Enhanced_Extended_ATX\n";
            break;
        case ComputerCase::LPX:                     os << "Formfactor: LPX\n";
            break;
        case ComputerCase::MiniLPX:                 os << "Formfactor: MiniLPX\n";
            break;
        case ComputerCase::PC_104:                  os << "Formfactor: PC_104\n";
            break;
        case ComputerCase::NLX:                     os << "Formfactor: NLX\n";
            break;
        case ComputerCase::UTX:                     os << "Formfactor: UTX\n";
            break;
        case ComputerCase::WTX:                     os << "Formfactor: WTX\n";
            break;
        case ComputerCase::SWTX:                    os << "Formfactor: SWTX\n";
            break;
        case ComputerCase::HPTX:                    os << "Formfactor: HPTX\n";
            break;
        case ComputerCase::XTX:                     os << "Formfactor: XTX\n";
            break;

        default:                                    os << "Formfactor: not defined!\n";
            break;
    }



    os      << "Metall: " << cc.metalThickness << "\n"
            << "5,25 Inch Bay: " << cc._525InchBay << "\n"
            << "3,5 Inch Bay: " << cc._35InchBay << "\n"
            << "3,5 Inch Bay inernal: " << cc._35InchBayIn << "\n"
            << "PCI slots: " << cc.PCISlots << "\n";
    if (cc.possibilityOfWaterCooling)
        os  << "WaterCooling: yes" << "\n";
    else
        os  << "WaterCooling: no" << "\n";
    if (cc.featurePSU)
        os  << "PSU: yes" << "\n";
    else
        os  << "PSU: no" << "\n";

    os      << "Depth: "  << cc.Depth  << "\n"
            << "Width: "  << cc.Width  << "\n"
            << "Height: " << cc.Height << std::endl;
    return os;
}

bool ComputerCase::isEmpty() const
{
    if (manufacturer == "" && model == "")
        return true;
    else return false;
}
