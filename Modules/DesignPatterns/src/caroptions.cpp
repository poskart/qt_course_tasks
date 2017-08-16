#include "headers/caroptions.h"

CarOptions::CarOptions(QObject *parent) : QObject(parent)
{
        colors.append("Blue");
        colors.append("Red");
        colors.append("Black");
        colors.append("White");
        colors.append("Green");
        colors.append("Yellow");
        colors.append("Magenta");
        colors.append("Cyan");
        colors.append("Gray");
        colors.append("Silver");
        colors.append("Gold");

        carBrands.append("Alfa Romeo");
        carBrands.append("Ferrari");
        carBrands.append("Honda");
        carBrands.append("Jaguar");
        carBrands.append("Mercedes");
        carBrands.append("Toyota");
        carBrands.append("Volkswagen");

        truckBrands.append("Jelcz");
        truckBrands.append("Man");
        truckBrands.append("Scania");
        truckBrands.append("Renault");
        truckBrands.append("Volvo");

        carModels.append("Economic");
        carModels.append("Medium-class");
        carModels.append("High quality");
        carModels.append("Exclusive");

        engineTypes.append("Petrol");
        engineTypes.append("Diesel");
        engineTypes.append("Gas");

        enginePowersCars.append("90");
        enginePowersCars.append("120");
        enginePowersCars.append("180");
        enginePowersCars.append("240");

        enginePowersTrucks.append("180");
        enginePowersTrucks.append("280");
        enginePowersTrucks.append("360");
        enginePowersTrucks.append("480");

        optionalEquipmentList.append("SuperNew ABS");
        optionalEquipmentList.append("ESP");
        optionalEquipmentList.append("ASR");
        optionalEquipmentList.append("BLIS");
        optionalEquipmentList.append("Antifog lights");
        optionalEquipmentList.append("Navigation");
        optionalEquipmentList.append("Leather seats");
        optionalEquipmentList.append("Heated seats");
        optionalEquipmentList.append("Multi-zone climate control");
        optionalEquipmentList.append("Alloy wheels");
}

const QStringList CarOptions::getEngineTypes(void)
{
    return engineTypes;
}

const QStringList CarOptions::getEnginePowersCars(void)
{
    return enginePowersCars;
}

const QStringList CarOptions::getEnginePowersTrucks(void)
{
    return enginePowersTrucks;
}

const QStringList CarOptions::getCarColors(void)
{
    return colors;
}

const QStringList CarOptions::getCarBrands(void)
{
    return carBrands;
}

const QStringList CarOptions::getTruckBrands(void)
{
    return truckBrands;
}

const QStringList CarOptions::getCarModels(void)
{
    return carModels;
}

const QStringList CarOptions::getEquipment(void)
{
    return optionalEquipmentList;
}

int CarOptions::getEquipmentCount(void) const
{
    return optionalEquipmentList.size();
}

const QString CarOptions::getEquipment(int index)
{
    return optionalEquipmentList.at(index);
}

int CarOptions::getLongestEqNameWidth() const
{
    int lettersCount = 0;
    foreach (QString eq, optionalEquipmentList) {
        if(eq.length() > lettersCount)
            lettersCount = eq.length();
    }
    return lettersCount;
}
