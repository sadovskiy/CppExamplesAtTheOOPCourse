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

#include "director.hpp"
#include "driver.hpp"
#include "engineer.hpp"
#include "manager.hpp"
#include "secretary.hpp"

using namespace std;

int main()
{
    // Инициализируем объекты при их создании
    Director director("Иван", "Иванов", 50, "уч.степень", "Генеральный", 1234567, 120000);
    Driver driver("Сидоров", "Сидоров", 35, "среднее", "B", "O564HT", 4659832, 25000);
    Engineer engineer("Сергей", "Сергеев", 26, "высшее", "Информационный", "Программист", 4659832, 40000);
    Manager manager("Пётр", "Петров", 30, "высшее", "Информационный", 5, 4659832, 60000);
    Secretary secretary("Анна", "Ивановна", 21, "высшее", "Иванов Иван Иванович", 4659832, 20000);

    // Выводим содержимое объектов на экран
    director.display();
    driver.display();
    engineer.display();
    manager.display();
    secretary.display();

    return 0;
}
