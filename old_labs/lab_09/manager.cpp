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

#include "manager.hpp"

Manager::Manager(): Staff(), department("none"), numstaff(new unsigned int(0))
{

}

Manager::Manager(    const std::string m_fname,
                    const std::string m_lname,
                    const unsigned int m_age,
                    const std::string m_education,
                    const std::string m_department,
                    const unsigned int m_numstaff,
                    const unsigned int m_telephon,
                    const float m_salary):     Staff(m_fname, m_lname, m_age, m_education, m_telephon, m_salary),
                                            department(m_department), numstaff(new unsigned int(m_numstaff))
{

}

// Так как в конструкторе и других функциях-членах выделяется память,
// то в деструкторе мы её освобождаем
Manager::~Manager()
{

    delete numstaff;
}

Manager::Manager(const Manager& other): Staff(other),
                                        department(other.department),
                                        numstaff(new unsigned int(*other.numstaff))
{

}

// По аналогии с предыдущими работами
Manager& Manager::operator=(const Manager& rhs)
{
    if (this == &rhs) return *this;

    Staff::operator=(rhs);
    department = rhs.department;
    *numstaff = *rhs.numstaff;

    return *this;
}

void Manager::departmentSetting(const std::string m_department)
{
    department = m_department;
}

void Manager::numstaffSetting(const unsigned int m_numstaff)
{
    *numstaff = m_numstaff;
}

std::string Manager::departmentGetting() const
{
    return department;
}

unsigned int Manager::numstaffGetting() const
{
    return *numstaff;
}

void Manager::display() const
{
    std::cout      << fnameGetting() << " "
                << lnameGetting() << " "
                << ageGetting() << " "
                << educationGetting() << " "
                << departmentGetting() << " "
                << numstaffGetting() << " "
                << telephonGetting() << " "
                << salaryGetting() << std::endl;
}
