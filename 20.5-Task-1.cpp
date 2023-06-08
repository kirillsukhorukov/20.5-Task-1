#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Функция ввода и проверки строки с целым числом
string int_input()
{
    string str;
    bool error = false;
    do
    {
        cout << "Enter payout amount: ";
        getline(cin, str);

        //Проверка длины строки с числом
        if (str.length() > 9)
        {
            cerr << "Error! Repeat input." << endl;
            error = true;
        }
        else error = false;

        //Проверка что все символы - числа
        for (int i = 0; i < str.length(); i++)
        {
            if (!isdigit(str[i]))
            {
                cerr << "Error! Repeat input." << endl;
                error = true;
                i = str.length() - 1;
            }
            else error = false;
        }

    } while (error);

    //Возврат строки с целым числом
    return str;
}

string input_date()
{
    string date;
    bool error = false;
    do
    {
        cout << "Enter date (DD.MM.YYYY): ";
        getline(cin, date);

        //Проверка длины строки и наличия разделительных точек
        if (date[2] != '.' || date[5] != '.' || date.length() != 10)
        {
            cerr << "Error! Repeat input." << endl;
            error = true;
        }
        else error = false;


        /*for (int i = 0; i < date.length(); i++)
        {
            if (!isdigit(date[i]) || date.length() > 9)
            {
                cerr << "Error! Repeat input." << endl;
                error = true;
                i = date.length() - 1;
            }
            else error = false;
        }*/

    } while (error);

    //Возврат целого числа
    return date;
}

void input_data (string &data)
{
    //Инициализация строк с данными
    string name;
    string family;
    string payout;
    string date;
    
    //Ввод имени и фамилии
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter last name: ";
    cin >> family;

    //Ввод суммы выплаты
    payout = int_input();

    //Ввод даты выплаты
    cout << "";
    cin >> date;

    //Формирование строки с данными для записи
    data = name + ' ' + family + ' ' + payout + ' ' + date;
}

void write_data (ofstream &file, string &data)
{
    file.open ("statements.txt", ios::app);
    file.is_open() ? cout << "Data recorded!" << endl : cerr << "Data not recorded! File not found!" << endl;
    file << data << endl;
    file.close();
}

int main()
{
    //Вызов функции ввода данных
    string data;
    input_data(data);

    //Запись данных в файл
    ofstream statements;
    write_data (statements, data);

}