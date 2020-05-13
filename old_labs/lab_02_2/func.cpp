#include <cstdlib>
#include <fstream>
#include <string>
#include <limits>
#include <cstring>

#include "func.hpp"

using namespace std;

size_t readStr(TBase(& db)[NUM])
{
    // Количесвто строк
    size_t numStr = 0;
    // Строка прочитанная из файла и индекс элемента ";" в ней
    string strFromFile;
    string::size_type index = 0;
    // Создаём поток "inFile" на чтение
    // и ассоциируем его с файлом "tele.db"
    fstream inFile("tele.db", ios_base::in);

    // Делаем проверку, открыт ли файл
    if ( !inFile.is_open() ) {
        // Если файл не открыт, то выдаём пользователю
        // соответствующее сообщение и выходим из программы
        cerr << "Error: File not open!" << endl;
        exit(1);
    }

    // Сообщение пользователю
    cout << "Starting reading from the file." << endl; // "Начинаем читать из файла.\n"

    // Чтение из файла осуществляем построчно
    // через цикл, который остановится, когда будет
    // достигнут конец файла
    while (!inFile.eof()) {
        // Читаем построчно из потока "inFile" и пишем в строку "strFromFile"
        getline(inFile, strFromFile);

        // Осуществляем синтаксический разбор входных данных строки "strFromFile"

        // Определяем конец столбца в строке, отделяемого символом ";"
        index = strFromFile.find(';');
        // Выделяем из строки нужный нам столбец, переводим его из типа string
        // в тип int и копируем в поле "id" стуктуры "db"
        db[numStr].id = atoi(strFromFile.substr(0, index).c_str());
        // Удаляем извлечённый столбец и терминальный символ ";"
        strFromFile.erase(0, index + 1);

        // Далее действия повторяются для каждого из полей структуры "db"
        index = strFromFile.find(';');
        db[numStr].telephone = atoi(strFromFile.substr(0, index).c_str());
        strFromFile.erase(0, index + 1);
        index = strFromFile.find(';');
        db[numStr].name = strFromFile.substr(0, index);
        strFromFile.erase(0, index + 1);
        index = strFromFile.find(';');
        db[numStr].t_plan = strFromFile.substr(0, index);
        strFromFile.erase(0, index + 1);
        index = strFromFile.find('\n');
        db[numStr].adress = strFromFile.substr(0, index);
        strFromFile.erase(0, index + 1);

        // Используем "numStr" для подсчёта количества строк в файле
        numStr++;
    }

     // Выводим количество прочитанных строк
    cout << "Number of string: " << numStr << endl; // "Количество строк: "

    cout << "Finished reading from the file." << endl; // "Закончили читать из файла.\n"

    // Закрываем поток "inFile"
    inFile.close();

    // Возвращаем прочитанное количество строк
    return numStr;
}

void writeStr(const size_t n, const TBase* const db)
{
    // Создаём поток "outFile" на запись
    // и ассоциируем его с файлом "tele.db"
    fstream outFile("tele.db", ios_base::out);

    // Делаем проверку, открыт ли файл
    if ( !outFile.is_open() ) {
        // Если файл не открыт, то выдаём пользователю
        // соответствующее сообщение и выходим из программы
        cerr << "Error: File not open!" << endl;
        exit(1);
    }

    cout << "Starting writing to the file." << endl; // "Начинаем записывать в файл.\n"

    // Записываем в файл по строчно данные из структуры "db".
    // Каждая строка, при этом, оканчивается символом переноса
    // на следующую строку "\n"
    for (size_t i = 0; i < n - 1; i++)
        outFile << db[i].id << ";"
                << db[i].telephone << ";"
                << db[i].name << ";"
                << db[i].t_plan << ";"
                << db[i].adress << endl;
    // Записываем последнюю строчку без символа переноса курсора "\n".
    outFile << db[n - 1].id << ";"
            << db[n - 1].telephone << ";"
            << db[n - 1].name << ";"
            << db[n - 1].t_plan << ";"
            << db[n - 1].adress;

    cout << "Finished writing to the file." << endl; // "Закончили записывать в файл.\n"

    // Закрываем поток "outFile"
    outFile.close();
}

