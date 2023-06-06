#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void input_data (string &data)
{
    string name;
    string family;
    int payout;
    string date;
    
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter last name: ";
    cin >> family;
    cout << "Enter payout amount: ";
    cin >> payout;
    string str_payout = to_string(payout);
    cout << "Enter date: ";
    cin >> date;

    data = name + ' ' + family + ' ' + str_payout + ' ' + date;
}

void write_data (ofstream &file, string &data)
{
    file.open ("statements.txt", ios::app);
    file.is_open() ? cout << "File is open!" << endl : cout << "File is not open!" << endl;
    file << data << endl;
    file.close();
}

int main()
{
    //Инициализация строки с данными
    string data;

    input_data(data);

    ofstream statements;
    write_data (statements, data);

}