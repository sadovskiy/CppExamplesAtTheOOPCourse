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

#ifndef SECRETARY_H
#define SECRETARY_H

#include "staff.hpp"

// Наследники получают часть данных и методов из базового класса
class Secretary : public Staff
{
        std::string director; // к кому закреплён

    public:
        Secretary();
        Secretary(    const std::string m_fname,
                    const std::string m_lname,
                    const unsigned int m_age,
                    const std::string m_education,
                    const std::string m_director,
                    const unsigned int m_telephon,
                    const float m_salary);
        virtual ~Secretary();
        Secretary(const Secretary& other);
        Secretary& operator=(const Secretary& other);

        void directorSetting(const std::string m_director);

        std::string directorGetting() const;

        void display() const;
};

#endif // SECRETARY_H
