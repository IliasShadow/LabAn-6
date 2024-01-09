#include <iostream>
#include <vector>
using namespace std;

class Pizza {
private:
    string Name;
    string Description;
    unsigned int Size;
    int Prise;
    int salt;
    int cheese;
public:
    Pizza (string n, string d, unsigned int s, int p): Name(n), Description(d), Prise(p), Size(s), salt(0), cheese(0) {}

    void Salt() {
        unsigned int Count;
        cout << "������� ���������� ����: ";
        cin >> Count;
        add_salt(Count);
    }
    void add_salt(unsigned int Count) {
        salt = Count;
        Prise += 2*Count;
    }
    void Cheese() {
        unsigned int Count;
        cout << "������� ���������� ����: ";
        cin >> Count;
        add_cheese(Count);
    }
    void add_cheese(unsigned int Count) {
        cheese = Count;
        Prise  += 5*Count;
    }
    virtual unsigned int Size_prise() {
        switch (Size) {
        case 25:
            Prise += 0;
            break;
        case 30:
            Prise += 50;
            break;
        case 35:
            Prise += 75;
            break;
        case 40:
            Prise += 100;
            break;
        default:
            Prise=0;
            cout<<"���� ������ �������� � ������������ ��� - ";
            break;
        }
        return Prise;
    }
    void Print_Pizza() {
        cout << "��������: " << Name << endl;
        cout << "��������: " << Description << endl;
        cout << "������: " << Size << " ��" << endl;
        cout << "����: " << salt << endl;
        cout << "���: " << cheese << endl;
        cout << "����: " << Size_prise() << " ���." << endl;
    }
    int get_Prise(){return Prise;};
};

class Margarita: public Pizza {
public:
    Margarita(unsigned int Size): Pizza("����� ���������", "������ �����, �������� ����, ��� ��������� � ��������� ���������� �����", Size, 389) {}
};
class Four_seasons: public Pizza {
public:
    Four_seasons(unsigned int Size): Pizza("����� ������ ������", "������ ��������� ������� � ������� ������� ���������", Size, 539) {}
};
class Pepperoni: public Pizza {
public:
    Pepperoni(unsigned int Size): Pizza("����� ���������", "������ ���������, ������, ��� ���������", Size, 539) {}
};
class Hawaiian: public Pizza {
public:
    Hawaiian(unsigned int Size): Pizza("����� ���������", "��������� ������ ������� � ��������� ������� � ����� ��������� �� �������� �����", Size, 489) {}
};
class Mushroom: public Pizza {
public:
    Mushroom(unsigned int Size): Pizza("����� �������", "���������, ����������, ���� ������� ", Size, 529) {}
};
class Four_cheeses: public Pizza {
public:
    Four_cheeses(unsigned int size): Pizza("����� ������ ����", "������������ ��������� ����� �� �������� �����: ���������, ��������, ����������, ������� � ��������� ������", size, 539) {}
};
class Order {
public:
    vector<Pizza> pizzas;
    void Add(Pizza pizza) {
        pizzas.push_back(pizza);
    }
    void Menu() {
        cout<< "��� ���� ����:" << endl;
        cout<< "1 - ����� ���������" << endl;
        cout<< "2 - ����� ������ ������" << endl;
        cout<< "3 - ����� ���������" << endl;
        cout<< "4 - ����� ���������" << endl;
        cout<< "5 - ����� �������" << endl;
        cout<< "6 - ����� ������ ����" << endl;
        cout << endl;
    }
    void Print_order() {
        cout << "��� ������:"<< endl;
        int price = 0;
        for (Pizza pizza : pizzas) {
            pizza.Print_Pizza();
            price += pizza.get_Prise();
        }
        cout << "�����: " << price << " ������" << endl;
    }
};

int main() {
    setlocale(0, "");
    Order order;
    int pizza;
    bool n;
    bool cont = 1;
    unsigned int Size;
    Pizza* select;
    cout << "���� �������������� ��� � ����� ��������"<< endl;
    do
    {
        order.Menu();
        cout<< "������� ����� �����:  "<< endl;
        cin >> pizza;
        cout << "������� ������ ����� (25, 30, 35, 40): ";
        cin >> Size;
        switch (pizza) {
        case 1:
            select = new Margarita(Size);
            break;
        case 2:
            select = new Four_seasons(Size);
            break;
        case 3:
            select = new Pepperoni(Size);
            break;
        case 4:
            select = new Hawaiian(Size);
            break;
        case 5:
            select = new Mushroom(Size);
            break;
        case 6:
            select = new Four_cheeses(Size);
            break;
        default:
            cout << "�� ����������� ����� �����. ���������� �����" << endl << endl;
            continue;
        }
        n=false;
        cout << "������ ��������� �����(0-���,1-��)? " << endl;
        cin >> n;
        if (n) select->Salt();
        cout << "������ �������� ���� (0-���,1-��)? " << endl;
        cin >> n;
        if (n) select->Cheese();
        order.Add(*select);
        delete select;
        cout<<"������� 1, ���� ������ ��������� �����, ����� 0" << endl;
        cin>> cont;
    } while (cont);
    order.Print_order();
    return 0;
}
