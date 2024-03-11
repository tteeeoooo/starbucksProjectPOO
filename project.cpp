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
        price = priceTag;}
//    drink(string drinkName) {
//        drinkChoice = drinkName;
//        price = 0;
//    }
};

vector<float> prices = {5.99, 3.99, 6.59, 3.99, 7.99, 6.49, 4.99};
vector<string> options = {"1: Iced Latte", "2: Cold Brew", "3: Matcha Latte", "4: Iced Black Tea", "5: Caramel Frappucino", "6: Caramel Ribbon Crunch Frappucino", "7: Pink Drink Refresher"};
class myCart : drink{
private:
    vector<string> myDrinks;            //vector de bauturi din cos => neaparat sa invat cum functioneaza vectorii in C++!!!!
    int amount;                         //nr de bauturi din cos
    float price;                        //suma care urmeaza sa fie platita

public:
    myCart(){              //constructor de initializare
        myDrinks = {};
        amount = 0;
        price= 0;
    }
    myCart(int index) {

    }
    //nu voi folosi constructori parametrizati datorita logicii aplicatiei: cosul este, la intrarea in aplicatie, gol,
    //iar pe parcursul input-urilor acesta se va umple

    void productAdd(string drink){       //pentru cand adaugam un produs in cos, sa actualizam nr. de produse
        amount ++;
        myDrinks.push_back(drink);
    };
    void productDelete(int index){    //pentru cand stergem un produs din cos, sa actualizam nr. de produse
        amount --;
        myDrinks.erase(myDrinks.begin() + index);
    }

    void priceAdd(float drinkPrice){
        price += drinkPrice;
    }
    void priceDelete(float drinkPrice){
        price -= drinkPrice;
    }

    void cartPrice(float priceToAdd) {      //pentru cand adaugam un produs in cos, sa ii actaulizam pretul
        price = price + priceToAdd;
    }

};

class myAccount: myCart{
private:
    string userName;                //nume de utlizator
    string password;                //parola
    vector<string> userCart;        //cosul de cumparaturi
public:
    myAccount(string name = "", string Password = "") {
        userName = name;
        password = Password;
    }
    string getUsername() const {
        return userName;
    }
//    void getInfo() {
//        std::cout<<"Your cart:"<<endl;
//        std::cout<<userCart;}
};

void operator << (ostream& COUT, myAccount& acc) {
    COUT<< acc.getUsername();
}

string Name, Password;
short int input;
int main(){
    std::cout<<"Chamberlain Coffee - Easy Mobile & Online Ordering & Delivery"<<endl;
    std::cout<<"Note(1): You can only add one product of each to your cart!"<<endl;
    std::cout<<"Note(2): You can not add more than more products in your cart for delivery reasons!"<<endl<<endl;

    std::cout<<"Connect to your account: "<<endl;
    std::cout<<"Username: ";
    std::cin>>Name;
    std::cout<<"Password: ";
    std::cin>>Password;
    std::cout<<endl;
    myAccount user = myAccount(Name, Password);
    //pana aici utilizatorul a introdus datele personale -> de cautat cum fac ca atunci cand utilizatorul scrie
    // de la tastatura sa apara * in loc de caracter??

    std::cout<<"1: Menu"<<endl;
    std::cout<<"2: My cart"<<endl;
    std::cout<<"0: Exit"<<endl<<endl;
    std::cout<<"Press 1 to see the menu / start adding products to your cart"<<endl;
    std::cout<<"Press 2 to see your cart status"<<endl;
    std::cout<<"Press 0 to cancel"<<endl;
    std::cin>>input;
    if (input == 1) {
        cout<<endl<<"Here are your options:"<<endl;
        for (int x = 0; x < 9; x ++) {
            cout<<options[x]<<" "<<prices[x]<<"$"<<endl;
        }
        while (input != 0) {
            std::cin>>input;

        }
    }
    if (input == 2) {
        while (input != 0) {

        }
    }
    if (input == 0){
        return 0;
    }

}

/*idee proiect:
 * un cos de cumparaturi pentru o aplicatie -> starbucks
 * utilizatorul poate face urmatoarele lucruri: poate pune produse in cos, le poate sterge si poate finaliza plata
 * se pun 2 conditii: poate achizitiona maxim 4 produse + poate adauga doar unul din fiecare
 * pe cel mai ieftin nu il mai plateste -> urmeaza sa fie facuta partea asta
 */
