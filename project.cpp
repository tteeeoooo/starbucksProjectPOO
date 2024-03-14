#include <iostream>
#include <string>
#include <vector>
#include <termios.h>
#include <unistd.h>
#include <cstring>
#include <iomanip>
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

    string drinkName() {
        return drinkChoice;
    }
    float drinkPrice() {
        return price;
    }

    friend ostream& operator<<(ostream& COUT, const drink& myDrink) {
        cout<<myDrink.drinkChoice<<" "<<myDrink.price;
        return COUT;
    }

    ~drink(){
        drinkChoice = "";
        price = 0;
    }
};

class myCart {
private:
    vector<string> myDrinks;            //vector de bauturi din cos => neaparat sa invat cum functioneaza vectorii in C++!!!!
    //int amount;                         //nr de bauturi din cos
    float price;                        //suma care urmeaza sa fie platita
    vector<float> priceList;            //lista prteurilor

public:
    myCart(){              //constructor de initializare
        myDrinks = {};
        //amount = 0;
        price = 0;
        priceList = {};
    }

    myCart(float newPrice) : price(newPrice) {}

    void productAdd(string drink, float productPrice){       //pentru cand adaugam un produs in cos, sa actualizam nr. de produse
        //amount ++;
        myDrinks.push_back(drink);
        price += productPrice;
        priceList.push_back(productPrice);
    };
    void productDelete(int index){    //pentru cand stergem un produs din cos, sa actualizam nr. de produse
        if (myDrinks.size() > 0) {
            //amount --;
            myDrinks.erase(myDrinks.begin() + index);
            price -= priceList[index];
        }
    }
    float cartPrice() {
        return price;
    }


    void applySale(int off) {
        price = price - (price * off) / 100;
    }


    myCart &operator=(const myCart& shopping) {
        if (this != &shopping) {
            //myDrinks = shopping.myDrinks;
            price = shopping.price;
            //priceList = shopping.priceList;
        }
        return *this;
    }

    myCart(const myCart& shopping): myDrinks(shopping.myDrinks) {};

    friend ostream& operator<<(ostream& COUT, const myCart& shopping) {
        COUT<<"Your shopping cart status:"<<endl;
        for (int x = 0; x < size(shopping.myDrinks); x ++) {
            COUT << "Product "<<x + 1<<": "<<shopping.myDrinks[x] << " - " << shopping.priceList[x] << endl;
        }
        COUT<< shopping.price<<endl;
        return COUT;
    }

    ~myCart(){
        myDrinks = {};
        //amount = 0;
        price = 0;
        priceList = {};}
}cart;

class myAccount {
private:
    string userName;                //nume de utlizator
    string password;                //parola
public:
    myAccount(string name = "", string Password = "") {
        userName = name;
        password = Password;
    }



    void userRead() {
        cout << "Username: ";
        cin >> userName;
        cout << "Password: ";
        cin.ignore();
        //disableEcho();
        string character;
        while ((character = cin.get()) != "\n") {
            password.append(character);
            cout << '*'; // Afișează "*" pentru fiecare caracter
        }
        cout<<endl;
        //enableEcho();
    }


    friend ostream& operator<<(ostream& COUT, const myAccount& acc) {
        COUT<< acc.userName;
        return COUT;
    }           //pt afisarea numelui utilizatorului!!! parola ramane tot private!! :)

    ~myAccount() {
        userName = "";
        password = "";
    }
}user;

void menuText();

void menuOptions(vector<drink> coffeeMenu);

void underLine();

void upperLine();

float priceCalculation(float oldPrice, int sale);

void order();

void atAddressPayment();

void giveATip();

void textToFinish();

void orderAndExit() ;

void creditCardInfo ();

void deliveryAddress();

void coutFinishedOrder();

void coutAbortedOrder();

void todaysSales();

void underLine();

void upperLine();



