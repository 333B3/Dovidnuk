#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
using namespace std;
void dataoutSearch() { //������� ��� ��������������� ��� ����������� ���������� ����������
    SetConsoleCP(1251);
    string line;
    system("cls");

    ifstream in("search.txt"); //�������� ����� ���� ���� �������� ��������� ������
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
    cout << "\n�����(0)";
    cin >> back;
    system("cls");
}
void search() {     //������� ��� ������ � ��������� ���������� � ����
    ifstream inF("data.txt");   //���� � ���� ����������
    ofstream outF("search.txt"); //��������� ����� ���� ���� ���� ������������ ����������
    string search;
    cout << "===========�����===========" << endl;
    cout << "����� ���� ��� ���:" << endl;
    cin >> search;
    string line;

    while (getline(inF, line)) {
        if (line.find(search) != string::npos) {
            outF << line << endl;
        }
    }
    inF.close();
    outF.close();
    cout << "��� ������� ��������" << endl;
}
void datadel() { //������� ��� ��������� ��������
    ofstream fout;
    fout.open("data.txt"); //������������ ���� � ����������, �� ���������� 
    if (!fout.is_open())
    {
        cout << "���� �� ��������" << endl;
    }
    else {
        string del;
    }
    system("cls");
    cout << "���������";
    Sleep(500);
    cout << ".";
    Sleep(600);
    cout << ".";
    Sleep(500);
    cout << "." << endl;
    cout << "��ϲ���!";
    Sleep(1000);
    system("cls");
}
void dataout() { //������� ��� ����������� ��� ��������� ��������
    SetConsoleCP(1251);

    string line;
    system("cls");
    cout << "================��������=================" << endl;

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
    cout << "\n�����(0)";
    cin >> back;
    system("cls");
}
void data() { //������� ��� ������ ����� ��������
    SetConsoleCP(1251);
    cout << "===========������_�������===========" << endl;
    ofstream fout;
    fout.open("data.txt", ofstream::app); // �� ���������� ����� ���� ������� ���������� ���� ����������
    if (!fout.is_open())
    {
        cout << "���� �� ��������" << endl;
    }
    else {
        SetConsoleCP(1251);

        string pib;
        string number;
        string age;
        cout << "����� ϲ�:" << endl;
        cin.get();
        getline(cin, pib);
        cout << "����� �����:"<< endl;
        cin.get();
        getline(cin, number);  
        cout << "����� ���� ����������:" << endl;
        cin >> age;
        fout << pib << "||" << number << "||" << age << endl;  
    }
}
int main() {    //������� �� ����������� ���� �������� �� ��������� �� �� ���� �����
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int menu;
    cout << "=========================================" << endl;
    cout << "____���������� �������____" << endl;
    cout << "1. ������ �������" << endl;
    cout << "2. �������� ��������" << endl;
    cout << "3. �������� �� ��������" << endl;
    cout << "4. ����� ��������" << endl;
    cout << "5. �����" << endl;
    cout << "\n6. �������� ������\n" << endl;
    cout << "=========================================" << endl;
    cout << "������� �����: ";
    cin >> menu;

    switch (menu) {
    case 1:
        cout << "__��������� ��������__" << endl;
        system("cls");
        data();
        cout << "���������, ����������" << endl;
        Sleep(2000);
        cout << "������!";
        Sleep(1500);
        system("cls");
        main();

        break;
    case 2:
        
        cout << "���������  ";
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
        cout << "�� ���������!" << endl;
        return 0;
        break;
    case 6:
        system("cls");
        main();
    default:
        system("cls");
        cout << "�� ����� ������������ ����� ����"<<endl<<"��������� �� ���";
        Sleep(1500);
        system("cls");
        main();
        break;
    }
    return 0;
}
