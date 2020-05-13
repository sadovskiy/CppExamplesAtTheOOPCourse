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

#include "secretary.hpp"

Secretary::Secretary(): Staff(), director("none")
{

}

Secretary::Secretary(    const std::string m_fname,
                        const std::string m_lname,
                        const unsigned int m_age,
                        const std::string m_education,
                        const std::string m_director,
                        const unsigned int m_telephon,
                        const float m_salary):     Staff(    m_fname,
                                                        m_lname,
                                                        m_age,
                                                        m_education,
                                                        m_telephon,
                                                        m_salary),
                                                director(m_director)
{

}

Secretary::~Secretary()
{

}

Secretary::Secretary(const Secretary& other): Staff(other), director(other.director)
{

}

Secretary& Secretary::operator=(const Secretary& rhs)
{
    if (this == &rhs) return *this;

    Staff::operator=(rhs);
    director = rhs.director;

    return *this;
}

void Secretary::directorSetting(const std::string m_director)
{
    director = m_director;
}

std::string Secretary::directorGetting() const
{
    return director;
}

void Secretary::display() const
{
    std::cout      << fnameGetting() << " "
                << lnameGetting() << " "
                << ageGetting() << " "
                << educationGetting() << " "
                << directorGetting() << " "
                << telephonGetting() << " "
                << salaryGetting() << std::endl;
}
