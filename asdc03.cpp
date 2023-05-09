#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <fstream>
#include <atlstr.h>
#include <stdio.h>

using namespace std;

struct base
{
    int nr;
    char name[20];
    char description[25];
    double price;
    int count;
    char unit[5];
    long long int id;
    base* b;
};

void print()
{
    FILE* file = fopen("mebeli1.txt", "rt");
    char str[100];
    while (!feof(file))
    {
        if (!fgets(str, 100, file)) break;
        puts(str);
    }
    fclose(file);
}


void addvd(base* m)
{
    int t;
    cout << "n = ";
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cout << "Name: ";
        cin >> m[i].name;
        cout << "Description: ";
        cin >> m[i].description;
        cout << "Price: ";
        cin >> m[i].price;
        cout << "Count: ";
        cin >> m[i].count;
        cout << "Unit: ";
        cin >> m[i].unit;
        cout << "Id: ";
        cin >> m[i].id;
    }

    fstream f("mebeli1.txt", ios::out);
    for (int i = 0; i < t; i++)
    {
        for (int i = 0; !f.eof(); i++)
        {
            char temp[20];
            f >> temp;
            if (f.eof()) break;
            f >> m[i].name;
            cout << m[i].name << " ";
            f >> m[i].description;
            cout << m[i].description << " ";
            f >> m[i].price;
            cout << m[i].price << " ";
            f >> m[i].count;
            cout << m[i].count << " ";
            f >> m[i].unit;
            cout << m[i].unit << " ";
            f >> m[i].id;
            cout << m[i].id << "\n ";
        }
        f.close();
    }
}

class list
{
private:
    base* head, * tail;
public:
    list()
    {
        head = NULL;
        tail = NULL;
    }
    void display()
    {

        base* temp = new base;
        temp = head;
        while (temp != NULL)
        {
            cout << temp->nr << "\t";
            temp = temp->b;
        }
    }
    void insert_start(int value)
    {
        base* temp = new base;
        temp->nr = value;
        temp->b = head;
        head = temp;
    }
    void insert_position(int pos, int value)
    {
        base* pre = new base;
        base* cur = new base;
        base* temp = new base;
        cur = head;
        for (int i = 1; i < pos; i++)
        {
            pre = cur;
            cur = cur->b;
        }
        temp->nr = value;
        pre->b = temp;
        temp->b = cur;
    }
    void delete_first()
    {
        base* temp = new base;
        temp = head;
        head = head->b;
        delete temp;
    }
    void delete_last()
    {
        base* current = new base;
        base* previous = new base;
        current = head;
        while (current->b != NULL)
        {
            previous = current;
            current = current->b;
        }
        tail = previous;
        previous->b = NULL;
        delete current;
    }
    void delete_position(int pos)
    {
        base* current = new base;
        base* previous = new base;
        current = head;
        for (int i = 1; i < pos; i++)
        {
            previous = current;
            current = current->b;
        }
        previous->b = current->b;
    }
};

int main()
{
    int k;
    base* p1 = new base[100];
    do {
        cout << "1. Enter data\n";
        cout << "2. Show data\n";
        cout << "3. Delete\n";
        cout << "5. Exit\n";
        cout << "==>";
        cin >> k;
        switch (k) {
        case 1: addvd(p1); break;
        case 2: print(); break;
        case 3: cout << ""; break;
        }
    } while (k != 4);
    system("pause");
    return 0;
}