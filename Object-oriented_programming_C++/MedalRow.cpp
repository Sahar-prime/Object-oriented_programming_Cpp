#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "MedalRow.h"

MedalRow::MedalRow(const char* country, const int* medals)
{
    if (country != nullptr) 
    {
        std::strncpy(this->country, country, 3);
    }
    else
    {
        std::strncpy(this->country, "NON", 3); // Если country == nullptr, устанавливаем "NON"
    }

    this->country[3] = '\0';

    if (medals != nullptr)
    {
        for (int i = 0; i < 3; ++i)
        {
            this->medals[i] = medals[i];
        }
    }
    else
    {
        for (int i = 0; i < 3; ++i) // Если medals == nullptr, устанавливаем все медали в 0
        {
            this->medals[i] = 0;
        }
    }
}

MedalRow& MedalRow::setCountry(const char* country)
{
    if (country != nullptr)
        std::strncpy(this->country, country, 3);
    else
        std::strncpy(this->country, "NON", 3);

    this->country[3] = '\0';
    return *this;
}
const char* MedalRow::getCountry() const
{
    return country;
}

void MedalRow::print() const
{
    std::cout << "Country: " << country << " - ";
    std::cout << "Gold: " << medals[gold] << ", ";
    std::cout << "Silver: " << medals[silver] << ", ";
    std::cout << "Bronze: " << medals[bronze] << std::endl;
}
