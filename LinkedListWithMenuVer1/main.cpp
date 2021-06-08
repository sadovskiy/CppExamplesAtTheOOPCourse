/*
 * Copyright (C) 2020. GPL
 *
 * Written by Sadovskiy B. S.
 *
 * Права на программу (С) 2020. GPL
 *
 * Написана Садовским Б. С.
 *
 * Пример взаимодействия объекта TObjectListItem,
 * связанного списка TObjectList и меню программы TMenu,
 * через агрегирование.
 * В качестве базового используется объект TObject,
 * от которого наследуется TObjectListItem
 *
 */

#include <iostream>
#include <limits>
#include <sstream>
#include <cstdlib>

using namespace std;

class TObject
{
    int m_value;
public:
    TObject(): m_value(0) {}
    explicit TObject(const int n): m_value(n) {}
    TObject(const TObject &other): m_value(other.m_value) {}

    ~TObject() {}

    TObject &operator=(const TObject&other);

    int get_n() const {return m_value;}
    void set_n(const int n) {m_value = n;}

    void display() const {cout << "n: " << m_value << endl;}
    friend ostream &operator<<(ostream &os, const TObject &a)
    {os << "n: " << a.m_value << endl; return os;}
};


TObject &TObject::operator=(const TObject &other)
{
    if (this == &other) return *this;
    m_value = other.m_value;
    return *this;
}


class TObjectListItem: public TObject
{
    TObjectListItem *m_next;
    TObjectListItem *m_prior;

public:
    TObjectListItem(): m_next(nullptr), m_prior(nullptr) {}
    ~TObjectListItem() {}
    TObjectListItem(const TObjectListItem &other):
        TObject(other), m_next(nullptr), m_prior(nullptr) {}

    void next(TObjectListItem* const l_next) {m_next = l_next;}
    void prior(TObjectListItem* const l_prior) {m_prior = l_prior;}

    TObjectListItem *next() const {return m_next;}
    TObjectListItem *prior() const {return m_prior;}
    TObjectListItem *current() {return this;}
};

class TObjectList
{
    TObjectListItem *m_first;
    TObjectListItem *m_last;
    int m_count;

public:
    TObjectList(): m_first(nullptr), m_last(nullptr), m_count(0) {}
    TObjectList(const TObjectList &other);
    ~TObjectList();

    TObjectList &operator=(const TObjectList &other);

    void add(const int value);
    void delFirst();
    bool del(const int key);
    void delLast();
    void edit(TObjectListItem * const Item, const int new_num);
    TObjectListItem* find_l(const int key) const;
    void print() const {}
    void printAll(const bool WithPause = true) const;
    bool isFull() const;
    bool isEmpty() const;
    int count() const;
};

TObjectList::TObjectList(const TObjectList &other):
    m_first(nullptr)
  , m_last(nullptr)
  , m_count(0)
{
    TObjectListItem *current = other.m_first;
    while (current != nullptr) {
        add(current->get_n());
        current = current->next();
    }
}

TObjectList::~TObjectList()
{
    while (m_last != nullptr) {
        delLast();
    }
}

TObjectList &TObjectList::operator=(const TObjectList &other)
{
    if (this == &other) return *this;

    m_count = 0;

    TObjectListItem *current = other.m_first;
    while (current != nullptr) {
        add(current->get_n());
        current = current->next();
    }

    return *this;
}

void TObjectList::add(const int value)
{
    TObjectListItem *new_element = new TObjectListItem;
    new_element->set_n(value);
    if (!m_first)
        m_first = new_element;
    else {
        new_element->prior(m_last);
        m_last->next(new_element);
    }

    m_last = new_element;
    m_count++;
}

void TObjectList::delFirst()
{
    if (m_first == nullptr)
        return;
    TObjectListItem *deleting_element = m_first;

    if (deleting_element->next() != nullptr) {
        deleting_element->next()->prior(nullptr);
        m_first = deleting_element->next();
    }
    else
        m_first = m_last = nullptr;

    delete deleting_element;
    m_count--;
}

bool TObjectList::del(const int key)

{
    TObjectListItem* deleting_element = find_l(key);

    if (deleting_element != nullptr) {
        if (m_first == m_last) {
            delete m_first;
            m_first = m_last = nullptr;
            return true;
        }
        if (deleting_element == m_first) {
            deleting_element->next()->prior(nullptr);
            m_first = deleting_element->next();
        }
        if (deleting_element == m_last) {
            deleting_element->prior()->next(nullptr);
            m_last = deleting_element->prior();
        }
        if ((deleting_element->next() != nullptr) &&
                (deleting_element->prior() != nullptr)) {
            deleting_element->next()->prior(deleting_element->prior());
            deleting_element->prior()->next(deleting_element->next());
        }
        delete deleting_element;
        m_count--;
        return true;
    }
    return false;
}

void TObjectList::delLast()
{
    if (m_last == nullptr)
        return;
    TObjectListItem* deleting_element = m_last;

    if (deleting_element->prior() != nullptr) {
        deleting_element->prior()->next(nullptr);
        m_last = deleting_element->prior();
    }
    else
        m_first = m_last = nullptr;

    delete deleting_element;
    m_count--;
}

void TObjectList::edit(TObjectListItem * const Item, const int new_num)
{
    if (Item != nullptr)
        Item->set_n(new_num);
}