int main() {
    cout<<"Chamberlain Coffee - Easy Mobile & Online Ordering & Delivery"<<endl;
    todaysSales();


    cout<<"Connect to your account: "<<endl;
    user.userRead();
    cout<<"Well hello "<<user<<"! We are glad to have you back! :)"<<endl;
    cout<<"What would you like to do today? Choose one of the following options!"<<endl;
    //pana aici utilizatorul a introdus datele personale -> de cautat cum fac ca atunci cand utilizatorul scrie
    // de la tastatura sa apara * in loc de caracter??
    //update: nu merge cum trebuie!!!

    cout<<"1: Menu"<<endl;
    cout<<"0: Exit"<<endl<<endl;
    cout<<"Press 1 to see the menu / start adding products to your cart! :D"<<endl;
    cout<<"Press 0 to exit the app :("<<endl;
    short int input;
    cin>>input;
    if (input == 1) {
        //functia order()

        order();
        //pana aici se face cosul
        // se poate modifica de cate ori este nevoie => e ok
        //singura problema e cu afisarea parolei

        //finishOrder();
        textToFinish();
        cin >> input;

        if (input == 1) {
            deliveryAddress();
            cout << endl << "Choose one of the following payment options: "<<endl;
            cout << "1: Credit Card" << endl;
            cout << "2: Cash on delivery" << endl;
            cin >> input;
            if (input == 1) {
                creditCardInfo();

                cout << endl << "Are your sure you want to place the order?" << endl;
                cout << "Press 1 to confirm the order! :D" << endl;
                cout << "Press 2 to switch to cash on delivery payment!" <<endl;
                cout << "Press 3 to go back to editing your cart" << endl;
                cout << "Press 0 to exit the app! :(" << endl;
                cin >> input;

                if (input == 0) {
                    cout << "We are sorry that you are leaving!";
                    return 0;
                }
                else {
                    if (input == 1) {
                        cout << "Thank you for your order! We are grinding your coffee right now, to make sure that you will have it as soon as possible! :)";
                        return 0;
                    }
                    else {
                        if (input == 2) {
                            atAddressPayment();
                        }
                        else {
                            if (input == 3) {
                                order();
                            }
                            else {
                                cout << "We are sorry that you are leaving!";
                                return 0;
                            }
                        }
                    }
                }
            }
            else {
                if (input == 2) {
                    atAddressPayment();
                }
                cout << "Press 1 to confirm the order!" << endl << "Press 0 to cancel and exit the app." << endl;
                cin >> input;
                if (input == 0) {
                    cout << "We are sorry that you are leaving!";
                }
                else {
                    coutFinishedOrder();
                }
                return 0;
            }
        }

        if (input == 2) {
            order();
        }

        else {
            if (input == 0 ){
                cout<<"We are sorry to see you leave!";
                return 0;
            }
        }
    }

    if (input == 0){
        return 0;
    }
    return 0;
}


void order() {
    short int input, input2, inputDelete;
    bool appliedSale = false;
    float newPrice;
    vector<drink> coffeeMenu = {drink("Iced Latte", 5.99), drink("Cold Brew", 3.99),
                                drink("Matcha Latte", 6.49),drink("Pink Drink Refresher", 4.59),
                                drink("Vanilla Sweet Cream Cold Brew", 6.49),drink("Vanilla Cremè", 5.49),
                                drink("Cinnamon Caramel Cream Cold Brew", 3.99),
                                drink("Cold Brew", 4.99), drink("Caramel Ribbon Crunch Frappucino", 5.49),
                                drink("Caramel Ribbon Crunch Frappucino", 6.99),
                                drink("Oleato Golden Foam Iced Shaken Espresso With Toffeenut", 7.49),
                                drink("Iced Matcha Tea Latte With Oatmilk", 6.49),
                                drink("Mocha Cookie Crumble Frappuccino"),drink("Espresso", 2.99), drink("Fiji Water", 3.29)};
    menuText();
    menuOptions(coffeeMenu);
    input = 1;
    while (input != 0) {
        cin >> input;
        if (input != 20) {
            if (input != 0) {
                cart.productAdd(coffeeMenu[input - 1].drinkName(), coffeeMenu[input - 1].drinkPrice());
                cout << cart;
                if (cart.cartPrice() > 30) {
                    //newPrice = cart.cartPrice() - (cart.cartPrice() * 25) / 100;
                    newPrice = priceCalculation(cart.cartPrice(), 25);
                    if (appliedSale == false) {
                        cout << "You are now eligible for the sale! :)" << endl;
                        appliedSale = true;
                    }
                    else {
                        ;
                    }
                    cout<<"Cart Price with 25% off: " << newPrice << endl;
                }
            }
            else {
                cout << "Are you sure you want to proceed to checkout? This action is irreversible!" << endl;
                cout << "Press 1 to go back to editing your shopping cart!" << endl;
                cout << "Press 0 to go to checkout" << endl;
                cin >> input2;
                if (input2 == 0) {
                    break;
                }
                else {
                    order();
                }
            }
        }
        else {
            cout << "Choose the index of the product that you would like to delete from your cart!" << endl;
            cin>> inputDelete;       //am gasit un produs pe care vrem sa il stergem & inputDelete retine al catelea produs sa fie sters;
            cart.productDelete(inputDelete - 1);
            cout << cart;
        }
    }
}


float priceCalculation(float oldPrice, int sale) {
    float newPrice;
    newPrice = oldPrice - (oldPrice * sale) / 100;
    return oldPrice - (oldPrice * sale) / 100;
}

