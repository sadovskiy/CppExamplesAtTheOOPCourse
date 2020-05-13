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

#include "driver.hpp"

Driver::Driver(): Staff(), category("none"), car("none")
{

}

Driver::Driver(    const std::string m_fname,
                    const std::string m_lname,
                    const unsigned int m_age,
                    const std::string m_education,
                    const std::string m_category,
                    const std::string m_car,
                    const unsigned int m_telephon,
                    const float m_salary):     Staff(m_fname, m_lname, m_age, m_education, m_telephon, m_salary),
                                            category(m_category), car(m_car)
{

}

Driver::~Driver()
{

}

Driver::Driver(const Driver& other): Staff(other), category(other.category), car(other.car)
{

}

Driver& Driver::operator=(const Driver& rhs)
{
    if (this == &rhs) return *this;

    Staff::operator=(rhs);
    category = rhs.category;
    car = rhs.car;

    return *this;
}

void Driver::categorySetting(const std::string m_category)
{
    category = m_category;
}

void Driver::carSetting(const std::string m_car)
{
    car = m_car;
}

std::string Driver::categoryGetting() const
{
    return category;
}

std::string Driver::carGetting() const
{
    return car;
}

void Driver::display() const
{
    std::cout      << fnameGetting() << " "
                << lnameGetting() << " "
                << ageGetting() << " "
                << educationGetting() << " "
                << categoryGetting() << " "
                << carGetting() << " "
                << telephonGetting() << " "
                << salaryGetting() << std::endl;
}
