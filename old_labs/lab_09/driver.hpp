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

#ifndef DRIVER_H
#define DRIVER_H

#include "staff.hpp"

// Наследники получают часть данных и методов из базового класса
class Driver : public Staff
{
        std::string category; // Категория прав
        std::string car; // К какой машине закреплён
    public:
        Driver();
        Driver(    const std::string m_fname,
                    const std::string m_lname,
                    const unsigned int m_age,
                    const std::string m_education,
                    const std::string m_category,
                    const std::string m_car,
                    const unsigned int m_telephon,
                    const float m_salary);
        Driver(const Driver& other);
        virtual ~Driver();
        Driver& operator=(const Driver& other);

        void categorySetting(const std::string m_category);
        void carSetting(const std::string m_car);

        std::string categoryGetting() const;
        std::string carGetting() const;

        void display() const;
};

#endif // DRIVER_H
