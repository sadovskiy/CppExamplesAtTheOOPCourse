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

#include "director.hpp"

Director::Director(): Staff(), type("none")
{

}

Director::Director(    const std::string m_fname,
                    const std::string m_lname,
                    const unsigned int m_age,
                    const std::string m_education,
                    const std::string m_type,
                    const unsigned int m_telephon,
                    const float m_salary):     Staff(m_fname, m_lname, m_age, m_education, m_telephon, m_salary),
                                            type(m_type)
{

}

Director::~Director()
{

}

Director::Director(const Director& other): Staff(other), type(other.type)
{

}

// По аналогии с предыдущими работами
Director& Director::operator=(const Director& rhs)
{
    if (this == &rhs) return *this;

    Staff::operator=(rhs);
    type = rhs.type;

    return *this;
}

void Director::typeSetting(const std::string m_type)
{
    type = m_type;
}

std::string Director::typeGetting() const
{
    return type;
}

void Director::display() const
{
    std::cout   << typeGetting() << " "
                << "Директор" << " "
                << fnameGetting() << " "
                << lnameGetting() << " "
                << ageGetting() << " "
                << educationGetting() << " "
                << telephonGetting() << " "
                << salaryGetting() << std::endl;
}