void orderAndExit() {
    short int input;
    cout <<endl << "Would you like to order your cart?" << endl;
    cout << "Press 1 to confirm!" << endl;
    cout << "Press 0 to exit! :(" << endl;
    cin >> input;
    if (input == 1) {
        coutFinishedOrder();
    }
    else {
        coutAbortedOrder();
    }
}

void menuText() {
    cout << "Choose the index of a product each time your want to add it to your cart! :D"<<endl;
    cout << "If you want to delete a product from your cart, press '20'." << endl;
    cout << "When you are done making your cart, just press 0! :)" << endl << endl;
}


void menuOptions(vector<drink> coffeeMenu) {
    cout << endl << "Here are your options:" << endl;
    for (int x = 0; x < 15; x++) {
        cout << "Product " << x + 1 << ": " << coffeeMenu[x] << endl;
    }
}

void textToFinish() {
    cout << endl << "Are you sure you don't want to edit your cart?" << endl;
    cout << "Press 1 to go introduce your delivery information!" << endl;
    cout << "Press 2 to go back to editing your cart!" << endl;
    cout << "Press 0 to exit :(" << endl;
}

void deliveryAddress() {
    string address;
    int zipCode;
    cout << "You are being redirected on the checkout page..." << endl;
    cout << "Subtotal: " << cart.cartPrice();     //de aici urmeaza partea de checkout etc!!
    if (cart.cartPrice() >= 30) {
        cout<< priceCalculation(cart.cartPrice(), 25) << endl;
    }
    else {
        cout << cart.cartPrice() << endl;
    }
    cout << "Our products do not support dropbox delivery! You will receive them through Doordash as soon as possible." << endl;
    cout << endl << "Introduce the delivery information!" << endl;
    cout << "Address: ";
    cin >> address;
    cout << endl << "Zip code: ";
    cin >> zipCode;
}


void creditCardInfo () {
    long int creditCard;
    short int input;
    cout << "Introduce your credit card information" << endl;
    cout << "Card number: ";
    cin >> creditCard;
    cout << "CVV/CVC/CVC2: ";
    cin >> input;
    cout << endl << "Would you like to give a tip to the delivery person?" << endl;
    cout << "Press 1 for yes! :)" << endl;
    cout << "Press 0 for no!" << endl;
    cin >> input;
    if (input == 1) {
        giveATip();
        cout << endl;
    }
    else {
        cout << "Are you sure? :(" << endl;
        cin >> input;
        if (input == 0) {
            cout << "Thank you for your order! We are grinding your coffee right now, to make sure that you will have it as soon as possible! :)";
        }
        else {
            giveATip();
            orderAndExit();
        }
    }
}

void atAddressPayment () {
    short int input;
    cout << "Are you sure you want to pay at the delivery?" << endl;
    cout << "Press 1 for yes" << endl;
    cout << "Press 0 to switch to credit card payment" << endl;
    cin >> input;

    if (input == 1) {
        cout << "You choose at delivery payment." << endl;
    }
    else {
        cout << "You switched to credit card payment!" << endl;
        creditCardInfo();
    }
    cout << "Would you like to give a tip to the delivery person?" << endl;
    cout << "Press 1 for yes! :)" << endl;
    cout << "Press 0 for no!" << endl;
    cin >> input;
    if (input == 1) {
        giveATip();
    }
    else {
        ;
    }
}

void coutFinishedOrder() {
    cout << "Thank you for your order! We are grinding your coffee right now, to make sure that you will have it as soon as possible! :)";
}

void coutAbortedOrder() {
    cout << "We are sorry that you are leaving! See you next time!";
}

void todaysSales() {
    cout << "Here is today's deal!" << endl;
    underLine();
    cout << "\uFE33" << "25% off for orders over $30" << "\uFE33" << endl;
    upperLine();
}

void giveATip() {
    short int input;
    float tip;
    cout << "How much would you like to tip your delivery person?" << endl;
    cout << "Press 1 for 10%" << endl;
    cout << "Press 2 for 20%" << endl;
    cout << "Press 3 for 50%" << endl;
    cout << "Press 4 for 100%" << endl;
    cout << "Press 0 to skip" << endl;
    cin >> input;

    if (input == 1) {
        tip = priceCalculation(cart.cartPrice(), 10);
    }
    if (input == 2) {
        tip = priceCalculation(cart.cartPrice(), 20);
    }
    if (input == 3) {
        tip = priceCalculation(cart.cartPrice(), 50);
    }
    if (input == 4) {
        tip = priceCalculation(cart.cartPrice(), 100);
    }
    cout << endl << "You will pay: " << cart.cartPrice() + tip << endl;
}

void underLine() {
    for (int i = 0; i < 30; i ++) {
        cout << "_";
    }
    cout << endl;
}

void upperLine() {
    for (int i = 0; i < 30; i ++) {
        cout << "‾";
    }
    cout<<endl;
}
