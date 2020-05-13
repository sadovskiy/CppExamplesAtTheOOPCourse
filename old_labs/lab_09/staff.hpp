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

#ifndef STAFF_H
#define STAFF_H

#include <iostream>
#include <string>

// Базовый класс используется для агрегирования
// общих данных и методов
class Staff
{
        unsigned int *id;
        std::string fname;
        std::string lname;
        unsigned int *age;
        std::string education;
        unsigned int *telephon;
        float *salary;
    public:
        Staff();
        Staff(    const std::string m_fname,
                const std::string m_lname,
                const unsigned int m_age,
                const std::string m_education,
                const unsigned int m_telephon,
                const float m_salary);
        Staff(const Staff& other);
        virtual ~Staff();
        Staff& operator=(const Staff& other);

        void fnameSetting(const std::string m_fname);
        void lnameSetting(const std::string m_lname);
        void ageSetting(const unsigned int m_age);
        void educationSetting(const std::string m_education);
        void telephonSetting(const unsigned int m_telephon);
        void salarySetting(const float m_salary);

        unsigned int idGetting() const;
        std::string fnameGetting() const;
        std::string lnameGetting() const;
        unsigned int ageGetting() const;
        std::string educationGetting() const;
        unsigned int telephonGetting() const;
        float salaryGetting() const;

        void display() const;
};

#endif // STAFF_H
