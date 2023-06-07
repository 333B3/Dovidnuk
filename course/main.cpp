#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
using namespace std;
void dataoutSearch() { //частина яка використовується для відображення пошукового результату
    SetConsoleCP(1251);
    string line;
    system("cls");

    ifstream in("search.txt"); //відкриття файлу куди було записано результат пошуку
    if (in.is_open())
    {
        while (getline(in, line))
        {
            cout << line << endl;
        }
    }
    in.close();
    cout << "=========================================" << endl;
    string back;
    cout << "\nНАЗАД(0)";
    cin >> back;
    system("cls");
}
void search() {     //частина для пошуку і написання результату в файл
    ifstream inF("data.txt");   //файл з усіма контактами
    ofstream outF("search.txt"); //створюємо новий файл куди буде записуватися інформація
    string search;
    cout << "===========Пошук===========" << endl;
    cout << "Ведіть відомі вам дані:" << endl;
    cin >> search;
    string line;

    while (getline(inF, line)) {
        if (line.find(search) != string::npos) {
            outF << line << endl;
        }
    }
    inF.close();
    outF.close();
    cout << "Ось знайдені контакти" << endl;
}
void datadel() { //частина для видалення контактів
    ofstream fout;
    fout.open("data.txt"); //перезаписуємо файл з контактами, він очиститься 
    if (!fout.is_open())
    {
        cout << "Файл не відкрився" << endl;
    }
    else {
        string del;
    }
    system("cls");
    cout << "ВИДАЛЕННЯ";
    Sleep(500);
    cout << ".";
    Sleep(600);
    cout << ".";
    Sleep(500);
    cout << "." << endl;
    cout << "УСПІШНО!";
    Sleep(1000);
    system("cls");
}
void dataout() { //частина для відображення всіх записаних контактів
    SetConsoleCP(1251);

    string line;
    system("cls");
    cout << "================КОНТАКТИ=================" << endl;

    ifstream in("data.txt");
    if (in.is_open())
    {

        while (getline(in, line))
        {
            cout << line << endl;
        }
    }
    in.close();
    cout << "=========================================" << endl;

    string back;
    cout << "\nНАЗАД(0)";
    cin >> back;
    system("cls");
}
void data() { //частина для запису нових контактів
    SetConsoleCP(1251);
    cout << "===========Додати_контакт===========" << endl;
    ofstream fout;
    fout.open("data.txt", ofstream::app); // до створеного файлу буде постійно додаватися нова інформація
    if (!fout.is_open())
    {
        cout << "Файл не відкрився" << endl;
    }
    else {
        SetConsoleCP(1251);

        string pib;
        string number;
        string age;
        cout << "Ведіть ПІП:" << endl;
        cin.get();
        getline(cin, pib);
        cout << "Ведіть номер:"<< endl;
        cin.get();
        getline(cin, number);  
        cout << "Ведіть дату народження:" << endl;
        cin >> age;
        fout << pib << "||" << number << "||" << age << endl;  
    }
}
int main() {    //частина де знаходиться менб програми та посилання на всі діючі блоки
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int menu;
    cout << "=========================================" << endl;
    cout << "____Телефонний довідник____" << endl;
    cout << "1. Додати контакт" << endl;
    cout << "2. Видалити контакти" << endl;
    cout << "3. Показати всі контакти" << endl;
    cout << "4. Пошук контакту" << endl;
    cout << "5. Вийти" << endl;
    cout << "\n6. очистити простір\n" << endl;
    cout << "=========================================" << endl;
    cout << "виберіть пункт: ";
    cin >> menu;

    switch (menu) {
    case 1:
        cout << "__Додавання контакту__" << endl;
        system("cls");
        data();
        cout << "Почекайте, збереження" << endl;
        Sleep(2000);
        cout << "Успішно!";
        Sleep(1500);
        system("cls");
        main();

        break;
    case 2:
        
        cout << "ЗАЧЕКАЙТЕ  ";
        datadel();
        Sleep(500);
        main();

        break;
    case 3:
        dataout();
        main();

        break;
    case 4:
        system("cls");
        search();
        dataoutSearch();
        main();

        break;
    case 5:
        cout << "До побачення!" << endl;
        return 0;
        break;
    case 6:
        system("cls");
        main();
    default:
        system("cls");
        cout << "Ви ввели неправильний пункт меню"<<endl<<"Спробуйте ще раз";
        Sleep(1500);
        system("cls");
        main();
        break;
    }
    return 0;
}
