#include <iostream>
#include <string>
#include <vector>
using namespace std;

class drink{
private:
    string drinkChoice;       //tipul bauturii
    float price;              //pretul bauturii
public:
    drink(string drinkName = "", float priceTag = 0) {
        drinkChoice = drinkName;
        price = priceTag;
    }
    ~drink(){}
};

class myCart {
private:
    vector<string> myDrinks;            //vector de bauturi din cos => neaparat sa invat cum functioneaza vectorii in C++!!!!
    int amount;                         //nr de bauturi din cos
    float price;                        //suma care urmeaza sa fie platita
    vector<float> priceList;            //lista prteurilor

public:
    myCart(){              //constructor de initializare
        myDrinks = {};
        amount = 0;
        price = 0;
        priceList = {};
    }

    void productAdd(string drink, float productPrice){       //pentru cand adaugam un produs in cos, sa actualizam nr. de produse
        amount ++;
        myDrinks.push_back(drink);
        price += productPrice;
        priceList.push_back(productPrice);
    };
    void productDelete(int index){    //pentru cand stergem un produs din cos, sa actualizam nr. de produse
        if (amount > 0) {
            amount --;
            myDrinks.erase(myDrinks.begin() + index);
            price -= priceList[index];
        }
    }

    friend ostream& operator<<(ostream& COUT, const myCart& shopping) {
        COUT<<"Your shopping cart status:"<<endl;
        for (int x = 0; x < size(shopping.myDrinks); x ++) {
            COUT << "Product "<<x + 1<<": "<<shopping.myDrinks[x] << " - " << shopping.priceList[x] << endl;
        }
        COUT<< shopping.price<<endl;
        return COUT;}

    ~myCart(){}

};

class myAccount {
private:
    string userName;                //nume de utlizator
    string password;                //parola
public:
    myAccount(string name = "", string Password = "") {
        userName = name;
        password = Password;}
    friend ostream& operator<<(ostream& COUT, const myAccount& acc) {
        COUT<< acc.userName;
        return COUT;}           //pt afisarea numelui utilizatorului!!! parola ramane tot private!! :)

    ~myAccount(){}
};

vector<float> prices = {5.99, 3.99, 6.59, 3.99, 7.99, 6.49, 4.99, 6.49, 6.49, 3.99, 5.49};
vector<string> options = {"Iced Latte", "Cold Brew", "Matcha Latte", "Iced Black Tea", "Caramel Frappucino", "Caramel Ribbon Crunch Frappucino", "Pink Drink Refresher", "Cinnamon Caramel Cream Cold Brew", "Vanilla Sweet Cream Cold Brew", "Featured Medium Roast Pike Place Roast", "Vanilla Cremè"};
string Name, Password, coffeeChoice;
short int input, input2, inputDelete;
myCart cart;
int main(){
    cout<<"Chamberlain Coffee - Easy Mobile & Online Ordering & Delivery"<<endl;

    cout<<"Connect to your account: "<<endl;
    cout<<"Username: ";
    cin>>Name;
    cout<<"Password: ";
    cin>>Password;
    cout<<endl;
    myAccount user = myAccount(Name, Password);
    cout<<"Well hello "<<user<<"! We are glad to have you back! :)"<<endl;
    cout<<"What would you like to do today? Choose one of the following options!"<<endl;
    //pana aici utilizatorul a introdus datele personale -> de cautat cum fac ca atunci cand utilizatorul scrie
    // de la tastatura sa apara * in loc de caracter??

    cout<<"1: Menu"<<endl;
    cout<<"0: Exit"<<endl<<endl;
    cout<<"Press 1 to see the menu / start adding products to your cart! :D"<<endl;
    cout<<"Press 0 to exit the app :("<<endl;
    cin>>input;
    if (input == 1) {
        cout<<endl<<"Here are your options:"<<endl;
        for (int x = 0; x < 11; x ++) {
            cout<<x + 1<<": "<<options[x]<<" "<<prices[x]<<"$"<<endl;
        }
        cout<<"If you want to delete a product from your cart, press '20'."<<endl;
        cout<<"When you are done making your cart, just press 0! :)"<<endl<<endl;
        while (input != 0) {
            cin>>input2;
            if(input2 != 20) {
                if (input2 != 0) {
                    coffeeChoice = options[input - 1];
                    cart.productAdd(coffeeChoice, prices[input - 1]);
                    cout<<cart;
                    input = input2;
                }
                else {
                    cout<<"Are you sure you want to proceed to checkout? This action is irreversible!"<<endl;
                    cout<<"Press 1 to go back to editing your shopping cart!"<<endl;
                    cout<<"Press 0 to go to checkout"<<endl;
                    cin>>input2;
                    input = input2;
                }
            }
            else {
                cout<<"Choose the index of the product that you would like to delete from your cart!"<<endl;
                cin>>inputDelete;       //am gasit un produs pe care vrem sa il stergem & inputDelete retine al catelea produs sa fie sters;
                cart.productDelete(inputDelete - 1);
                cout<<cart;
            }
        }
        cout<<"You are being redirected on the checkout page..."<<endl;
        cout<<"Subtotal: ";     //de aici urmeaza partea de checkout etc!!
    }
    if (input == 0){
        return 0;
    }
    return 0;

}
