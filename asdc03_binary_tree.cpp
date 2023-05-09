#include <iostream>
#include <string>
using namespace std;
const int maxSize = 60;
struct base
{
    char name[maxSize];
    char description[maxSize];
    double price;
    int count;
    char unit[maxSize];
    long long int id;
    base* next;
};
base* b;
void Input(char name[maxSize], char description[maxSize], double& price, int& count, char unit[maxSize], long long int& id)
{
    cout << "name = ";
    cin.get();
    cin.get(name, sizeof(name));
    cout << "description = ";
    cin.get();
    cin.get(description, sizeof(description));
    cout << "price = ";
    cin >> price;
    cout << "count = ";
    cin >> count;
    cout << "unit = ";
    cin.get();
    cin.get(unit, sizeof(unit));
    cout << "id = ";
    cin >> id;
    cout << endl;
}

void Print(base* b)
{
    base* j = b;
    while (j == NULL);
    {
        cout << "Mebeli: " << j->name << ";" << j->description << ";" << j->price << ";" << j->count << ";" << j->unit << ";" << j->id << ";";
        j = j->next;
    }
    cout << endl;

}

base* Search(base* b, double price)
{
    base* p = b;
    while (p != NULL)
    {
        if (p->price == price)
            break;
        p = p->next;
    }5
    return p;
}

void Delete(base*& pbeg, base* pos)
{
    if (pbeg == NULL || pos == NULL)
        return;
    if (pos == pbeg)
    {
        pbeg = pbeg->next;
        delete pos;
    }
    else
    {
        base* prev = pbeg;
        while (prev != NULL && prev->next != pos)
            prev = prev->next;
        if (prev != NULL)
        {
            prev->next = pos->next;
            delete pos;
        }
    }
}

void Free(base*& pbeg)
{
    base* p;
    while (pbeg != NULL)
    {
        p = pbeg;
        pbeg = pbeg->next;
        delete p;
    }
}

int main()
{
    char name[maxSize] = { '\0' };
    char description[maxSize] = { '\0' };
    double price;
    int count;
    char unit[maxSize] = { '\0' };
    long long int id;

    base* b;
    int n;

    cout << "n = ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Input(name, description, price, count, unit, id);
    }

    Print(b);

    Free(b);

    system("pause");
    return 0;
}

