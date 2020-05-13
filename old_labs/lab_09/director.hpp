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

#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "staff.hpp"

// Наследники получают часть данных и методов из базового класса
class Director: public Staff
{
        std::string type; // Директор, какого подразделения
    public:
        Director();
        Director(   const std::string m_fname,
                    const std::string m_lname,
                    const unsigned int m_age,
                    const std::string m_education,
                    const std::string m_type,
                    const unsigned int m_telephon,
                    const float m_salary);
        Director(const Director& other);
        virtual ~Director();
        Director& operator=(const Director& other);

        void typeSetting(const std::string m_type);

        std::string typeGetting() const;

        void display() const;
};

#endif // DIRECTOR_H