size_t readBin(TBase* db)
{
    // Создаём поток "inFile" на чтение
    // и ассоциируем его с файлом "tele_bin.db"
    fstream inFile("tele_bin.db", ios_base::in | ios_base::binary);

    // Делаем проверку, открыт ли файл
    if ( !inFile.is_open() ) {
        cerr << "Error: File not open!" << endl;
        exit(1);
    }

    cout << "Starting reading from the binary file." << endl; // "Начинаем читать из бинарного файла.\n"

    // Запись строк типа string в бинарном виде,
    // приводит к сильному усложнению программы,
    // с сомнительным выигрышем, по этому
    // для некоторого упрощения создадим отдельную структуру,
    // содержащую строки типа массив char.
    TBaseBin baseBin[NUM];

    // Читаем из двоичного файла во временный массив структур "baseBin"
    inFile.read((char *) &baseBin, sizeof baseBin);

    // Вычисляем, сколько строк имеется в двоичном файле
    // и сохраняем их в "numStr"
    size_t numStr = 0;
    for (size_t i = 0; i < NUM; i++)
        if ((baseBin[i].id == 0) && (i != 0)) {
            numStr = i;
            cout << "Number of string: " << numStr << endl; // "Количество строк: "
            break;
        }

    cout << "Finished reading from the binary file." << endl; // "Закончили читать из бинарного файла.\n"

    inFile.close();

    // Копируем из временного массива структур "baseBin"
    // в основной массив структур "db"
    // в количестве строк "numStr"
    for (size_t i = 0; i < numStr; i++) {
        db[i].id = baseBin[i].id;
        db[i].telephone = baseBin[i].telephone;
        db[i].name = baseBin[i].name;
        db[i].t_plan = baseBin[i].t_plan;
        db[i].adress = baseBin[i].adress;
    }

    return numStr;
}

void writeBin(const size_t n, const TBase* const db)
{
    // Создаём поток "outFile" на запись
    // и ассоциируем его с файлом "tele_bin.db"
    fstream outFile("tele_bin.db", ios_base::out | ios_base::binary);

    // Делаем проверку, открыт ли файл
    if ( !outFile.is_open() ) {
        cerr << "Error: File not open!" << endl;
        exit(1);
    }

    cout << "Starting writing to the binary file." << endl; // "Начинаем записывать в бинарный файл.\n"

    // Запись строк типа string в бинарном виде,
    // приводит к сильному усложнению программы,
    // с сомнительным выигрышем, по этому
    // для некоторого упрощения создадим отдельную структуру,
    // содержащую строки типа массив char.
    TBaseBin baseBin[NUM];

    // Копируем из основного массива структур "db"
    // в временный массив структур "baseBin"
    // для записи в двоичной форме
    for (size_t i = 0; i < n; i++) {
        baseBin[i].id = db[i].id;
        baseBin[i].telephone = db[i].telephone;
        strcpy(baseBin[i].name, db[i].name.c_str());
        strcpy(baseBin[i].t_plan, db[i].t_plan.c_str());
        strcpy(baseBin[i].adress, db[i].adress.c_str());
    }

    // Записываем в файл массив структур "baseBin"
    outFile.write((char *) &baseBin, sizeof (baseBin));

    cout << "Finished writing to the binary file." << endl; // "Закончили записывать в бинарный файл.\n"

    // Закрываем поток
    outFile.close();
}

void print(const size_t n, const TBase* const db)
{
    // Делаем проверку, не пуста ли наша база
    if (!n) {
        cout << "Database is empty!" << endl;
        return;
    }

    // Выводим прочитанную строку на экран
    for (size_t i = 0; i < n; i++)
        cout << db[i].id << " "
             << db[i].telephone << " "
             << db[i].name << " "
             << db[i].t_plan << " "
             << db[i].adress << endl;
}

void about()
{
    cout << "Made in ISTAC (MSUCE), author: Sadovskiy B. S.\n" << endl;
}

void pressAnyKey()
{
    // "\nНажмите любую клавишу для продолжения...\n"
    cout << "\nPress any key...\n" << endl;

    // Сброс специальных битов (badbit, eofbit, failbit) потока ввода ,
    // для предотвращения зацикливания при вводе некорректных символов
    std::cin.clear();
    // Если в потоке ввода остались символы, то мы их удаляем (игнорируем)
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // ставим задержку
    cin.get();

// в случае разных ОС, компилятор выберет подходящий
// способ очистки экрана
#ifdef __linux__
    system("clear");
#elif __windows__
    system("cls");
#endif
}