TObjectListItem* TObjectList::find_l(const int key) const
{
    for (TObjectListItem *current = m_first;
         current;
         current = current->next())
        if (current->get_n() == key)
            return current;

    return nullptr;
}

void TObjectList::printAll(const bool WithPause) const
{
#ifdef __WINNT__
    system("cls");
#elif __linux__
    system("clear");
#endif
    // В списке имеются следующие значения
    cout << "The list contains the following values:" << endl;
    for (TObjectListItem* current = m_first;
         current;
         current = current->next())
        cout << current->get_n() << endl;
    if (WithPause)
        cin.get();
}

bool TObjectList::isFull() const
{
    TObjectListItem *temp = new TObjectListItem;
    if (temp == nullptr)
        return true;
    else {
        delete temp;
        return false;
    }
}

bool TObjectList::isEmpty() const
{
    if(m_first == nullptr)
        return true;
    else
        return false;
}

int TObjectList::count() const
{
    return m_count;
}

class TMenu
{
    TObjectList list;
public:
    TMenu();
    ~TMenu() {}

    void printMenu() const;
    int exec();
};

TMenu::TMenu()
{
    printMenu();
}

void TMenu::printMenu() const
{
    // Количество элементов в списке равно
    cout << "The number of items in the list is " << list.count() << "\n"

         << "1) Add item to list."             << "\n"  // Добавить элемент в список
         << "2) Remove an item from the list." << "\n"  // Удалить элемент из списка
         << "3) Remove first item."            << "\n"  // Удалить первый элемент
         << "4) Remove last item."             << "\n"  // Удалить последний элемент
         << "5) Edit item."                    << "\n"  // Редактировать элемент
         << "6) Find item."                    << "\n"  // Найти элемент
         << "7) Display the entire list."      << "\n"  // Вывести на экран весь список
         << "8) Exit."                         << endl; // Выход

}

int TMenu::exec()
{
    while (true)
    {
        int ch = 0;
        TObjectListItem *finded = nullptr;
        cin >> ch;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        int num = 0, num_new = 0;
        bool isDeleted = false;
#ifdef __WINNT__
        system("cls");
#elif __linux__
        system("clear");
#endif
        switch (ch)
        {
        case 1:
            // Задайте число для сохранения в список
            cout << "Set the number to save to the list: " << endl;
            cin >> num;
            list.add(num);
            break;
        case 2:
            if (list.isEmpty()) {
                // Список пуст
                cout << "The list is empty!" << endl;
                cin.get();
                break;
            }
            list.printAll(false);
            // Укажите число для удаления из списка
            cout << "Specify the number to remove from the list: ";
            cin >> num;
            isDeleted = list.del(num);
            if (isDeleted)
                // Значение num удалено
                cout << "Value " << num << " removed!" << endl;
            else
                // // Элемент num не найден
                cout << "Item " << num << " not found!" << endl;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            break;
        case 3:
            list.delFirst();
            if (!list.isEmpty())
                list.printAll();
            else {
                // Список пуст
                cout << "The list is empty!" << endl;
                cin.get();
            }
            break;
        case 4:
            list.delLast();
            if (!list.isEmpty())
                list.printAll();
            else {
                // Список пуст
                cout << "The list is empty!" << endl;
                cin.get();
            }
            break;
        case 5:
            if (list.isEmpty()) {
                // Список пуст
                cout << "The list is empty!" << endl;
                cin.get();
                break;
            }
            // Укажите значение для правки из списка
            cout << "Set the value to edit from the list: ";
            cin >> num;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            finded = list.find_l(num);
            if (finded == nullptr) {
                // Элемент с таким значением не найден
                cout << "No item with this value was found!" << endl;
                cin.get();
                break;
            }
            // Элемент со значением finded->get_n() найден.
            cout << "An item with a value of " << finded->get_n()
                 << " was found." << endl;

            // Задайте новое значение
            cout << "Set new value: ";
            cin >> num_new;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            list.edit(finded, num_new);
            // Значение num заменино на num_new
            cout << "The value "       << num
                 << " is replaced by " << num_new << endl;
            cin.get();
            break;
        case 6:
            if (list.isEmpty()) {
                // Список пуст
                cout << "The list is empty!" << endl;
                cin.get();
                break;
            }
            // Задайте число для поиска в списке
            cout << "Specify the number to search in the list: " << endl;
            cin >> num;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            finded = list.find_l(num);
            if (finded != nullptr)
                // Элемент со значением finded->get_n() найден.
                cout << "An item with a value of " << finded->get_n()
                     << " was found." << endl;
            else
                // Элемент с таким значением не найден
                cout << "No item with this value was found!" << endl;
            cin.get();
            break;
        case 7:
            if (list.isEmpty()) {
                // Список пуст
                cout << "The list is empty!" << endl;
                cin.get();
                break;
            }
            list.printAll();
            break;
        case 8: return EXIT_SUCCESS;
            break;
        default:
            // Нет такого пункта в меню
            cout << "There is no such item in the menu!" << endl;
        }
#ifdef __WINNT__
        system("cls");
#elif __linux__
        system("clear");
#endif
        printMenu();
    }
}

int main()
{
    TMenu menu;

    return menu.exec();
}
