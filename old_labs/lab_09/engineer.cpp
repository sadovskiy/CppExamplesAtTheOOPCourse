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

#include "engineer.hpp"


Engineer::Engineer(): Staff(), department("none"), profession("none")
{

}

Engineer::Engineer(    const std::string m_fname,
                    const std::string m_lname,
                    const unsigned int m_age,
                    const std::string m_education,
                    const std::string m_department,
                    const std::string m_profession,
                    const unsigned int m_telephon,
                    const float m_salary):     Staff(m_fname, m_lname, m_age, m_education, m_telephon, m_salary),
                                            department(m_department), profession(m_profession)
{

}

Engineer::~Engineer()
{

}

Engineer::Engineer(const Engineer& other): Staff(other), department(other.department), profession(other.profession)
{

}

Engineer& Engineer::operator=(const Engineer& rhs)
{
    if (this == &rhs) return *this;

    Staff::operator=(rhs);
    department = rhs.department;
    profession = rhs.profession;

    return *this;
}

void Engineer::departmentSetting(const std::string m_department)
{
    department = m_department;
}

void Engineer::professionSetting(const std::string m_profession)
{
    department = m_profession;
}

std::string Engineer::departmentGetting() const
{
    return department;
}

std::string Engineer::professionGetting() const
{
    return profession;
}

void Engineer::display() const
{
    std::cout      << fnameGetting() << " "
                << lnameGetting() << " "
                << ageGetting() << " "
                << educationGetting() << " "
                << departmentGetting() << " "
                << professionGetting() << " "
                << telephonGetting() << " "
                << salaryGetting() << std::endl;
}
