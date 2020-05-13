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

#ifndef ENGINEER_H
#define ENGINEER_H

#include "staff.hpp"

// Наследники получают часть данных и методов из базового класса
class Engineer : public Staff
{
        std::string department; // В каком отделе работает
        std::string profession; // Специальность
    public:
        Engineer();
        Engineer(    const std::string m_fname,
                    const std::string m_lname,
                    const unsigned int m_age,
                    const std::string m_education,
                    const std::string m_department,
                    const std::string m_profession,
                    const unsigned int m_telephon,
                    const float m_salary);
        virtual ~Engineer();
        Engineer(const Engineer& other);
        Engineer& operator=(const Engineer& other);

        void departmentSetting(const std::string m_department);
        void professionSetting(const std::string m_profession);

        std::string departmentGetting() const;
        std::string professionGetting() const;

        void display() const;
};

#endif // ENGINEER_H
