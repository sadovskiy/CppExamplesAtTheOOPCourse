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

#ifndef A_H
#define A_H

#include <iostream>

// Создаём класс, так как это делали в предыдущих работах
class A
{
        std::string str;
        int num;
        bool bnum;
    public:
        A();
        A(const std::string val1, const int val2, const bool val3);
        A(const A& other);
        ~A();

        A& operator=(const A& other);

        // Ввиду того, что методы состоят из одного оператора,
        // сделаем их встроенными (inline)
        std::string getStr() const { return str; }
        void setStr(const std::string val) { str = val; }
        int getNum() const { return num; }
        void setNum(const int val) { num = val; }
        bool getbNum() const { return bnum; }
        void setbNum(const bool val) { bnum = val; }

        void tbNum() {bnum = true;}
        void pbNum() {bnum = false;}

        void display() const;

        // Метод проверки "пуст ли объект"
        bool isEmpty() const;
};

#endif // A_H
