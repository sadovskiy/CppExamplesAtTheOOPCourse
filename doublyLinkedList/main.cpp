/*
 * Copyright (C) 2020. GPL
 *
 * Written by Sadovskiy B. S.
 *
 * Права на программу (С) 2020. GPL
 *
 * Написана Садовским Б. С.
 *
 * Демонстрация взаимодействия объекта, связанного списка и меню программы
 *
 */


#include <iostream>

using namespace std;

class A
{
    int m_n;
public:
    A(){}
    explicit A(const int n): m_n(n){}
    ~A(){}

    int get_n() const {return m_n;}
    void set_n(const int n) {m_n = n;}
};

class A_unit: public A
{
    A_unit* n;
    A_unit* p;

public:
    A_unit(): n(0), p(0) {}
    ~A_unit(){}

    A_unit* next() const {return n;}
    A_unit* prior() const {return p;}

    void next(A_unit* const l_n) {n = l_n;}
    void prior(A_unit* const l_p) {p = l_p;}
};

class list_A
{
    A_unit obj;
    A_unit* first;
    A_unit* last;

public:
    list_A(): first(0), last(0) {}
    ~list_A(){}

    void add(const int number);
    void del();
    void del(const int n);
    void edit(const int num_old, const int new_num);
    A_unit* find_l(const int key) const;
    void print() const {}
    void printAll() const;
    bool is_full() const;
    bool is_empty_l() const;
};

void list_A::add(const int number)
{
    A_unit* new_element = new A_unit;
    new_element->set_n(number);
    if (!first)
        first = new_element;
    else {
        new_element->prior(last);
        last->next(new_element);
    }

    last = new_element;
}

void list_A::del()
{
    A_unit* deleting_element = last;
    if (last)
        deleting_element->prior()->next(0);
    last = deleting_element->prior();
    delete deleting_element;
}

void list_A::del(const int n)
{
    A_unit* deleting_element = find_l(n);

    if (deleting_element) {
        if (first == last) {
            delete first;
            first = last = 0;
            return;
        }
        if (deleting_element == first) {
            deleting_element->next()->prior(0);
            first = deleting_element->next();
        }
        if (deleting_element == last) {
            deleting_element->prior()->next(0);
            last = deleting_element->prior();
        }
        if ((deleting_element->next() != 0) &&
                (deleting_element->prior() != 0)) {
            deleting_element->next()->prior(deleting_element->prior());
            deleting_element->prior()->next(deleting_element->next());
        }
        delete deleting_element;
    }
}

void list_A::edit(const int num_old, const int new_num)
{
    A_unit* num = find_l(num_old);
    if (num)
        num->set_n(new_num);
    else
        cout << "Элемент не найден!" << endl;
}

A_unit* list_A::find_l(const int key) const
{
    for (A_unit* current = first;
         current;
         current = current->next())
        if (current->get_n() == key)
            return current;
    return 0;
}

void list_A::printAll() const
{
    for (A_unit* current = first;
         current;
         current = current->next())
        cout << current->get_n() << endl;
}

bool list_A::is_full() const
{
    A_unit* temp = new A_unit;
    if (temp)
    {
        delete temp;
        return 0;
    }
    else
        return 1;
}

bool list_A::is_empty_l() const
{
    if(!first)
        return true;
    else
        return false;
}

class Menu
{
    list_A list;
public:
    Menu();
    ~Menu() {}

    void printMenu() const;
    int exec();
};

Menu::Menu()
{
    printMenu();
}

void Menu::printMenu() const
{
    cout << "1) Добавить элемент в список."    << "\n"
         << "2) Удалить элемент из списка."    << "\n"
         << "3) Редактировать элемент."        << "\n"
         << "4) Найти элемент."                << "\n"
         << "5) Вывести на экран весь список." << "\n"
         << "6) Выход."                        << endl;

}

int Menu::exec()
{
    while (true)
    {
        int ch = 0;
        A_unit* finded = 0;
        cin >> ch;
        int num = 0, num_new = 0;
        switch (ch)
        {
        case 1:
            system("cls");

            cout << "Задайте число для сохранения в список: " << endl;
            cin >> num;
            list.add(num);
            break;
        case 2:
            system("cls");

            list.printAll();
            cout << "Задайте число для удаления из списка: " << endl;
            cin >> num;
            list.del(num);
            break;
        case 3:
            system("cls");

            cout << "Задайте значение для правки из списка: " << endl;
            cin >> num;
            cout << "Задайте новое значение: " << endl;
            cin >> num_new;
            list.edit(num, num_new);
            break;
        case 4:
            system("cls");

            cout << "Задайте число для поиска в списке: " << endl;
            cin >> num;
            finded = list.find_l(num);
            if (finded)
                cout << finded->get_n() << endl;
            else
                cout << "Элемент с таким значением не найден!" << endl;
            break;
        case 5:
            system("cls");
            list.printAll();
            break;
        case 6: return 0;
            break;
        default:
            cout << "Нет такого варианта!" << endl;
        }
        printMenu();
    }
}

int main()
{
    Menu menu;

    return menu.exec();
}
