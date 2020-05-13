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

// Подключаем для работы с файлами в Си++
#include <fstream>
// Подключаем для пользования функцией exit()
#include <cstdlib>

#include "func.hpp"

// Для пользования объектами cout/cin и другими
// стандартными средствами Си++ надо распространить
// стандартное (std) пространство имён на данный файл
using namespace std;

void readFile(string& text)
{
    // Создаём поток "inFile" на чтение
    // и ассоциируем его с файлом "db.txt"
    ifstream inFile("db.txt", ios_base::in);

    // Делаем проверку, открыт ли файл
    if (!inFile.is_open()) {
        // Если файл не открыт, то выдаём пользователю
        // соответствующее сообщение и выходим из программы
        cerr << "Error: File not open!" << endl;
        exit(1);
    }


    // Очистим строку "text" для того, что бы убедиться,
    // что запись была прочитана из файла правильно
    text = "";

    // Сообщение пользователю
    cout << "Starting reading from the file." << endl; // "Начинаем читать из файла.\n"

    // Чтение из файла осуществляем построчно
    // через цикл, который остановится, когда будет
    // достигнут конец файла
    while (!inFile.eof())
        // Читаем построчно из "inFile" и пишем в строку "text"
        getline(inFile, text);

    // Выводим прочитанный текст
    cout << "Loaded from file: " << text << endl; // "Загружено из файла: %s\n"

    cout << "Finished reading from the file." << endl; // "Закончили читать из файла.\n"

    // Закрываем поток "inFile"
    inFile.close();
}

void writeFile(const string& text)
{
    // Создаём поток "outFile" на запись,
    // и ассоциируем его с файлом "db.txt"
    ofstream outFile("db.txt", ios_base::out);

    cout << "Starting writing to the file." << endl; // "Начинаем записывать в файл.\n"

    if (!outFile.is_open()) {
        cerr << "Error: File not open!" << endl;
        exit(1);
    }

    // Пишем в файл из переменной "text"
    outFile << text;

    cout << "Finished writing to the file." << endl; // "Закончили записывать в файл.\n"

    // Закрываем поток "inFile"
    outFile.close();
}
