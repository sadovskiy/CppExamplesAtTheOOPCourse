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

#ifndef MANAGER_H
#define MANAGER_H

#include "staff.hpp"

// Наследники получают часть данных и методов из базового класса
class Manager : public Staff
{
        std::string department; // Отдел, которым управляет менеджер
        unsigned int *numstaff; // Количество служащих в подчинении
    public:
        Manager();
        Manager(    const std::string m_fname,
                    const std::string m_lname,
                    const unsigned int m_age,
                    const std::string m_education,
                    const std::string m_department,
                    const unsigned int m_numstaff,
                    const unsigned int m_telephon,
                    const float m_salary);
        Manager(const Manager& other);
        virtual ~Manager();
        Manager& operator=(const Manager& other);

        void departmentSetting(const std::string m_department);
        void numstaffSetting(const unsigned int m_numstaff);

        std::string departmentGetting() const;
        unsigned int numstaffGetting() const;

        void display() const;
};

#endif // MANAGER_H
