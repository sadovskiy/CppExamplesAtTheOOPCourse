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

#include "staff.hpp"

Staff::Staff(): id(new unsigned int(1)),
                fname("none"),
                lname("none"),
                age(new unsigned int(0)),
                education("none"),
                telephon(new unsigned int(0)),
                salary(new float(0))
{

}

Staff::Staff(    const std::string m_fname,
                const std::string m_lname,
                const unsigned int m_age,
                const std::string m_education,
                const unsigned int m_telephon,
                const float m_salary):     id(new unsigned int(1)),
                                        fname(m_fname),
                                        lname(m_lname),
                                        age(new unsigned int(m_age)),
                                        education(m_education),
                                        telephon(new unsigned int(m_telephon)),
                                        salary(new float(m_salary))
{

}

Staff::~Staff()
{

    delete id;
    delete age;
    delete telephon;
    delete salary;
}

Staff::Staff(const Staff& other):     id(new unsigned int(0)),
                                    fname(other.fname),
                                    lname(other.lname),
                                    age(new unsigned int(*other.age)),
                                    education(other.education),
                                    telephon(new unsigned int(*other.telephon)),
                                    salary(new float(*other.salary))
{

}

Staff& Staff::operator=(const Staff& rhs)
{
    if (this == &rhs) return *this;

    *id = *rhs.id;
    fname = rhs.fname;
    lname = rhs.lname;
    *age = *rhs.age;
    education = rhs.education;
    *telephon = *rhs.telephon;
    *salary = *rhs.salary;

    return *this;
}

void Staff::fnameSetting(const std::string m_fname)
{
    fname = m_fname;
}

void Staff::lnameSetting(const std::string m_lname)
{
    lname = m_lname;
}
void Staff::ageSetting(const unsigned int m_age)
{
    *age = m_age;
}

void Staff::educationSetting(const std::string m_education)
{
    education = m_education;
}

void Staff::telephonSetting(const unsigned int m_telephon)
{
    *telephon = m_telephon;
}

void Staff::salarySetting(const float m_salary)
{
    *salary = m_salary;
}

unsigned int Staff::idGetting() const
{
    return *id;
}

std::string Staff::fnameGetting() const
{
    return fname;
}

std::string Staff::lnameGetting() const
{
    return lname;
}

unsigned int Staff::ageGetting() const
{
    return *age;
}

std::string Staff::educationGetting() const
{
    return education;
}

unsigned int Staff::telephonGetting() const
{
    return *telephon;
}

float Staff::salaryGetting() const
{
    return *salary;
}

void Staff::display() const
{
    std::cout      << fnameGetting() << " "
                << lnameGetting() << " "
                << ageGetting() << " "
                << educationGetting() << " "
                << telephonGetting() << " "
                << salaryGetting() << std::endl;
}

