#include<iostream>
#include<string>
using namespace std;

class Book {
    private:     // private, public, protected are the access modifiers
    string name; //data members
    int price;
    int pages;

    public:
    void setName(string name){  //member functions
        this->name = name;
    }
    void setPrice(int p){
        price = p;
    }
    void setPages(int x){
        pages = x;
    }

    void getName(){
        cout<<name<<endl;
    }
    void getPrice(){
        cout<<price<<endl;
    }
    void getPages(){
        cout<<pages<<endl;
    }

    int countBooks(int p){
        if(price<p) return 1;
        else return 0;
    }

    bool isBookPresent(string s){
        if(s==name) return true;
        else return false;
    }
};

int main(){
    Book alladin;
    alladin.setName("alladin");
    alladin.setPages(44);
    alladin.setPrice(80);

    alladin.getName();
    alladin.getPages();
    alladin.getPrice();
    cout<<alladin.countBooks(55)<<endl;
    cout<<alladin.isBookPresent("alladin");
}