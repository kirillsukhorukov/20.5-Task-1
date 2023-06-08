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
        //Сброс ошибки
        error = false;

        //Ввод даты
        cout << "Enter date (DD.MM.YYYY): ";
        getline(cin, date);

        //Проверка длины строки,наличия разделительных точек, что день месяц и год - числа
        if (date[2] != '.' || date[5] != '.' || date.length() != 10 
        || !isdigit(date[0]) || !isdigit(date[1]) || !isdigit(date[3]) || !isdigit(date[4])
        || !isdigit(date[6]) || !isdigit(date[7]) || !isdigit(date[8]) || !isdigit(date[9]))
        {
            cerr << "Error! Invalid input format! Repeat input." << endl;
            error = true;
        }
        else
        {
            //Вытаскиваем из строки день, месяц и год
            int DD = stoi (date.substr(0,2));
            int MM = stoi (date.substr(3,2));

            //Проверяем корректность ввода дня и месяца
            int dayInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
            if(MM < 1 || MM > 12) 
            {
                cerr << "Error! Month entered incorrectly! Repeat input." << endl;
                error = true;
            }
            else if (DD < 1 || DD > dayInMonth[MM-1])
            {
                cerr << "Error! Day entered incorrectly! Repeat input." << endl;
                error = true;
            }        
        }

        
    } while (error);

    //Возврат строки с датой
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
    getline(cin, name);
    cout << "Enter last name: ";
    getline(cin, family);

    //Ввод суммы выплаты
    payout = int_input();

    //Ввод даты выплаты
    date = input_date();

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