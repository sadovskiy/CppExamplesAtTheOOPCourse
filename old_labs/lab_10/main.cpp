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

#include "b.hpp"

using namespace std;

// Делаем проверку методов класса "B"
int main()
{
    // Создадим пустой объект "b"
    B b;

    // Проверим, действительно ли он пуст
    if (b.isEmpty())
        cout << "List is full!" << endl; // "Список заполнен!"
    else
        // cout << "В списке уже есть элементы!" << endl;
        cout << "The list already contains elements!" << endl;

    // Заполним его
    // cout << "Начинаем заполнять список." << endl;
    cout << "Starting fill in list." << endl;
    b.add("test 1", true);
    b.add("test 2", true);
    b.add("test 3", true);
    b.add("test 4", true);
    b.add("test 5", false);
    b.add("test 6", false);
    b.add("test 7", false);
    b.add("test 8", false);
    b.add("test 9", false);
    b.add("test 10", false);
    // cout << "Закончили заполнять список." << endl;
    cout << "Finished fill in list." << endl;

    // Проверим, осталось ли ещё место
    if (b.isEmpty())
        cout << "List is full!" << endl; // "Список заполнен!"
    else
        // cout << "В списке ещё есть не заполненные места!" << endl;
        cout << "In the list there are still vacant places!" << endl;

    // Проверим работу метода поиска
    cout << "----------------------------" << endl;
    A& test = b.find(3);

    // Выводим найденый элемент на экран
    if (test.isEmpty()) {
        cout << "element is found!" << endl; // "Найден элемент!"
        test.display();
    }

    // Проверим метод для установки значения false
    cout << "----------------------------" << endl;
    cout << "Invert the item number 3, the bnum." << endl;
    b.pdata(3);

    // Выведем на экран элемент списка,
    // в котором было установлено значение false
    test.display();

    // Выведем весь список объекта "b" на экран
    cout << "----------------------------" << endl;
    b.displayALL();

    // Создадим пустой объект "b2",
    cout << "----------------------------" << endl;
    B b2;
    // и скопируем в него данные из ранее заполненного объекта "b"
    b2 = b;

    // Удалим элемент под номером 7 из списка (массива)
    b2.del(7);

    // Выведем всё содержимое объекта "b2"
    cout << "----------------------------" << endl;
    b2.displayALL();

    return 0;
}
