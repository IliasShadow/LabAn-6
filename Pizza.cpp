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
        cout << "Введите количество соли: ";
        cin >> Count;
        add_salt(Count);
    }
    void add_salt(unsigned int Count) {
        salt = Count;
        Prise += 2*Count;
    }
    void Cheese() {
        unsigned int Count;
        cout << "Введите количество сыра: ";
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
            cout<<"Пицц такого диаметра в ассортименте нет - ";
            break;
        }
        return Prise;
    }
    void Print_Pizza() {
        cout << "Название: " << Name << endl;
        cout << "Описание: " << Description << endl;
        cout << "Размер: " << Size << " см" << endl;
        cout << "Соль: " << salt << endl;
        cout << "Сыр: " << cheese << endl;
        cout << "Цена: " << Size_prise() << " руб." << endl;
    }
    int get_Prise(){return Prise;};
};

class Margarita: public Pizza {
public:
    Margarita(unsigned int Size): Pizza("Пицца Маргарита", "Нежное тесто, томатный соус, сыр моцарелла и ароматные прованские травы", Size, 389) {}
};
class Four_seasons: public Pizza {
public:
    Four_seasons(unsigned int Size): Pizza("Пицца Четыре сезона", "Четыре ароматный кусочка с разными мясными начинками", Size, 539) {}
};
class Pepperoni: public Pizza {
public:
    Pepperoni(unsigned int Size): Pizza("Пицца Пепперони", "Салями пепперони, томаты, сыр моцарелла", Size, 539) {}
};
class Hawaiian: public Pizza {
public:
    Hawaiian(unsigned int Size): Pizza("Пицца Гавайская", "Сочетание нежной ветчины с кусочками ананаса и сыром моцарелла на томатном соусе", Size, 489) {}
};
class Mushroom: public Pizza {
public:
    Mushroom(unsigned int Size): Pizza("Пицца Грибная", "Моцарелла, шампиньоны, соус красный ", Size, 529) {}
};
class Four_cheeses: public Pizza {
public:
    Four_cheeses(unsigned int size): Pizza("Пицца Четыре сыра", "Оригинальное сочетание сыров на томатном соусе: моцарелла, пармезан, горгонзола, маасдам и ароматные специи", size, 539) {}
};
class Order {
public:
    vector<Pizza> pizzas;
    void Add(Pizza pizza) {
        pizzas.push_back(pizza);
    }
    void Menu() {
        cout<< "Вот Ваше меню:" << endl;
        cout<< "1 - Пицца Маргарита" << endl;
        cout<< "2 - Пицца Четыре сезона" << endl;
        cout<< "3 - Пицца Пепперони" << endl;
        cout<< "4 - Пицца Гавайская" << endl;
        cout<< "5 - Пицца Грибная" << endl;
        cout<< "6 - Пицца Четыре сыра" << endl;
        cout << endl;
    }
    void Print_order() {
        cout << "Ваш заказа:"<< endl;
        int price = 0;
        for (Pizza pizza : pizzas) {
            pizza.Print_Pizza();
            price += pizza.get_Prise();
        }
        cout << "Итого: " << price << " рублей" << endl;
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
    cout << "Рады приветствовать Вас в нашей пиццерии"<< endl;
    do
    {
        order.Menu();
        cout<< "Введите номер пиццы:  "<< endl;
        cin >> pizza;
        cout << "Введите размер пиццы (25, 30, 35, 40): ";
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
            cout << "Вы неправильно ввели номер. Попробуйте снова" << endl << endl;
            continue;
        }
        n=false;
        cout << "Хотите подсолить пиццу(0-нет,1-да)? " << endl;
        cin >> n;
        if (n) select->Salt();
        cout << "Хотите добавить сыра (0-нет,1-да)? " << endl;
        cin >> n;
        if (n) select->Cheese();
        order.Add(*select);
        delete select;
        cout<<"Введите 1, если хотите продожить заказ, иначе 0" << endl;
        cin>> cont;
    } while (cont);
    order.Print_order();
    return 0;
}
